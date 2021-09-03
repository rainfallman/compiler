/*	Definition section */
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int scopenumber;
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[2000];  // Get current code line from lex
int dump_number;
int attribute_count;
int syntax_flag;
char outbuf[50];
/* Symbol table function - you can add new function if needed. */
int lookup_symbol(char* name,char* type);
void create_symbol();
void insert_symbol(char* name,char* entry_type,char* data_type,int scope_level,int attribute_number);
void check_symbol();
void dump_symbol(int nownumber);
void test();
void create_attribute();
void insert_attribute(char* type,int count);
char* show_attribute(int number);

/* semantic test */
int semantic_happen;
char semantic_name[50];
char semantic_type[50];
char semantic_message[50];
void undeclare_test(char* name,char* type);
void redeclare_test(char* name,char* type);
void semanticerror();

/* .j file generate */

FILE *file;

void gencode_function(char* java_code);
void generate_variable_code(char* type,char* name);
int declarate_has_init;
int constantflag;
int intconstant;
float floatconstant;
void generate_local(char* type,char* name);
void generate_print_function(char* input);
char* remember_function_name;
char* remember_function_type;
char* funcparameterout(char* name);
char parameterreturn[50];
typedef struct heap_s{
	int i;
	float f;
	int flag;
}Heap;
Heap my_heap[10];
void heapipush(int input);
int heapipop();
void heapfpush(float input);
float heapfpop();


typedef struct symbol{
	int index;
	char* name;
	char* entry_type;
	char* data_type;
	int scope_level;
	int attribute_number;
	struct symbol * next;
	struct symbol* prev;
} Symbol_Table;

Symbol_Table* my_symbol_head;

typedef struct attribute{
	int number;
	char* type;
	struct attribute* next;
	struct attribute*prev;
} Attribute_Table;

Attribute_Table* my_attribute_head;




%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string;
}

/* Token without return */
/* Arithmetic */
%token ADD SUB MUL DIV MOD INC DEC
/* Relational */
%token EQ NE MT LT MTE LTE
/* Assignment */
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
/* Logical */
%token AND OR NOT
/* Parentheses and Comma*/
%token LB RB LCB RCB LSB RSB COMMA
%token PRINT 
%token IF ELSE FOR WHILE
%token SEMICOLON
%token VOID INT FLOAT STRING BOOL
%token TRUE FALSE
%token RETURN

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STRING_CONST
%token <string> ID

/* Nonterminal with return, which need to sepcify type */
%type <string> type
%type <string> init_declarator
%type <string> postfix_expression
%type <string> primary_expression
%type <string> unary_expression
%type <string> logical_or_expression logical_and_expression equality_expression assignment_expression
%type <string> relational_expression additive_expression multiplicative_expression cast_expression
%type <string> constant 
%type <i_val> whileop
/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program ex_declaration 
    | ex_declaration
;

ex_declaration
    : function_de 
    | declaration 
;

function_de
    : function_forward parameter_part RB scope 
    | function_forward parameter_part RB SEMICOLON
;

function_forward
	: type ID LB {
	redeclare_test($2,"function");
	attribute_count++; 
	insert_symbol($2,"function",$1,scopenumber,attribute_count);
	remember_function_name=$2;
	if($1=="int")
		remember_function_type="I";
	else if($1=="float")
		remember_function_type="F";
	else if($1=="string")
		remember_function_type="Ljava/lang/String;";
	else if($1=="void")
		remember_function_type="V";
	}
;

scope
    : scopestart block_item_list scopeend 
;

scopestart
    : LCB { 
		scopenumber++;
		char tmp[50]="";
		gencode_function(".method public static");
		if(strcmp(remember_function_name,"main"))
			sprintf(tmp," %s(%s)%s\n",remember_function_name,funcparameterout(remember_function_name),remember_function_type);
		else
			sprintf(tmp," %s(%s)%s\n",remember_function_name,"[Ljava/lang/String;",remember_function_type);
		gencode_function(tmp);
		gencode_function(".limit stack 50\n. limit locals 50\n");
		}

