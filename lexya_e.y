%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "node.h"

Node *opr(int name,int num,...);
Node *set_index(int value);
Node *set_content(float value);

void NodeFree(Node *p);
int NodeExecute(Node *p);

typedef union {
    float val;
    int index;
    Node *node;
}yystype;

#define YYSTYPE yystype

void debug_vsp(YYSTYPE,char *,YYSTYPE *,char *);

void print_stmt();

void add_var(char *);

int G_iVarMaxIndex = 0;
int G_iVarCurIndex = -1;
struct VarIndex G_Var[MAX_VARS];

void yyerror(char *s);
%}


%union{
    float val;
    int index;
    Node *node;
};

%token <val> NUMBER
%token <index> VARIABLE
%token INT FLOAT
%token PRINT
%token FOR WHILE BREAK
%token FUNCTION
%nonassoc IF
%nonassoc ELSE
%left AND OR
%left GE LE EQ NE '>' '<'
%left '+''-'
%left '*''/'
%left ADD_T ADD_TT MUS_T MUS_TT
%left '[' ']'
%nonassoc UMINUS
%type <node> stmt stmt_list var_decl expr_set expr_setself expr_comp expr        /* func_decl_args func_decl */


%%
program:

function{ exit(0); }

;

function:

function stmt{ NodeExecute($2);NodeFree($2); }

|

;


stmt:

BREAK ';' { $$ = opr(BREAK,0); }

| ';'{ $$=opr(';',2,NULL,NULL); }

| expr_set';'{ $$=$1; }

| PRINT expr';'{ $$=opr(PRINT,1,$2); }

| PRINT expr_set ';'    { $$ = opr(PRINT, 1, $2); }

| FOR '(' expr_set ';' expr_comp ';' expr_set ')' stmt { $$ = opr(FOR, 4, $3, $5, $7, $9); }

| WHILE '(' expr_comp ')' stmt       { $$ = opr(WHILE, 2, $3, $5); }

| IF'('expr_comp')'stmt %prec IF{ $$=opr(IF,2,$3,$5); }

| IF'('expr_comp')'stmt ELSE stmt %prec ELSE{ $$=opr(IF,3,$3,$5,$7); }

| '{'stmt_list'}'{ $$=$2; }

| var_decl';'{}

;


stmt_list:

stmt{ $$=$1; }

| stmt_list stmt{ $$=opr(';',2,$1,$2); }

;



var_decl:

INT VARIABLE{ $$ = set_index($2);}

| FLOAT VARIABLE {$$ = set_index($2);}

| INT VARIABLE '=' expr {$$ = opr('=', 2, set_index($2), $4);}

| FLOAT VARIABLE '=' expr { $$ = opr('=', 2, set_index($2), $4); }

| INT VARIABLE '[' expr ']' { $$ = set_index($2); }

;


expr_set:

VARIABLE '=' expr { $$ = opr('=', 2, set_index($1), $3); }

| VARIABLE '=' expr_setself { $$ = opr('=', 2, set_index($1), $3); }

| expr_setself

| VARIABLE '[' expr ']' '=' expr { $$ = opr('=', 3, set_index($1), $3, $6); }

;


expr_setself:

  ADD_T VARIABLE  { $$ = opr(ADD_T, 1, set_index($2)); }

  | MUS_T VARIABLE  { $$ = opr(MUS_T, 1, set_index($2)); }

  | VARIABLE ADD_T  { $$ = opr(ADD_TT, 1, set_index($1)); }

  | VARIABLE MUS_T  { $$ = opr(MUS_TT, 1, set_index($1)); }

  | '(' expr_setself ')' { $$ = $2; }

  ;


expr_comp:

  expr '<' expr   { $$ = opr('<', 2, $1, $3); }

  | expr '>' expr   { $$ = opr('>', 2, $1, $3); }

  | expr GE expr    { $$ = opr(GE, 2, $1, $3); }

  | expr LE expr    { $$ = opr(LE, 2, $1, $3); }

  | expr NE expr    { $$ = opr(NE, 2, $1, $3); }

  | expr EQ expr    { $$ = opr(EQ, 2, $1, $3); }

  | expr_comp AND expr_comp { $$ = opr(AND, 2, $1, $3); }

  | expr_comp OR expr_comp  { $$ = opr(OR, 2, $1, $3); }

  | '(' expr_comp ')'       { $$ = $2; }

  ;


expr:

NUMBER            { $$ = set_content($1); }

| VARIABLE        { $$ = set_index($1); }

| '-' NUMBER %prec UMINUS { $$ = set_content(-$2); }

| expr '+' expr   { $$ = opr('+', 2, $1, $3); }

