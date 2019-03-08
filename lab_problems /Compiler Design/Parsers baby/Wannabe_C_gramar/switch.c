#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.c"

Node switch_stmt(FILE *fp, Node token);
Node cases(FILE *fp, Node token);
Node def(FILE *fp, Node token);

Node loop(FILE *fp, Node token);

Node expn(FILE *fp, Node token);
Node simple(FILE *fp, Node token);
Node term(FILE *fp, Node token);
Node factor(FILE *fp, Node token);
Node tprime(FILE *fp, Node token);
Node mulop(FILE *fp, Node token);
Node seprime(FILE *fp, Node token);
Node addop(FILE *fp, Node token);
Node eprime(FILE *fp, Node token);
Node relop(FILE *fp, Node token);

Node stat_list(FILE *fp, Node token);
Node statement(FILE *fp, Node token);
Node assign(FILE *fp, Node token);
Node decision(FILE *fp, Node token);
Node dprime(FILE *fp, Node token);

void Success()
{
	printf("Success\n");
	exit(0);
}

void Error()
{
	printf("Error\n");
	exit(0);
}

Node dprime(FILE *fp, Node token)
{
	if(token!=NULL && strcmp(token->word, "else")==0)
	{
		token=getNextToken(fp);
		if(token!=NULL && (strcmp(token->word, "{")==0))
		{
			token=stat_list(fp, token);
			if(token!=NULL && (strcmp(token->word, "}")==0))
			{
				token=getNextToken(fp);
				return token;
			}
		}
	}
	return token;
}

Node decision(FILE *fp, Node token)
{
	if(token!=NULL && strcmp(token->word, "if")==0)
	{
		token=getNextToken(fp);
		if(token!=NULL && (strcmp(token->word, "(")==0))
		{
			token=expn(fp, token);
			if(token!=NULL && (strcmp(token->word, ")")==0))
			{
				token=getNextToken(fp);
				if(token!=NULL && (strcmp(token->word, "{")==0))
				{
					token=stat_list(fp, token);
					if(token!=NULL && (strcmp(token->word, "}")==0))
					{
						token=dprime(fp,token);
						if(token!=NULL)
						{
							token=getNextToken(fp);
							return token;
						}
					}
				}
			}
		}
	}
	return NULL;
}

Node assign(FILE *fp, Node token)
{
	if(token!=NULL && strcmp(token->type, "IDENTIFIER")==0)
	{
		token=getNextToken(fp);
		if(token!=NULL && (strcmp(token->word, "=")==0))
		{
			token=getNextToken(fp);
			token=expn(fp, token);

            if(strcmp(token->word, ";")==0)
                token=getNextToken(fp);

			if(token!=NULL)
                return token;
		}
	}
	return NULL;
}

Node statement(FILE *fp, Node token)
{
	Node temp = token;
	token=assign(fp, token);
	if(token==NULL)
	{
		token=decision(fp, temp);
		if(token==NULL)
		{
			token=loop(fp, temp);
			if(token==NULL)
                return NULL;
            else
                return token;
		}
		else
            return token;
	}
    return token;
}

Node stat_list(FILE *fp, Node token)
{
	Node temp=token;
	token=statement(fp, token);

	if(token!=NULL)
	{
		temp=token;
		token=stat_list(fp, token);
		if(token!=NULL)
			return token;
		else
			token=temp;
	}
	else
		token=temp;
	return token;
}

Node relop(FILE *fp, Node token)
{
	if(token!=NULL && (strcmp(token->type, "RELATIONAL OPERATOR")==0) )
	{
		token=getNextToken(fp);
		return token;
	}
	return NULL;
}

Node eprime(FILE *fp, Node token)
{
	Node temp=token;
	token=relop(fp, token);
	if(token!=NULL)
	{
		temp=token;
		token=simple(fp, token);
		if(token!=NULL)
			return token;
		else
			token=temp;
	}
	else
		token=temp;
	return token;
}

Node addop(FILE *fp, Node token)
{
	if(token!=NULL && ( (strcmp(token->word, "+")==0) || (strcmp(token->word, "-")==0) ))
	{
		token=getNextToken(fp);
		return token;
	}
	return NULL;
}

Node seprime(FILE *fp, Node token)
{
	Node temp=token;
	token=addop(fp, token);
	if(token!=NULL)
	{
		temp=token;
		token=term(fp, token);
		if(token!=NULL)
		{
			temp=token;
			token=seprime(fp, token);
			if(token!=NULL)
				return token;
			else
				token=temp;
		}
		else
			token=temp;
	}
	else
		token=temp;
	return token;
}

Node mulop(FILE *fp, Node token)
{
	if(token!=NULL && ((strcmp(token->word, "*")==0) || (strcmp(token->word, "/")==0) || (strcmp(token->word, "%")==0)))
	{
		token=getNextToken(fp);
		return token;
	}
	return NULL;
}

Node tprime(FILE *fp, Node token)
{
	Node temp = token;
	token=mulop(fp, temp);
	if(token!=NULL)
	{
		temp=token;
		token=factor(fp, token);
		if(token!=NULL)
		{
			temp=token;
			token=tprime(fp, token);
			if(token!=NULL)
				return token;
			else
				token=temp;
		}
		else
			token=temp;
	}
	else
		token=temp;
	return token;
}