scopeend
    : RCB {dump_number=scopenumber;scopenumber--;gencode_function(".end method\n");}
;

parameter_part
    : parameter_part COMMA type ID {
		insert_symbol($4,"parameter",$3,scopenumber+1,0);
		insert_attribute($3,attribute_count);
		/*check_symbol();*/
		}
    | type ID {
		insert_symbol($2,"parameter",$1,scopenumber+1,0);
		insert_attribute($1,attribute_count);
		/*check_symbol();*/


		}
    |
;

block_item_list
	: block_item
	| block_item_list block_item
;

block_item
	: declaration 
	| statement
;

/* declaration  start */

declaration
    : type init_declarator SEMICOLON {
		redeclare_test($2,"variable");
		insert_symbol($2,"variable",$1,scopenumber,0);
		if(scopenumber==0)
			generate_variable_code($1,$2);
		else if(scopenumber>0)
			generate_local($1,$2);
		//printf("init\n");
		}
;

init_declarator
	: ID ASGN initializer {$$=$1;declarate_has_init=1;}
	| ID {$$=$1;}
;


initializer
    : assignment_expression 
;

assignment_expression
	: logical_or_expression {$$=$1;}
	| unary_expression assignment_operator assignment_expression {
		printf("%s=%s",$1,$3);
		Symbol_Table * seeall;
		char tmp[20];
		for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
		{
			if(strcmp(seeall->name,$1)==0)
				break;
		}
		if(!strcmp(seeall->data_type,"int"))
		{
			sprintf(tmp,"istore %d\n",seeall->index);
		}
		if(!strcmp(seeall->data_type,"float"))
		{
			sprintf(tmp,"fstore %d\n",seeall->index);
		}
		if(!strcmp(seeall->data_type,"string"))
		{
			sprintf(tmp,"astore %d\n",seeall->index);
		}
		gencode_function(tmp);
	}
;

assignment_operator
    : ASGN {printf("now is =\n");}
    | ADDASGN {printf("now is +=\n");}
    | SUBASGN {printf("now is -=\n");}
    | MULASGN {printf("now is *=\n");}
    | DIVASGN {printf("now is /=\n");}
    | MODASGN {printf("now is %%=\n");}
;

unary_expression
	: postfix_expression {$$=$1;}
	| INC unary_expression {$$=$2;}
	| DEC unary_expression {$$=$2;}
	| unary_operator cast_expression {$$="";}
;

postfix_expression
	: primary_expression {$$=$1;}
	| postfix_expression LB RB {
		undeclare_test($1,"function");
		printf("%sNO input function\n",$1);
		}
	| postfix_expression LB argument_expression_list RB {
		undeclare_test($1,"function");
		printf("%shas input function\n",$1);

		}
	| postfix_expression INC
	| postfix_expression DEC
;

primary_expression
	: ID {undeclare_test($1,"variable");/*printf("%s v\n",$1);*/}
	| constant	{$$=$1;/*printf("constant\n");*/}
	| LB expression RB {$$="";}
;

argument_expression_list
	: assignment_expression
	| argument_expression_list COMMA assignment_expression
;

constant
    : I_CONST {
		$$="I_CONST";
		printf("I:%d\n",$1);
		intconstant=$1;
		constantflag=1;
		heapipush($1);
		if(scopenumber>0)
		{
			printf("ldc %d\n",$1);
			//gencode_function("ldc ");
		}
		}
    | F_CONST {
		$$="F_CONST";
		printf("F:%f\n",(float)$1);
		floatconstant=$1;
		constantflag=2;
		heapfpush($1);
		if(scopenumber>0)
		{
			printf("ldc %f\n",$1);
			//gencode_function("ldc ");
		}
		}
    | STRING_CONST {
		$$="STRING_CONST";
		if(scopenumber>0)
		{
			printf("ldc %s\n",$1);
			//gencode_function("ldc ");
		}
	}
    | boolean {$$="boolean";}