| expr '-' expr   { $$ = opr('-', 2, $1, $3); }

| expr '*' expr   { $$ = opr('*', 2, $1, $3); }

| expr '/' expr   { $$ = opr('/', 2, $1, $3); }

| '(' expr ')'    { $$ = $2; }

| VARIABLE '[' expr ']' { $$ = opr('[',2,set_index($1),$3); }

;


%%


#define SIZE_OF_NODE  ((char*)&p->content-(char*)p)

Node *set_content(float value){

    Node *p;

    size_t sizeNode;

    sizeNode = SIZE_OF_NODE + sizeof(float);

    if((p = malloc(sizeNode)) == NULL)
	yyerror("out of memory");


    p->type = TYPE_CONTENT;
    p->content = value;

    return p;

}

Node *set_index(int value){

    Node *p;
    size_t sizeNode;

    sizeNode = SIZE_OF_NODE + sizeof(int);

    if((p = malloc(sizeNode)) == NULL)
	yyerror("out of memory");


    p->type = TYPE_INDEX;
    p->index = value;

    return p;
}

Node *opr(int name,int num,...){

    va_list valist;
    Node *p;
    size_t sizeNode;
    int i;

    sizeNode = SIZE_OF_NODE + sizeof(OpNode) + (num - 1) * sizeof(Node*);

    if((p = malloc(sizeNode)) == NULL)
	yyerror("out of memory");


    
    p->type = TYPE_OP;
    p->op.name = name;
    p->op.num = num;

    va_start(valist,num);

    for(i = 0;i < num;i++)
	p->op.node[i] = va_arg(valist,Node*);

    va_end(valist);
    return p;
}

void debug_vsp(YYSTYPE yval, char * info, YYSTYPE * vsp, char * mark) {

#ifdef PARSE_DEBUG
    printf("\n -RULE  0x%x  %s \n ", yval.node, info  );

    int i;
    int ilen=strlen(mark);

    for(i=1-ilen;i<=0;i++) {
		
	switch(mark[ilen+i-1]){
	
	    case '0':
	
		printf(" [ 0x%x ",vsp[i].node);//「」
		
		switch(vsp[i].node->type) {
		
		    case TYPE_CONTENT:
		
			printf("%g ] ",vsp[i].node->content);
							      
			break;
			
		    case TYPE_INDEX:
			
			printf("%s ] ",G_Var[vsp[i].node->index].mark);
			
			break;
			
		    case TYPE_OP:

			if(vsp[i].node->op.name<USER_DEF_NUM)
			    printf("%c ] ",vsp[i].node->op.name);

			else			
			    printf("%s ] ",G_Def[vsp[i].node->op.name-USER_DEF_NUM].name);
			break;      
		}
		break;
	    case '1':
		printf(" %c ",vsp[i].index);   /* 打印运算符 */
		break;
	    case '2':
		printf(" %s ",G_Var[vsp[i].index].mark);
		break;
	    case '3':
		printf(" %g ",vsp[i].val);
		break;
	    case '4':
		printf(" %s ",G_Def[vsp[i].index].name);		
		break;  
		
	}
	
    }
    printf("\n");
    print_stmt();

#endif

}


void add_var(char *mark){

    if(G_iVarMaxIndex == 0){
	strcpy(G_Var[0].mark,mark);
	G_iVarMaxIndex++;
	G_iVarCurIndex=0;
	return;
    }

    int i; 
    for(i=0;i<=G_iVarMaxIndex-1;i++) {
	 if(strcmp(G_Var[i].mark,mark)==0) {
	     G_iVarCurIndex=i;
	     return;
	 }
     }

    strcpy(G_Var[G_iVarMaxIndex].mark,mark);
    G_iVarCurIndex=G_iVarMaxIndex;
    G_iVarMaxIndex++;
}


void print_stmt() {
     printf(" -STMT: \n");

     if(G_iBuffColCount==0)
	 printf("  %s \n",G_sBuff[G_iBuffRowCount-1]);  
     else
	 printf("  %s \n",G_sBuff[G_iBuffRowCount]);
   
     printf("\n");
}


void NodeFree(Node *p){
    int i;
    if(!p)return;
    if(p->type == TYPE_OP){
	for(i = 0;i<p->op.num;i++)
	    NodeFree(p->op.node[i]);
    }
    free(p);
}

void yyerror(char *s){
	 
    printf("<Parser Error> Line %d ,Col %d \n",G_iBuffRowCount+1,G_iBuffColCount+1);

    printf(" %s\n",G_sBuff[G_iBuffRowCount]);
}

int main(void){
    yyparse();
    return 0;
}