Node factor(FILE *fp, Node token)
{
	if(token!=NULL && ((strcmp(token->type, "IDENTIFIER")==0) || (strcmp(token->type, "NUMERIC CONSTANT")==0)))
	{
		token=getNextToken(fp);
		return token;
	}
	return NULL;
}

Node term(FILE *fp, Node token)
{
	token=factor(fp, token);
	if(token!=NULL)
	{

		token=tprime(fp, token);
		if(token!=NULL)
			return token;
	}
	return NULL;
}

Node simple(FILE *fp, Node token)
{
	Node temp=token;
	token=term(fp, temp);
	if(token!=NULL)
	{
		token=seprime(fp, token);
		if(token!=NULL)
			return token;
	}
	return NULL;
}

Node expn(FILE *fp, Node token)
{
	token=simple(fp, token);
	if(token!=NULL)
	{
		token=eprime(fp, token);
		if(token!=NULL)
			return token;
	}
	return NULL;
}

Node loop(FILE *fp, Node token)
{
	if(strcmp(token->word, "while")==0)
	{
		token = getNextToken(fp);
		if(strcmp(token->word, "(")==0)
		{
		    token=getNextToken(fp);
			token = expn(fp, token);
			if(token!=NULL && strcmp(token->word, ")")==0)
            {
                token=getNextToken(fp);
                if(strcmp(token->word, "{")==0)
                {
                    token=getNextToken(fp);
                    token=stat_list(fp, token);
                    if(token!=NULL && strcmp(token->word, "}")==0)
                            Success();
                }
                else if(strcmp(token->word, ";")==0)
                    Success();
                else
                    Error();
            }
            else
                Error();
		}
		else
			Error();
	}
	else if(strcmp(token->word, "for")==0)
	{
		token = getNextToken(fp);
		if(strcmp(token->word, "(")==0)
		{
			token=getNextToken(fp);
			token = assign(fp, token);
			if(token!=NULL && strcmp(token->word, ";")==0)
			{
				token=getNextToken(fp);
				token = expn(fp, token);

				if(token!=NULL && strcmp(token->word, ";")==0)
				{
					token=getNextToken(fp);
					token = assign(fp, token);

					if(token!=NULL && strcmp(token->word, ")")==0)
					{
						token=getNextToken(fp);
						if(strcmp(token->word, "{")==0)
						{
							token=getNextToken(fp);
							token=stat_list(fp, token);
							if(token!=NULL && strcmp(token->word, "}")==0)
									Success();
						}
						else if(strcmp(token->word, ";")==0)
							Success();
						else
							Error();
					}
					else
						Error();
				}
				else
					Error();
			}
			else
				Error();
		}
		else
			Error();
	}
	return NULL;
}

Node cases(FILE *fp, Node token)
{
    if(strcmp(token->word, "case")==0)
    {
        token=getNextToken(fp);
        if(strcmp(token->type, "NUMERIC CONSTANT")==0 || strcmp(token->type, "STRING LITERAL")==0)
        {
            token=getNextToken(fp);
            if(strcmp(token->word, ":")==0)
            {
                token=getNextToken(fp);
                token=stat_list(fp,token);
                if(strcmp(token->word, "break")==0)
                {
                    token=getNextToken(fp);
                    if(strcmp(token->word, ";")==0)
                        Success();
                    else
                        Error();
                }
                else
                    Error();
            }
            else
                Error();
        }
        else
            Error();
    }
    else if(strcmp(token->word, "default")==0)
    {
        token=getNextToken(fp);
        if(strcmp(token->word, ":")==0)
        {
            token=getNextToken(fp);
            token=stat_list(fp,token);
            if(strcmp(token->word, "break")==0)
            {
                token=getNextToken(fp);
                if(strcmp(token->word, ";")==0)
                    Success();
                else
                    Error();
            }
            else
                Error();
        }
        else
            Error();
    }
    return token;
}

Node switch_stmt(FILE *fp, Node token)
{
	if(strcmp(token->word, "switch")==0)
	{
		token = getNextToken(fp);
		if(strcmp(token->word, "(")==0)
		{
		    token=getNextToken(fp);
			if(strcmp(token->type, "IDENTIFIER")==0)
            {
                token=getNextToken(fp);
                if(strcmp(token->word, ")")==0)
                {
                    token=getNextToken(fp);
                    if(strcmp(token->word, "{")==0)
                    {
                        token=getNextToken(fp);
                        token=cases(fp, token);
                        //token = def(fp, token);
                        if(token!=NULL && strcmp(token->word, "}")==0)
                            Success();
                        else
                            Error();
                    }
                    else
                        Error();
                }
                else
                    Error();
            }
            else
                Error();
		}
		else
			Error();
	}
	return NULL;
}

int main()
{
	FILE *fp = fopen("input1.c", "r");
	if(fp==NULL)
	{
		printf("File not found\n");
		exit(0);
	}

	Node token = getNextToken(fp);
	token = switch_stmt(fp, token);
	if(token==NULL)
        Error();

	return 0;
}

