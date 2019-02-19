#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token{
	int index;
	char name[256];
	char type[25];
	int size;
	char scope;
	int arg;
	int args[500];
	char returntype[25];
	struct token* next;
};

typedef struct token *TOKEN;
TOKEN table[10000];

void initialise_symtab()
{
	for(int i=0;i<10000;i++)
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

	int hash = (strlen(name)+15)%7;
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
	return;
}

int search(char name[])
{
	int hash = (strlen(name)+15)%7;
	TOKEN check = table[hash];
	while(check!=NULL)
	{
		if(strcmp(name,check->name)==0)
			return hash;
		check=check->next;
	}
	return -1;
}
void display()
{
	fprintf(yyout, "<index|type|size|scope|No.of.args|arguments|ReturnType>\n\n", );
	for(int i=0;i<10000;i++)
	{
		if(table[i]!=NULL)
		{
			TOKEN check=table[i];
			while(check!=NULL)
			{
				fprintf(yyout, "<%d|%s|%d|%c|%d|",check->index,check->type,check->size,check->scope,check->arg);
				for(int j =0;j<check->arg;j++)
					fprintf(yyout, "%d ",check->args[i]);
				fprintf(yyout, "|%s>\n",check->returntype);
				check=check->next;
			}
		}
	}	
}
int main()
{
	initialise_symtab();
	insert("DANIEL");
	insert("AADIL");
	insert("humus");
	printf("%d\n",search("DANIEL"));
	printf("%d\n",search("AADIL"));
	printf("%d\n",search("humus"));


	return 0;
}