;

boolean
    : TRUE
    | FALSE
;

unary_operator
    : ADD
    | SUB
    | NOT
;

cast_expression
	: unary_expression
	| LB specifier_qualifier_list RB cast_expression {$$="";}
;

specifier_qualifier_list
	: type specifier_qualifier_list
	| type
;

logical_or_expression
	: logical_and_expression {$$=$1;}
	| logical_or_expression OR logical_and_expression {$$="";}
;

logical_and_expression
	: equality_expression {$$=$1;}
	| logical_and_expression AND equality_expression
;

equality_expression
	: relational_expression {$$=$1;}
	| equality_expression EQ relational_expression
	| equality_expression NE relational_expression
;

relational_expression
	: additive_expression {$$=$1;}
	| relational_expression MT additive_expression 
	| relational_expression LT additive_expression 
	| relational_expression MTE additive_expression 
	| relational_expression LTE additive_expression 
;

additive_expression
	: multiplicative_expression {$$=$1;}
	| additive_expression ADD multiplicative_expression {
		char tmp[20];
		printf("now is %s+%s\n",$1,$3);
		if(!strcmp($1,"I_CONST"))
		{
			sprintf(tmp,"ldc %d\n",yylval.i_val);
			gencode_function(tmp);
		}
		else if(!strcmp($1,"F_CONST"))
		{
			sprintf(tmp,"ldc %f\n",yylval.f_val);
			gencode_function(tmp);
		}
		else
		{
			Symbol_Table * seeall;
			char tmp[20];
			for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
			{
				if(strcmp(seeall->name,$1)==0)
					break;
			}
			if(!strcmp(seeall->data_type,"int"))
			{
				sprintf(tmp,"iload %d\n",seeall->index);
			}
			if(!strcmp(seeall->data_type,"float"))
			{
				sprintf(tmp,"fload %d\n",seeall->index);
			}
			gencode_function(tmp);

		}
		if(!strcmp($3,"I_CONST"))
		{
			sprintf(tmp,"ldc %d\n",yylval.i_val);
			gencode_function(tmp);
		}
		else if(!strcmp($3,"F_CONST"))
		{
			sprintf(tmp,"ldc %f\n",yylval.f_val);
			gencode_function(tmp);
		}
		else
		{
			Symbol_Table * seeall;
			char tmp[20];
			for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
			{
				if(strcmp(seeall->name,$3)==0)
					break;
			}
			if(!strcmp(seeall->data_type,"int"))
			{
				sprintf(tmp,"iload %d\n",seeall->index);
			}
			if(!strcmp(seeall->data_type,"float"))
			{
				sprintf(tmp,"fload %d\n",seeall->index);
			}
			gencode_function(tmp);

		}
		gencode_function("iadd\n");

	}
	| additive_expression SUB multiplicative_expression {printf("now is %s-%s\n",$1,$3);}
;

multiplicative_expression
	: cast_expression {$$=$1;}
	| multiplicative_expression MUL cast_expression {printf("now is %s*%s\n",$1,$3);}
	| multiplicative_expression DIV cast_expression {printf("now is %s/%s\n",$1,$3);}
	| multiplicative_expression MOD cast_expression {printf("now is %s%% %s\n",$1,$3);}
;

/* statement start */

statement
	: compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
    | print_statement
;

compound_statement
    : LCB RCB   
	| LCB  block_item_list RCB
;

expression_statement
	: SEMICOLON
	| expression SEMICOLON
;

selection_statement
	: IF LB expression RB statement ELSE statement {printf("ifandelse\n");}
	| IF LB expression RB statement {printf("if\n");}
;

iteration_statement
	: WHILE LB whileexpression RB statement {
		printf("while\n");
		gencode_function("goto LABEL_BEGIN\nLABEL_FALSE:\ngoto EXIT_0\nEXIT_0:\n");
		}
;

