/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/
struct token{
	int index;
	char name[256];
	char type[25];
	int size;
	char scope;
	int arg;
	int args[50];
	char returntype[25];
	struct token* next;
};

typedef struct token *TOKEN;
TOKEN table[20];

void initialise_symtab()
{
	for(int i=0;i<20;i++)
		table[i]=NULL;
}
void insert(int index, char name[], char type[], int size, char scope,int arg, int args[],char returntype[25])
{
	TOKEN temp = (TOKEN) malloc(sizeof(struct token));
	temp->index = index;
	strcpy(temp->name,name);
	strcpy(temp->type,type);
	temp->size=size;
	temp->scope=scope;
	temp->arg=arg;
	for(int i=0;i<arg;i++)
		temp->args[i]=args[i];
	strcpy(temp->returntype,returntype);
	temp->next=NULL;

	int hash = (strlen(name)+15)%19;
	if(table[hash]==NULL)
	{
		table[hash] = temp;
	}
	else
	{
		TOKEN check = table[hash];
		while(check->next!=NULL)
			check=check->next;
		check->next = temp;
	}
	in++;
	return;
}

int search(char name[])
{
	int hash = (strlen(name)+15)%19;
	TOKEN check = table[hash];
	while(check!=NULL)
	{
		if(strcmp(name,check->name)==0)
			return hash;
		check=check->next;
	}
	return -1;
}

void insert_var(int index, char name[], char type[], char scope)
{
	if(strcmp(type,"int")==0)
			insert(in+1,name,type,sizeof(int),scope,0,NULL,"-");
		else if(strcmp(type,"long")==0)
			insert(in+1,name,type,sizeof(long),scope,0,NULL,"-");
		else if(strcmp(type,"float")==0)
			insert(in+1,name,type,sizeof(float),scope,0,NULL,"-");
		else if(strcmp(type,"double")==0)
			insert(in+1,name,type,sizeof(double),scope,0,NULL,"-");
		else if(strcmp(type,"short")==0)
			insert(in+1,name,type,sizeof(short),scope,0,NULL,"-");
		else if(strcmp(type,"char")==0)
			insert(in+1,name,type,sizeof(char),scope,0,NULL,"-");
}

void display()
{
	fprintf(yyout, "<index|name|type|size|scope|No.of.args|arguments|ReturnType>\n\n");
	for(int i=0;i<20;i++)
	{
		if(table[i]!=NULL)
		{
			TOKEN check=table[i];
			while(check!=NULL)
			{
				fprintf(yyout, "<%d|%s|%s|%d|%c|%d|",check->index,check->name,check->type,check->size,check->scope,check->arg);
				for(int j = 0;j<check->arg;j++)
					fprintf(yyout, "%d ",check->args[j]);
				fprintf(yyout, "|%s>\n",check->returntype);
				check=check->next;
			}
		}
	}	
}