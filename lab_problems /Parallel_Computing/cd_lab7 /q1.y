%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
extern FILE *yyin;
%}

%token NL ID NUMBER INT CHAR SS CO
%left ';' ','

%%
stmt : DC NL
	 ;
DC : DT IDL SS
	|
	;
DT : INT
	 | CHAR
	 ;
IDL: ID
	| ID CO IDL
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
