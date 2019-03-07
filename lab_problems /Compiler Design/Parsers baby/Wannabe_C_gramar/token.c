#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct token
{
    char *word, *type;
    int row, col;
};

typedef struct token *Node;

Node getNode()
{
    Node x=(Node)malloc(sizeof(struct token));
    if(x==NULL)
        exit(0);
    x->word=malloc(sizeof(char)*20);
    x->type=malloc(sizeof(char)*20);
    return x;
}

int isKeyword(char *word)
{
    char keywords[32][32]={"auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

    for(int i=0; i<32; i++)
    {
        if(strcmp(keywords[i], word)==0)
            return 1;
    }
    return 0;
}

int isIdentifier(char *word)
{
    if(word[0]>='0' && word[0]<='9')
        return 0;
    int len=strlen(word);
    for(int i=1; i<len; i++)
    {
        if((word[i]>='0' && word[i]<='9')||(word[i]>='A'&& word[i]<='Z')||(word[i]>='a' && word[i]<='z')||(word[i]=='_'))
            continue;
        else
            return 0;
    }
    return 1;
}

int isNumericConstant(char *word)
{
    int len=strlen(word);
    if(word[0]>='0' && word[0]<='9')
    {
        if(len==1)
            return 1;
    }
    else
        return 0;
    for(int i=1; i<len; i++)
    {
        if((word[i]>='0' && word[i]<='9')||(word[i]=='.' && word[i-1]!='.')||(word[i]=='e' && word[i-1]!='e')||(word[i]=='E' && word[i-1]!='E'))
            continue;
        else
            return 0;
    }
    return 1;
}

int isAlphaNumeric(char c)
{
    return (c>='A' && c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')||(c=='_');
}

int isArithmetic(char c)
{
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='^';
}

int isRelational(char c)
{
    return c=='<'||c=='>'||c=='!'||c=='=';
}

int isLogical(char c)
{
    return c=='|'||c=='&'||c=='!';
}

int isSpecial(char c)
{
    return c=='('||c==')'||c=='{'||c=='}'||c=='['||c==']'||c==';'||c==','||c=='$'||c==':';
}

int isWhite(char ch)
{
    return (ch==' ' || ch=='\t' || ch=='\n' || ch=='\0' || ch==EOF);
}

Node print(char *word, int line, int col, int type)
{
    char *str=malloc(sizeof(char)*20);
    if(type==-1)
    {
        printf("Invalid Word\n");
        return NULL;
    }
    else if(type==1)
    {
        if(isKeyword(word))
            str="KEYWORD";
        else if(isIdentifier(word))
            str="IDENTIFIER";
        else if(isNumericConstant(word))
            str="NUMERIC CONSTANT";
        else
        {
            printf("Type 1 fail\n");
            return NULL;
        }
    }
    else if(type==2)
        str="ARITHMETIC OPERATOR";
    else if(type==3)
        str="RELATIONAL OPERATOR";
    else if(type==4)
        str="LOGICAL OPERATOR";
    else if(type==5)
        str="SPECIAL SYMBOL";
    else if(type==6)
        str="STRING LITERAL";
    else
    {
        printf("Type fail\n");
        return NULL;
    }
    Node t = getNode();
    strcpy(t->word, word);
    strcpy(t->type, str);
    t->row=line;
    t->col=col;
    return t;
    //printf("<%s, %d, %d, %s>\n", word, line, col, str);
}

Node getNextToken(FILE *fp)
{
    //char c=fgetc(fp);
    char c;
    int type=-1, open=0, line=1, col=1;

    while(c!=EOF)
    {
        c=fgetc(fp);
        char *word=malloc(sizeof(char)*20);

        if(c=='#')
        {
            while(c!='\n')
                c=fgetc(fp);
        }

        if(c=='/')
        {
            c=fgetc(fp);
            if(c=='/')
            {
                while(c!='\n')
                    c=fgetc(fp);
            }
            else if(c=='*')
            {
                //printf("E\n");
                int done=0;
                while(!done && c!=EOF)
                {
                    c=fgetc(fp);
                    if(c=='*')
                    {
                        c=fgetc(fp);
                        if(c=='/')
                            done=1;
                    }
                }
                c=fgetc(fp);
            }
            else
                ungetc(c,fp);
        }
        if(!isWhite(c))
        {
            if(isAlphaNumeric(c))
            {
                int i=0;
                while(isAlphaNumeric(c) || c=='.')
                {
                    word[i]=c;
                    i+=1;
                    c=fgetc(fp);
                }
                type=1;
                ungetc(c,fp);
                word[i]='\0';
            }
            else if(isArithmetic(c))
            {
                word[0]=c;
                if(c=='+')
                {
                    c=fgetc(fp);
                    if(c=='+')
                        word[1]=c;
                    else
                        ungetc(c,fp);
                    word[2]='\0';
                }
                else if(c=='-')
                {
                    c=fgetc(fp);
                    if(c=='-')
                        word[1]=c;
                    else
                        ungetc(c,fp);
                    word[2]='\0';
                }
                else
                    word[1]='\0';
                type=2;
            }
            else if(isRelational(c))
            {
                if(c=='<'||c=='>'||c=='='||c=='!')
                {
                    word[0]=c;
                    c=fgetc(fp);
                    if(c=='=')
                    {
                        word[1]='=';
                        word[2]='\0';
                    }
                    else
                        ungetc(c,fp);
                }
                else
                    word="";
                type=3;
            }
            else if(isLogical(c))
            {
                word[0]=c;
                if(c=='|')
                {
                    c=fgetc(fp);
                    if(c=='|')
                        word[1]='|';
                    else
                        ungetc(c,fp);
                    word[2]='\0';
                }
                else if(c=='&')
                {
                    c=fgetc(fp);
                    if(c=='&')
                        word[1]='&';
                    else
                        ungetc(c,fp);
                    word[2]='\0';
                }
                else
                    word[1]='\0';
                type=4;
            }
            else if(isSpecial(c))
            {
                word[0]=c;
                word[1]='\0';
                type=5;
                //col+=1;
            }
            else if(c=='\''||c=='\"')
            {
                word[0]=c;
                c=fgetc(fp);
                int i=1;
                while(c!='\'' && c!='\"')
                {
                    word[i]=c;
                    i+=1;
                    c=fgetc(fp);
                }
                word[i]=c;
                i+=1;
                word[i]='\0';
                type=6;
            }
            else
                printf("Fail:%c\n", c);
            Node head = print(word,line,col,type);
            if(head!=NULL)
                return head;
            else
                return NULL;
            col+=strlen(word);
            //col-=1;
        }
        else
            col+=1;

        if(c=='\n')
        {
            line+=1;
            col=1;
        }

        //c=fgetc(fp);
        if(c==EOF)
            break;
    }
    return NULL;
}
