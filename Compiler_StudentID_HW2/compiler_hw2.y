/*	Definition section */
%{
#include <stdio.h>
#include <string.h>

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
	: type ID LB {redeclare_test($2,"function");attribute_count++; insert_symbol($2,"function",$1,scopenumber,attribute_count);}
;

scope
    : scopestart block_item_list scopeend 
;

scopestart
    : LCB { scopenumber++;}

scopeend
    : RCB {dump_number=scopenumber;scopenumber--;}
;

parameter_part
    : parameter_part COMMA type ID {insert_symbol($4,"parameter",$3,scopenumber+1,0);insert_attribute($3,attribute_count);/*check_symbol();*/}
    | type ID {insert_symbol($2,"parameter",$1,scopenumber+1,0);insert_attribute($1,attribute_count);/*check_symbol();*/}
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
    : type init_declarator SEMICOLON {redeclare_test($2,"variable");insert_symbol($2,"variable",$1,scopenumber,0);/*check_symbol();*/}
;

init_declarator
	: ID ASGN initializer {$$=$1;}
	| ID {$$=$1;}
;


initializer
    : assignment_expression
;

assignment_expression
	: logical_or_expression
	| unary_expression assignment_operator assignment_expression
;

assignment_operator
    : ASGN
    | ADDASGN
    | SUBASGN
    | MULASGN
    | DIVASGN
    | MODASGN
;

unary_expression
	: postfix_expression
	| INC unary_expression
	| DEC unary_expression
	| unary_operator cast_expression
;

postfix_expression
	: primary_expression 
	| postfix_expression LB RB {undeclare_test($1,"function");}
	| postfix_expression LB argument_expression_list RB {undeclare_test($1,"function");}
	| postfix_expression INC
	| postfix_expression DEC
;

primary_expression
	: ID {undeclare_test($1,"variable");}
	| constant	
	| LB expression RB 
;

argument_expression_list
	: assignment_expression
	| argument_expression_list COMMA assignment_expression
;

constant
    : I_CONST
    | F_CONST
    | STRING_CONST
    | boolean
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
	| LB specifier_qualifier_list RB cast_expression
;

specifier_qualifier_list
	: type specifier_qualifier_list
	| type
;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR logical_and_expression
;

logical_and_expression
	: equality_expression
	| logical_and_expression AND equality_expression
;

equality_expression
	: relational_expression
	| equality_expression EQ relational_expression
	| equality_expression NE relational_expression
;

relational_expression
	: additive_expression
	| relational_expression MT additive_expression
	| relational_expression LT additive_expression
	| relational_expression MTE additive_expression
	| relational_expression LTE additive_expression
;

additive_expression
	: multiplicative_expression
	| additive_expression ADD multiplicative_expression
	| additive_expression SUB multiplicative_expression
;

multiplicative_expression
	: cast_expression
	| multiplicative_expression MUL cast_expression
	| multiplicative_expression DIV cast_expression
	| multiplicative_expression MOD cast_expression
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
	: IF LB expression RB statement ELSE statement
	| IF LB expression RB statement
;

iteration_statement
	: WHILE LB expression RB statement
;

jump_statement
	: RETURN SEMICOLON
	| RETURN expression SEMICOLON
;

expression
	: assignment_expression
	| expression COMMA assignment_expression
;

print_statement
    : PRINT LB expression RB SEMICOLON
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
			//printf("%s %s redeclare!!!\n",name,type);
			strcpy(semantic_name,name);
			strcpy(semantic_type,type);
			strcpy(semantic_message,"Redeclared");
			semantic_happen=1;
		}
	}
}