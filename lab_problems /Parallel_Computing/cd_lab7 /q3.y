%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
extern FILE *yyin;
%}

%token NL ID NUMBER PLUS MINUS MUL DIV
%left '+' '-' '*' '/'
%%
stmt : exp NL
	 ;
exp : exp PLUS term
	| exp MINUS term
	| exp MUL term
	| exp DIV term
	| term
	;
term : ID
	 | NUMBER
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