whileexpression
	: primary_expression whileop primary_expression {
		printf("whileexpression\n");
		gencode_function("LABEL_BEGIN:\n");
		char tmp[50];
		int choise=0;
		if(!strcmp($1,"I_CONST"))
		{
			sprintf(tmp,"ldc %d\n",heapipop());
			gencode_function(tmp);
			choise=1;
		}
		else if(!strcmp($1,"F_CONST"))
		{
			sprintf(tmp,"ldc %f\n",heapfpop());
			gencode_function(tmp);
		}
		else
		{
			Symbol_Table * seeall;
			for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
			{
				if(strcmp(seeall->name,$1)==0)
					break;
			}
			if(seeall->data_type=="int")
				choise=1;
			else
				choise=2;
			sprintf(tmp,"iload %d\n",seeall->index);
			gencode_function(tmp);
		}
		if(!strcmp($3,"I_CONST"))
		{
			sprintf(tmp,"ldc %d\n",heapipop());
			gencode_function(tmp);
			choise=1;
		}
		else if(!strcmp($3,"F_CONST"))
		{
			sprintf(tmp,"ldc %f\n",heapfpop());
			gencode_function(tmp);
		}
		else
		{
			Symbol_Table * seeall;
			for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
			{
				if(strcmp(seeall->name,$1)==0)
					break;
			}
			if(seeall->data_type=="int")
				choise=1;
			else
				choise=2;
			sprintf(tmp,"iload %d\n",seeall->index);
			gencode_function(tmp);
		}
		if(choise==1)
			gencode_function("isub\n");
		else
			gencode_function("fsub\n");
		switch ($2)
		{
			case 1:
				gencode_function("ifgt LABEL_TRUE\n");
				break;
			case 2:
				gencode_function("iflt LABEL_TRUE\n");
				break;
			case 3:
				gencode_function("ifge LABEL_TRUE\n");
				break;
			case 4:
				gencode_function("ifle LABEL_TRUE\n");
				break;
			case 5:
				gencode_function("ifne LABEL_TRUE\n");
				break;
			default:
			break;
		}
		gencode_function("goto LABEL_FALSE\n");
		printf("end\n");
	}
;
whileop
	: MT {printf("now is >\n");$$=1;}
	| LT {printf("now is <\n");$$=2;}
	| MTE {printf("now is >=\n");$$=3;}
	| LTE {printf("now is <=\n");$$=4;}
	| EQ {$$=5;}
;

jump_statement
	: RETURN SEMICOLON {gencode_function("return\n");}
	| RETURN expression SEMICOLON {
		if(remember_function_type=="I")
			gencode_function("ireturn\n");
		if(remember_function_type=="F")
			gencode_function("freturn\n");}
;

expression
	: assignment_expression
	| expression COMMA assignment_expression
;

print_statement
    : PRINT LB primary_expression RB SEMICOLON {printf("%s\n",$3);generate_print_function($3);}
;



/* actions can be taken when meet the token or rule */
type
    : INT { $$ = "int"; }
    | FLOAT { $$ = "float"; }
    | BOOL  { $$ = "bool"; }
    | STRING { $$ = "string"; }
    | VOID { $$ = "void"; }
;

%%



/* C code section */
int main(int argc, char** argv)
{
	memset(my_heap,0,sizeof(my_heap));
	file = fopen("compiler_hw3.j","w");

    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");
    scopenumber=0;
	attribute_count=0;
    yylineno = 0;
	semantic_happen=0;
	syntax_flag=0;
	create_symbol();
	create_attribute();
	
    yyparse();
	if(!syntax_flag)
		dump_symbol(scopenumber);
		printf("\nTotal lines: %d \n",yylineno);
	//test();
	fclose(file);
    return 0;
}

void semanticerror()
{
	printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s %s %s",semantic_message,semantic_type,semantic_name);
    printf("\n|-----------------------------------------------|\n\n");
}

void yyerror(char *s)
{
	if(semantic_happen==1)
	{
		semanticerror();
	}
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
	syntax_flag=1;
}

