%{
#include <unistd.h>      
#include <sys/types.h>	    
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "node.h"
#include "lexya_e.tab.h"
struct VarDefine G_Def[MAX_DEFS];
char G_sBuff[MAX_BUFF_ROWS][MAX_BUFF_COLS];
int G_iBuffRowCount = 0;
int G_iBuffColCount = 0;
extern void add_var(char *);	// and variable into memory
void add_buff(char *,char *);
void yyerror(char *);
%}

any .

%%



\/\/{any}*[\n] {

    add_buff(yytext,NULL);

    G_iBuffColCount=0;

    G_iBuffRowCount++;
}

#{any}*[\n] { 

    add_buff(yytext,NULL);

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

    char buf[100] = "TYPE          :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return INT;
}


"float" {

    yylval.index = FLOAT - USER_DEF_NUM;

    G_Def[yylval.index].name = "float";

    char buf[100] = "TYPE          :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return FLOAT;
}

"for" {

    yylval.index = FOR - USER_DEF_NUM;

    G_Def[yylval.index].name= "for";

    char buf[100] = "Token	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return FOR;
}

"foreach" {

    yylval.index = FOREACH - USER_DEF_NUM;

    G_Def[yylval.index].name= "foreach";

    char buf[100] = "Token	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf); printf("foreach\n");

    return FOREACH;
}

"in" {

    yylval.index = IN - USER_DEF_NUM;

    G_Def[yylval.index].name= "in";

    char buf[100] = "Token	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return IN;
}

"break" {

    yylval.index = BREAK - USER_DEF_NUM;

    G_Def[yylval.index].name= "break";

    char buf[100] = "Token	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return BREAK;
}

"continue" {

    yylval.index = CONTINUE - USER_DEF_NUM;

    G_Def[yylval.index].name= "continue";

    char buf[100] = "Token	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return CONTINUE;
}

"while" {

    yylval.index = WHILE-USER_DEF_NUM;

    G_Def[yylval.index].name= "while";

    char buf[100] = "Token      	   :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);
    
    return WHILE;
}


"if" {

    yylval.index = IF-USER_DEF_NUM;

    G_Def[yylval.index].name= "if";

    char buf[100] = "Token        	   :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return IF;
}

"else" {

    yylval.index = ELSE-USER_DEF_NUM;

    G_Def[yylval.index].name= "else";

    char buf[100] = "Token       	   :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);


    return ELSE;
}

"print" {

    yylval.index = PRINT-USER_DEF_NUM;

    G_Def[yylval.index].name= "print";

    char buf[100] = "Token      	   :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return PRINT;
}


[a-zA-Z][a-zA-Z0-9]* {

    add_var(yytext);

    yylval.index = G_iVarCurIndex;

    char buf[100] = "VAR           	   :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);


    return VARIABLE;	
}

  
[0-9]+ {
 
    yylval.val = atof(yytext);

    char buf[100] = "INT       	   :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return NUMBER;
}

[0-9]*\.[0-9]+ {

    yylval.val = atof(yytext);

    char buf[100] = "FLOAT              :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return NUMBER;
}

"++" { 
    
    yylval.index = ADD_T-USER_DEF_NUM; 
    
    G_Def[yylval.index].name="++"; 
    
    G_Def[yylval.index+1].name="++";  
    
    char buf[100] = "OP	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);
    
    return ADD_T; 
}

"--" { 
    
    yylval.index = MUS_T-USER_DEF_NUM; 
    
    G_Def[yylval.index].name="--"; 
    
    G_Def[yylval.index+1].name="--";  
    
    char buf[100] = "OP	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);
    
    return MUS_T; 
}

">=" { 
    
    yylval.index = GE - USER_DEF_NUM;  
    
    G_Def[yylval.index].name=">=";  
    
    char buf[100] = "OP	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);
    
    return GE;
}


"<=" { 
    
    yylval.index = LE - USER_DEF_NUM;  
    
    G_Def[yylval.index].name="<=";  
    
    char buf[100] = "OP	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);
    
    return LE;
}

"==" { 
    
    yylval.index = EQ - USER_DEF_NUM;  
    
    G_Def[yylval.index].name="==";  
    
    char buf[100] = "OP	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);
    
    return EQ;
}

"!=" { 
    
    yylval.index = NE - USER_DEF_NUM;  
    
    G_Def[yylval.index].name="!=";  
    
    char buf[100] = "OP	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);
    
    return NE;
}

"&&" { 
    
    yylval.index = AND - USER_DEF_NUM;  
    
    G_Def[yylval.index].name="&&";  
    
    char buf[100] = "OP	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);
    
    return AND;
}

"||" { 
    
    yylval.index = OR - USER_DEF_NUM;  
    
    G_Def[yylval.index].name="||";  
    
    char buf[100] = "OP	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);
    
    return OR;
}


"[" {

    yylval.index = *yytext;

    char buf[100] = "OP	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return *yytext;

}


"]" {

    yylval.index = *yytext;

    char buf[100] = "OP	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return *yytext;

}


[()<>=+\-*/;{}.] {

    yylval.index = *yytext;

    char buf[100] = "OP	           :       ";
    
    strcat(buf,yytext);

    add_buff(yytext,buf);

    return *yytext;

}

[\t]	{ add_buff(yytext,NULL);} 

[ ]	{ add_buff(yytext,NULL);}

{any}	{printf("Ignore Unknow Symbol:[%s]\n",yytext);}
	
%%

void add_buff(char *buff,char *data){
    strcat(G_sBuff[G_iBuffRowCount],buff);
    G_iBuffColCount += strlen(buff);

    int fd;
    
    fd = open("token.txt",O_WRONLY | O_CREAT | O_APPEND,S_IRWXU  | S_IRWXG | S_IRWXO);
   
    if(fd < 0)    
	printf("err in open\n");
        
    if(data != NULL){
    	write(fd,data,strlen(data));
	write(fd,"\n",strlen("\n"));
    }

    close(fd);
}

int yywrap(void) {

    return 1;

}
