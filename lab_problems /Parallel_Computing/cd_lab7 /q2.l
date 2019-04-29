%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"q2.tab.h"
%}

%%
[0-9]+ {printf("%s\n",yytext); return NUMBER;}
"if" {printf("%s\n",yytext);return IF;}
"else" {printf("%s\n",yytext);return ELSE;}
[a-zA-Z][a-zA-Z0-9_]* {printf("%s\n",yytext); return ID;}
";" {printf("%s\n",yytext);return SS;}
"=" {printf("%s\n",yytext);return EQ;}
"(" {printf("%s\n",yytext);return OBC;}
")" {printf("%s\n",yytext);return CBC;}
"{" {printf("%s\n",yytext);return OB;}
"}" {printf("%s\n",yytext);return CB;}
("+"|"-") {printf("%s\n",yytext); return ADOP;}
("*"|"/"|"%") {printf("%s\n",yytext); return MULOP;}
("=="|"!="|"<="|">="|">"|"<") {printf("%s\n",yytext); return RELOP;}
%%

int yywrap()
{return 1;} 