void create_symbol() {
	my_symbol_head=(Symbol_Table*)malloc(sizeof(Symbol_Table));
	my_symbol_head->next=my_symbol_head;
	my_symbol_head->prev=my_symbol_head;
	my_symbol_head->index=-1;
	my_symbol_head->name=NULL;
	my_symbol_head->entry_type=NULL;
	my_symbol_head->data_type=NULL;
	my_symbol_head->scope_level=-1;
	my_symbol_head->attribute_number=-1;
}
void insert_symbol(char* name,char* entry_type,char* data_type,int scope_level,int attribute_number) {
	int index=0;
	Symbol_Table * seeall;
	for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
	{
		if(seeall->scope_level==scope_level)
		{
			index++;
		}
	}
	Symbol_Table* tmp=(Symbol_Table*)malloc(sizeof(Symbol_Table));
	tmp->index=index;
	tmp->name=name;
	tmp->entry_type=entry_type;
	tmp->data_type=data_type;
	tmp->scope_level=scope_level;
	tmp->attribute_number=attribute_number;


	my_symbol_head->prev->next=tmp;
	tmp->next=my_symbol_head;
	tmp->prev=my_symbol_head->prev;
	my_symbol_head->prev=tmp;
}
void check_symbol() 
{
	Symbol_Table * seeall;
	for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
	{
		printf("\n%-10d%-10s%-12s%-10s%-10d%-10d\n",seeall->index, seeall->name, seeall->entry_type, seeall->data_type, seeall->scope_level, seeall->attribute_number);
	}
	//printf("\n|-----------------------------------------------|\n");
}
int lookup_symbol(char* name,char* type) 
{
	
}
void dump_symbol(int nownumber) 
{
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n","Index", "Name", "Kind", "Type", "Scope", "Attribute");
	Symbol_Table * out;
	for(out=my_symbol_head->next;out!=my_symbol_head;out=out->next)
	{
		if(out->scope_level==nownumber)
		{
			printf("%-10d%-10s%-12s%-10s%-10d%-10s\n",out->index,out->name,out->entry_type,out->data_type,out->scope_level,show_attribute(out->attribute_number));
			out->prev->next=out->next;
			out->next->prev=out->prev;
		}
	}
	printf("\n");
	
}

void test()
{
	insert_symbol("a","v","int",scopenumber,0);
	insert_symbol("s","v","int",scopenumber,0);
	scopenumber++;
	insert_symbol("d","v","int",scopenumber,0);
	insert_symbol("b","v","int",scopenumber,0);
	insert_symbol("x","v","int",scopenumber,0);
	check_symbol();
	dump_symbol(scopenumber);
	scopenumber--;
	check_symbol();
	scopenumber++;
	insert_symbol("cf","v","int",scopenumber,0);
	insert_symbol("q","v","int",scopenumber,0);
	insert_symbol("y","v","int",scopenumber,0);
	check_symbol();
}


void create_attribute()
{
	my_attribute_head=(Attribute_Table*)malloc(sizeof(Attribute_Table));
	my_attribute_head->number=-1;
	my_attribute_head->type=NULL;
	my_attribute_head->next=my_attribute_head;
	my_attribute_head->prev=my_attribute_head;
}
void insert_attribute(char* type,int count)
{
	Attribute_Table* tmp=(Attribute_Table*)malloc(sizeof(Attribute_Table));
	tmp->type=type;
	tmp->number=count;

	my_attribute_head->prev->next=tmp;
	tmp->next=my_attribute_head;
	tmp->prev=my_attribute_head->prev;
	my_attribute_head->prev=tmp;
}
char* show_attribute(int number)
{
	
	outbuf[0]='\0' ;
	Attribute_Table * seeall;
	if(number>0)
	{
		for(seeall=my_attribute_head->next;seeall!=my_attribute_head;seeall=seeall->next)
		{
			if(seeall->number==number)
			{
				if(outbuf[0]=='\0')
				{
					strncat(outbuf,seeall->type,strlen(seeall->type));
				}
				else
				{
					strncat(outbuf,",",1);
					strncat(outbuf,seeall->type,strlen(seeall->type));
				}
			}
		}
	}
	return outbuf;
}

