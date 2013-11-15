%{
#include <stdlib.h>
#include "node.h"
#include "lexya_e.tab.h"
struct VarDefine G_Def[MAX_DEFS];
char G_sBuff[MAX_BUFF_ROWS][MAX_BUFF_COLS];
int G_iBuffRowCount = 0;
int G_iBuffColCount = 0;
extern void add_var(char *);	// and variable into memory
void add_buff(char *);
void yyerror(char *);
%}

any .

%%



\/\/{any}*[\n] {
	
    add_buff(yytext);

    G_iBuffColCount=0;

    G_iBuffRowCount++;
}

#{any}*[\n] { 

    add_buff(yytext);

    G_iBuffColCount=0;

    G_iBuffRowCount++;
}

[\n] {
    
    G_iBuffColCount=0;

    G_iBuffRowCount++;
}

"int" {

    yylval.index = INT - USER_DEF_NUM;

    G_Def[yylval.index].name = "int";

    add_buff(yytext);

    return INT;
}


"float" {

    yylval.index = FLOAT - USER_DEF_NUM;

    G_Def[yylval.index].name = "float";

    add_buff(yytext);

    return FLOAT;
}

"for" {

    yylval.index = FOR - USER_DEF_NUM;

    G_Def[yylval.index].name= "for";

    add_buff(yytext);

    return FOR;
}

"while" {

    yylval.index = WHILE-USER_DEF_NUM;

    G_Def[yylval.index].name= "while";

    add_buff(yytext);

    return WHILE;
}


"if" {

    yylval.index = IF-USER_DEF_NUM;

    G_Def[yylval.index].name= "if";

    add_buff(yytext);

    return IF;
}

"else" {

    yylval.index = ELSE-USER_DEF_NUM;

    G_Def[yylval.index].name= "else";

    add_buff(yytext);

    return ELSE;
}

"print" {

    yylval.index = PRINT-USER_DEF_NUM;

    G_Def[yylval.index].name= "print";

    add_buff(yytext);

    return PRINT;
}


[a-zA-Z][a-zA-Z0-9]* {

    add_var(yytext);

    yylval.index = G_iVarCurIndex;

    add_buff(yytext);

    return VARIABLE;	
}

  
[0-9]+ {
 
    yylval.val = atof(yytext);

    add_buff(yytext);

    return NUMBER;
}

[0-9]*\.[0-9]+ {

    yylval.val = atof(yytext);

    add_buff(yytext);

    return NUMBER;
}

"++" { 
    
    yylval.index = ADD_T-USER_DEF_NUM; 
    
    G_Def[yylval.index].name="++"; 
    
    G_Def[yylval.index+1].name="++";  
    
    add_buff(yytext); 
    
    return ADD_T; 
}

"--" { 
    
    yylval.index = MUS_T-USER_DEF_NUM; 
    
    G_Def[yylval.index].name="--"; 
    
    G_Def[yylval.index+1].name="--";  
    
    add_buff(yytext); 
    
    return MUS_T; 
}

">=" { 
    
    yylval.index = GE - USER_DEF_NUM;  
    
    G_Def[yylval.index].name=">=";  
    
    add_buff(yytext); 
    
    return GE;
}


"<=" { 
    
    yylval.index = LE - USER_DEF_NUM;  
    
    G_Def[yylval.index].name="<=";  
    
    add_buff(yytext); 
    
    return LE;
}

"==" { 
    
    yylval.index = EQ - USER_DEF_NUM;  
    
    G_Def[yylval.index].name="==";  
    
    add_buff(yytext); 
    
    return EQ;
}

"!=" { 
    
    yylval.index = NE - USER_DEF_NUM;  
    
    G_Def[yylval.index].name="!=";  
    
    add_buff(yytext); 
    
    return NE;
}

"&&" { 
    
    yylval.index = AND - USER_DEF_NUM;  
    
    G_Def[yylval.index].name="&&";  
    
    add_buff(yytext); 
    
    return AND;
}

"||" { 
    
    yylval.index = OR - USER_DEF_NUM;  
    
    G_Def[yylval.index].name="||";  
    
    add_buff(yytext); 
    
    return OR;
}


"[" {

    yylval.index = *yytext;

    add_buff(yytext);

    return *yytext;

}


"]" {

    yylval.index = *yytext;

    add_buff(yytext);

    return *yytext;

}


[()<>=+\-*/;{}.] {

    yylval.index = *yytext;

    add_buff(yytext);

    return *yytext;

}

[\t]	{ add_buff(yytext);} 

[ ]	{ add_buff(yytext);}

{any}	{printf("Ignore Unknow Symbol:[%s]\n",yytext);}
	
%%

void add_buff(char *buff){
    strcat(G_sBuff[G_iBuffRowCount],buff);
    G_iBuffColCount += strlen(buff);
}

int yywrap(void) {

    return 1;

}
