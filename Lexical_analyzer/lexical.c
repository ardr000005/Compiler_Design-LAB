#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>

char keyword[20][30],identifier[20][30],operator[20][30],literal[20][30];
int key_c=0,iden_t=0,operator_t=0,liter_t=0;

int iskeyword(char *token)
{
	if(strcmp(token,"int")==0 || strcmp(token,"void")==0 || strcmp(token,"if")==0 || strcmp(token,"main")==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isidentifier(char *token)
{
	if(token[0]>='a' && token[0]<='z')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isoperator(char *token)
{
	if(strcmp(token,"+")==0 || strcmp(token,"-")==0 || strcmp(token,"=")==0 || strcmp(token,"*")==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



void tokenize(char *line)
{
	const char *delimiter =" ,\t\n;" ;
	char *token = strtok(line,delimiter);
	
	while(token != NULL)
	{
		if(iskeyword(token))
		{
			strcpy(keyword[key_c],token);
			key_c++;
		}
		else if(isidentifier(token))
		{
			strcpy(identifier[iden_t],token);
			iden_t++;
		}
		else if(isoperator(token))
		{
			strcpy(operator[operator_t],token);
			operator_t++;
		}
		else
		{
			strcpy(literal[liter_t],token);
			liter_t++;
		}
		token = strtok(NULL, delimiter);
	}
}

int main()
{
	FILE *fp;
	char line[20];
	fp=fopen("in.txt","r");
	
	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		tokenize(line);
	}
	fclose(fp);
	printf("Keywords are : ");
	for(int i=0;i<key_c;i++)
	{
		printf("%s ",keyword[i]);
	}
	printf("\n ");
	printf("Identifiers are : ");
	for(int i=0;i<iden_t;i++)
	{
		printf("%s ",identifier[i]);
	}
	printf("\n ");
	printf("Operators are: ");
	for(int i=0;i<operator_t;i++)
	{
		printf("%s ",operator[i]);
	}
	printf("\n");
	
	printf("Literals are: ");
	for(int i=0;i<liter_t;i++)
	{
		printf("%s ",literal[i]);
	}
	printf("\n");
	return 0;
}
