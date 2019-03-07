#include<stdio.h>
#include<stdlib.h>
//#include"lex_analyzer.h"
#include "sym_table.h"
#include<string.h>

Token lookahead; 


FILE *fa,*fb; 

void looping_start();
void expn();
void assign_stat();
void statement_list();
void statement(); 
void simple_exp(); 
void factor();
void tprime();
void seprime(); 
void term(); 
void eprime(); 
void relop();
void addop();
void mulop(); 

void error(Token t)
{
    printf("error at line %d and col %d \n",t.row,t.col); 
    exit(1); 
}

void looping_start()
{
    if(strcmp(lookahead.lexeme,"while")==0)
    {
        lookahead=getNextToken(fa);
        insert_util(lookahead,fa); 
        if(strcmp(lookahead.lexeme,"(")==0)
        {
            lookahead=getNextToken(fa); 
            insert_util(lookahead,fa); 
            expn();
            if(strcmp(lookahead.lexeme,")")==0)
            {
                lookahead=getNextToken(fa);
                insert_util(lookahead,fa); 
                if(strcmp(lookahead.lexeme,"{")==0)
                {
                    lookahead=getNextToken(fa); 
                    insert_util(lookahead,fa); 
                    statement_list();
                    if(strcmp(lookahead.lexeme,"}")==0)
                    {
                        lookahead=getNextToken(fa); 
                        insert_util(lookahead,fa); 
                        return; 
                    }
                    else error(lookahead); 
                }
                else error(lookahead); 
            }
            else error(lookahead); 
        }
        else error(lookahead); 
    }
    else if(strcmp(lookahead.lexeme,"for")==0)
    {
        lookahead=getNextToken(fa); 
        insert_util(lookahead,fa); 
        if(strcmp(lookahead.lexeme,"(")==0)
        {
            lookahead=getNextToken(fa); 
            insert_util(lookahead,fa); 
            assign_stat();
            if(strcmp(lookahead.lexeme,";")==0)
            {
                lookahead=getNextToken(fa); 
                insert_util(lookahead,fa); 
                expn();
                if(strcmp(lookahead.lexeme,";")==0)
                {
                    lookahead=getNextToken(fa); 
                    insert_util(lookahead,fa); 
                    assign_stat();
                    if(strcmp(lookahead.lexeme,")")==0)
                    {
                        lookahead=getNextToken(fa); 
                        insert_util(lookahead,fa); 
                        if(strcmp(lookahead.lexeme,"{")==0)
                        {
                            lookahead=getNextToken(fa);
                            insert_util(lookahead,fa); 
                            statement_list();
                            if(strcmp(lookahead.lexeme,"}")==0)
                            {
                                lookahead=getNextToken(fa);
                                insert_util(lookahead,fa); 
                                return; 

                            }
                            else error(lookahead); 

                        }
                        else error(lookahead); 
                    }
                    else error(lookahead); 
                }
                else error(lookahead); 
            }
            else error(lookahead); 
        }
        else error(lookahead); 
    }
    else error(lookahead); 
}

void assign_stat()
{
    if(lookahead.type==2)
    {
        lookahead=getNextToken(fa);
        insert_util(lookahead,fa);
        if(strcmp(lookahead.lexeme,"=")==0)
        {
            lookahead=getNextToken(fa);
            insert_util(lookahead,fa);
            expn(); 
        }
        else
            error(lookahead); 
    }
}

void statement_list()
{
    if(lookahead.type==2 || strcmp(lookahead.lexeme,"while")==0 || strcmp(lookahead.lexeme,"while")==0)
    {
        statement();
        statement_list();
    }
    else return ; 
}

void statement()
{
    if(lookahead.type==2)
    {
        assign_stat();
        if(strcmp(lookahead.lexeme,";")==0)
        {
            lookahead=getNextToken(fa);
            insert_util(lookahead,fa); 
            return ; 
        }
    }
    else if(strcmp(lookahead.lexeme,"while")==0 || strcmp(lookahead.lexeme,"for")==0)
    {
        looping_start(); 

    }
    else error(lookahead); 
}

void expn()
{
    simple_exp(); 
    eprime();
}
void simple_exp()
{

    term();
    seprime();
}
void eprime()
{
    printf("%s eprime %d type\n",lookahead.lexeme,lookahead.type); 
    if(lookahead.type==4)
    {
        relop();
        simple_exp();
    }
    else return; 
}
void term()
{
    //lookahead.getNextToken();
    factor();
    tprime(); 

}
void seprime()
{
    printf("%s seprime %d type\n",lookahead.lexeme,lookahead.type); 
    if(lookahead.type==3)
    {
        addop();
        term();
        seprime(); 
    }
    else return; 
}
void tprime()
{
    if(strcmp(lookahead.lexeme,"*")==0 || strcmp(lookahead.lexeme,"/")==0 || strcmp(lookahead.lexeme,"%")==0 ) 
    {
        mulop();
        factor();
        tprime();

    }
    else return ; 
}
void relop()
{
    if(lookahead.type==4)
    {
        lookahead=getNextToken(fa);
        insert_util(lookahead,fa); 
    }
    else
        error(lookahead); 
}
void addop()
{
    if(strcmp(lookahead.lexeme,"+")==0 || strcmp(lookahead.lexeme,"-")==0 )
    {
        lookahead=getNextToken(fa);
        insert_util(lookahead,fa); 
    }
    else
        error(lookahead); 
}
void factor()
{
    if(lookahead.type==2 || lookahead.type==8)
    {
        lookahead=getNextToken(fa); 
        insert_util(lookahead,fa); 
    }
    else
        error(lookahead); 
}
void mulop()
{
    if(strcmp(lookahead.lexeme,"*")==0 || strcmp(lookahead.lexeme,"/")==0 || strcmp(lookahead.lexeme,"%")==0 ) 
    {
        lookahead=getNextToken(fa); 
        insert_util(lookahead,fa); 
    }
    else
        error(lookahead); 
}
int main()
{
    fa = fopen("q2i.c","r");
    fb = fopen("qi2.c","w");
    discard_headers_comments(fa,fb);

    fa = fopen("qi2.c","r");
    if(fa == NULL){
        printf("Cannot open file \n");
        exit(0);
    }   

    Token t[100];
    /*    
          while(!feof(fa))
          {
    //t[i]=getNextToken(fa);
    lookahead=getNextToken(fa); 
    insert_util(lookahead,fa); 
    }
    */
    lookahead=getNextToken(fa);   
    insert_util(lookahead,fa); 
    looping_start(); 
    if(strcmp(lookahead.lexeme,"$")==0)
        printf("successful\n");
    else
    {
        error(lookahead); 
    }
    Display(); 

    return 0; 

}
q2.c
Displaying q2i.c.