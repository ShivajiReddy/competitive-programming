%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"q1.tab.h"
%}

%%
[0-9]+ {printf("%s\n",yytext); return NUMBER;}
\n {return NL;}
"int" {return INT;}
"char" {return CHAR;}
[a-zA-Z][a-zA-Z0-9_]* {printf("%s\n",yytext); return ID;}
";" {printf(";\n"); return SS;}
"," {printf(",\n"); return CO;}
%%

int yywrap()
{return 1;} 