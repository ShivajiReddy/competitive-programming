%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
extern FILE *yyin;
%}

%token NL ID NUMBER PLUS MINUS MUL DIV POW 
%left '+' '-' '*' '/' '^'
%%
stmt : stmt line
	 |
	 ;
line : NL
	 | exp NL
	 ;
exp : NUMBER
	| exp exp PLUS
	| exp exp MINUS
	| exp exp MUL
	| exp exp DIV
	| exp exp POW
	;
%%

int yyerror(char *msg)
{
printf("Invalid Expression\n");
exit(0);
}

void main()
{
	printf("Enter the Expression\n");
	yyin = fopen("in.txt","r");
	do
	{
		if(yyparse())
		{
			printf("\n Failure");
			exit(0);
		}
	}while(!feof(yyin));
	printf("success\n");
}
