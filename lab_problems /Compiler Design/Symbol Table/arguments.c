#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	
	char str[256] = "main(int argc, char* argv[], double k)";
	char name[256],arg_type[256],argu[256];
	memset(name,'\0',256);
	int i=0,j;
	while(str[i]!='(')
	{
		name[i]=str[i];
		i++;
	}
	i++;
	while(str[i]!=')')
	{
		j=0;
		memset(arg_type,'\0',256);
		memset(argu,'\0',256);
		while(str[i]!=' ')
		{
			arg_type[j]=str[i];
			j++;
			i++;
		}
		printf("%s\n", arg_type);
		i++;
		j=0;
		while(str[i]!=','&&str[i]!=')')
		{
			argu[j]=str[i];
			j++;
			i++;
		}
		printf("%s\n",argu );
		if(str[i]==')')
			break;
		i++;
		while(str[i]==' ')
			i++;
		
	}

	printf("\n");
	return 0;
}