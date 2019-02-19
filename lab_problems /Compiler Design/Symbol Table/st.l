%{
	#include<stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int line = 1, col = 1;
	int arg=0, args[50];
	char type[25],global='G';
	int in =0;
	#include "symtab.h"
%}

ws [" ""\n""\t"]+
sp [" ""\t"]+
digit [0-9]+
alpha [a-zA-Z]+
special [@#$(){}[\]~`:;,.?]
datatype ("int "|"char "|"double "|"float "|"long "|"short "|"void ") 
id [a-zA-Z_]({alpha}|{digit})*

%%
\n {line++;col=1;}
\t {col+=strlen(yytext);}
"//".*"\n" {line++;col=1;}
"/*"(.*"\n"?.*)*"*/" {
	int i = 0;
	while(yytext[i]!='\0'){
		if(yytext[i]=='\n'){
			line++;
			col=1;
		}
		else
			col++;
		i++;
	}
}
"#".*("<".*">")?("\"".*"\"")?"\n" {line++;col=1;}
"{" {global='L';}
"}" {global='G';}
{datatype} {
	yytext[strlen(yytext)-1]='\0';
	memset(type,'\0',25);
	strcpy(type,yytext);
}
{id}"(".*")" {
	char func_name[25],arg_type[25],argu[25];
	memset(func_name,'\0',25);
	int i=0,j=0,hash;
	while(yytext[i]!='(')
	{
		func_name[i]=yytext[i];
		i++;
	}	
	if(strcmp(func_name,"printf")==0||strcmp(func_name,"scanf")==0)
	{
		if(search(func_name)==-1)
			insert(in+1,func_name,"FUNC",0,global,0,0,"-");
		break;
	}
	i++;
	if(search(func_name)==-1)
	{
		while(yytext[i]!=')')
		{
			j=0;
			memset(arg_type,'\0',25);
			memset(argu,'\0',25);
			while(yytext[i]!=' ')
			{
				arg_type[j]=yytext[i];
				j++;
				i++;
			}
			i++;
			j=0;
			while(yytext[i]!=','&&yytext[i]!=')')
			{
				argu[j]=yytext[i];
				i++;
				j++;

			}
			hash = search(argu);
			if(hash==-1)
			{
				insert_var(in+1,argu,arg_type,'L');
				args[arg] = search(argu);
				arg++;	
			}
			else
			{
				args[arg] = hash;
				arg++;
			}
			if(yytext[i]==')')
				break;
			i++;
			while(yytext[i]==' ')
				i++;
		}
		insert(in+1,func_name,"FUNC",0,'G',arg,args,type);
		arg=0;
	}
}
({id},?)+;? {
	if(yytext[strlen(yytext)-1]==','||yytext[strlen(yytext)-1]==';')
		yytext[strlen(yytext)-1]='\0';
	int hash = search(yytext);
	if(hash==-1)
		insert_var(in+1,yytext,type,global);
} 
. {;}
%%

int main()
{
	initialise_symtab();
	yyin = fopen("input.c","r");
	yyout = fopen("output2.c","w");
	yylex();
}
int yywrap()
{
	display();
	return 1;
}