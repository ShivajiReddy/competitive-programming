%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"q3.tab.h"
%}

%%
[0-9]+ {printf("%s\n",yytext); return NUMBER;}
\n {return NL;}
[a-zA-Z][a-zA-Z0-9_]* {printf("%s\n",yytext); return ID;}
"+" {printf("+\n"); return PLUS;}
"-" {printf("-\n"); return MINUS;}
"*" {printf("*\n"); return MUL;}
"/" {printf("/\n"); return DIV;}
%%

int yywrap()
{return 1;} 