void undeclare_test(char* name,char* type)
{
	int check=0;
	Symbol_Table * seeall;
	for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
	{
		if(strcmp(seeall->name,name)==0)
		{
			//printf("%sexist!!!\n",type);
			check=1;
			break;
		}
	}
	if(check==0)
	{
		//printf("%sno exist!!\n",type);
		strcpy(semantic_name,name);
		strcpy(semantic_type,type);
		strcpy(semantic_message,"Undeclared");
		semantic_happen=1;

	}
}
void redeclare_test(char* name,char* type)
{
	Symbol_Table * seeall;
	for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
	{
		if(strcmp(seeall->name,name)==0)
		{
			if(seeall->scope_level>0)
			//printf("%s %s redeclare!!!\n",name,type);
			strcpy(semantic_name,name);
			strcpy(semantic_type,type);
			strcpy(semantic_message,"Redeclared");
			semantic_happen=1;
		}
	}
}


/* homework 3 added  */

void gencode_function(char* java_code) {
    if(!syntax_flag)
		fprintf(file, "%s", java_code);  
}
void generate_variable_code(char* type,char* name)
{
	char tmp[256];
	//printf("%s %s",type,name);
	
	if(!strcmp(type, "int"))
	{
		if(declarate_has_init)
		{
			if(constantflag==1)
				sprintf(tmp,".field public static %s %s = %d\n", name, "I", intconstant);
			if(constantflag==2)
				sprintf(tmp,".field public static %s %s = %d\n", name, "I", (int)floatconstant);
		}
		else
			sprintf(tmp,".field public static %s %s = %d\n", name, "I",0);
	}
	else if(!strcmp(type, "float"))
	{
		if(declarate_has_init)
		{
			if(constantflag==1)
			sprintf(tmp,".field public static %s %s = %f\n", name, "F", (float)intconstant);
			if(constantflag==2)
			sprintf(tmp,".field public static %s %s = %f\n", name, "F", floatconstant);

		}
		else
			sprintf(tmp,".field public static %s %s = %f\n", name, "F",0);
	}
	else if(!strcmp(type, "string"))
	{
		sprintf(tmp, ".field public static %s %s = \"%s\"\n", name, "Ljava/lang/String;", yylval.string);
		
	}
	else if(!strcmp(type, "bool"))
	{
		if(declarate_has_init)
			sprintf(tmp,".field public static %s %s = %d\n", name, "B", yylval.i_val);
		else
			sprintf(tmp,".field public static %s %s = %d\n", name, "B", 0);
	}
	
	
	if(strcmp(tmp, ""))
            gencode_function(tmp);
	declarate_has_init=0;
	constantflag=0;
	heapipop();
}

void generate_local(char*type,char* name){
	char tmp[256];
	Symbol_Table * seeall;
	for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
	{
		if(strcmp(seeall->name,name)==0)
			break;
	}
	if(!strcmp(type, "int"))
	{
		if(declarate_has_init)
		{
			if(constantflag==1)
			{
				gencode_function("ldc ");
				sprintf(tmp,"%d\nistore %d\n",intconstant,seeall->index);
			}
			if(constantflag==2)
			{
				gencode_function("ldc ");
				sprintf(tmp,"%d\nistore %d\n",(int)floatconstant,seeall->index);
			}
		}
		else 
		{
			gencode_function("ldc ");
			sprintf(tmp,"%d\nistore %d\n",0,seeall->index);
		}
	}
	if(!strcmp(type, "float"))
	{
		if(declarate_has_init)
		{
			if(constantflag==1)
			{
				gencode_function("ldc ");
				sprintf(tmp,"%f\nfstore %d\n",(float)intconstant,seeall->index);
			}
			if(constantflag==2)
			{
				gencode_function("ldc ");
				sprintf(tmp,"%f\nfstore %d\n",floatconstant,seeall->index);
			}
		}
		else 
		{
			gencode_function("ldc ");
			sprintf(tmp,"%d\nfstore %d\n",0,seeall->index);
		}
	}
	if(!strcmp(type, "string"))
	{
		if(declarate_has_init)
		{
			gencode_function("ldc ");
			sprintf(tmp,"%s\nastore %d\n",yylval.string,seeall->index);
		}
	}
	if(strcmp(tmp, ""))
        gencode_function(tmp);
	declarate_has_init=0;
	constantflag=0;
	heapipop();
}

