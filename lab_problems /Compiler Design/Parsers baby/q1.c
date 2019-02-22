//Sanjeevi's; minor errors?
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char inp[100], prods[100][100];
int i = 0;

void S();
void T();
void Td();


void S() 
{
    if(inp[i] == 'a') 
    {
        printf("Matched: %c\n", inp[i]);
        ++i;
        
    } 
    else if(inp[i] == '>') 
    {
        printf("matched at: %c\n", inp[i]);
        ++i;
    }
    else if(inp[i] == '(') 
    {
        printf("matched at %c\n",inp[i]);
        ++i;
        T();
        if(inp[i] == ')')
        {
            printf("matched at %c\n",inp[i] );
            ++i;
        }
        else
            printf("error\n");
    }
    else
        printf("error\n");
    if(inp[i] == '$')
    {
        
        printf("Parsing complete.");
        exit(0);
    
    }
}

void T() 
{
    S();
    Td();
}

void Td() 
{
    if(inp[i]==',') 
    {
        printf("Matched: %c\n", inp[i]);
        ++i;
        S();
        Td();
    } 
}


int main() 
{
    
    printf("Enter the input string: \n");
    scanf("%s", inp);

    int len = strlen(inp);
    inp[len] = '$';

    S();

    return 0;
}
