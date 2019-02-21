#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char inp[100], prods[100][100];
int i = 0;

void S();
void A();
void Ad();
void B();

void S() 
{
    if(inp[i] == 'a') 
    {
        printf("Matched: %c\n", inp[i]);
        ++i;
        A();
        if(inp[i] == 'c') 
        {
            printf("Matched: %c\n", inp[i]);
            ++i;
            B();
            if(inp[i] == 'e') 
            {
                printf("Matched: %c\n", inp[i]);
                ++i;
            } else 
            {
                printf("Error at: %c", inp[i]);
                exit(1);
            }
        } else 
        {
            printf("Error at: %c", inp[i]);
            exit(1);
        }
    } else 
    {
        printf("Error at: %c", inp[i]);
        exit(1);
    }
    if(inp[i] == '$') 
    {
        printf("Parsing complete.");
        exit(0);
    }
}

void A() 
{
    if(inp[i] == 'b') 
    {
        printf("Matched: %c\n", inp[i]);
        ++i;
        Ad();
    }
}

void Ad() 
{
    if(inp[i]=='b') 
    {
        printf("Matched: %c\n", inp[i]);
        ++i;
        Ad();
    } else if(inp[i]=='c') 
    {
        return;
    }
}

void B() 
{
    if(inp[i] == 'd') 
    {
        printf("Matched: %c\n", inp[i]);
        ++i;
    } else 
    {
        printf("Error at: %c\n", inp[i]);
        exit(1);
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