void generate_print_function(char* input){
	
	char tmp[256];
	if(!strcmp(input, "I_CONST"))
	{	
		sprintf(tmp,"ldc %d\n",(int)yylval.f_val);
		gencode_function(tmp);
		gencode_function("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
		
	}
	else if(!strcmp(input, "F_CONST"))
	{	
		sprintf(tmp,"ldc %f\n",yylval.f_val);
		gencode_function(tmp);
		gencode_function("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(F)V\n");
		
	}
	else if(!strcmp(input, "STRING_CONST"))
	{	
		sprintf(tmp,"ldc %s\n",yylval.string);
		gencode_function(tmp);
		gencode_function("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
		
	}
	else 
	{
		Symbol_Table * seeall;
		for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
		{
			if(strcmp(seeall->name,input)==0)
				break;
		}
		if(!strcmp(seeall->data_type,"int"))
		{
			sprintf(tmp,"iload %d\n",seeall->index);
			gencode_function(tmp);
			gencode_function("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
		}
		if(!strcmp(seeall->data_type,"float"))
		{
			sprintf(tmp,"fload %d\n",seeall->index);
			gencode_function(tmp);
			gencode_function("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
		}
		if(!strcmp(seeall->data_type,"string"))
		{
			sprintf(tmp,"aload %d\n",seeall->index);
			gencode_function(tmp);
			gencode_function("getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(I)V\n");
		}
	}
}

char* funcparameterout(char* name)
{
	Symbol_Table * seeall;
		for(seeall=my_symbol_head->next;seeall!=my_symbol_head;seeall=seeall->next)
		{
			if(strcmp(seeall->name,name)==0)
				break;
		}
	parameterreturn[0]='\0';
	Attribute_Table* search;
	for (search=my_attribute_head->next;search!=my_attribute_head;search=search->next)
	{
		if(search->number==seeall->attribute_number)
		{
			if(search->type=="int")
			{
				strncat(parameterreturn,"I",1);
			}
			else if(search->type=="float")
			{
				strncat(parameterreturn,"F",1);
			}
			else if(search->type=="string")
			{
				strcat(parameterreturn,"Ljava/lang/String;");
			}
		}

	}
	//printf("%s\n",parameterreturn);
	return parameterreturn;
}


void heapipush(int input){
	int i=0;
	for(i;i<10;i++)
	{
		if(my_heap[i].flag==0)
		{
			my_heap[i].i=input;
			my_heap[i].flag=1;
			break;
		}
	}
}
void heapfpush(float input){
	int i=0;
	for(i;i<10;i++)
	{
		if(my_heap[i].flag==0)
		{
			my_heap[i].f=input;
			my_heap[i].flag=2;
			break;
		}
	}
}
int heapipop(){
	int tmp=my_heap[0].i;
	int i;
	for(i=1;i<10;i++)
	{
		my_heap[i-1].i=my_heap[i].i;
		my_heap[i-1].f=my_heap[i].f;
		my_heap[i-1].flag=my_heap[i].flag;
	}
	return tmp;
}
float heapfpop(){
	float tmp=my_heap[0].f;
	int i;
	for(i=1;i<10;i++)
	{
		my_heap[i-1].i=my_heap[i].i;
		my_heap[i-1].f=my_heap[i].f;
		my_heap[i-1].flag=my_heap[i].flag;
	}
	return tmp;
}
