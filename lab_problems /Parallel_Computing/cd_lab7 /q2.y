%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
extern FILE *yyin;
%}

%token IF ELSE ID NUMBER RELOP ADOP MULOP SS EQ OBC CBC OB CB
%left ';' '=' '(' ')' '{' '}'
%%
decision_stat : IF OBC expn CBC OB statement_list CB dprime 
	 		  ;
expn : simple_expn eprime
	 ;
simple_expn : term seprime
			;
term : factor tprime
	 ;
factor : ID
	   | NUMBER
	   ;
tprime : MULOP factor tprime
		|
		;
seprime : ADOP term seprime
		|
		;
eprime : RELOP simple_expn
		|
		;
statement_list : statement statement_list
				|
				;
statement : assign_stat SS
			| decision_stat
			;
assign_stat : ID EQ expn
			;
dprime : ELSE OB statement_list CB
		| 
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
