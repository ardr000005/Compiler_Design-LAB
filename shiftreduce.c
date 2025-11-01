#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int p_input=0,p_stack=0;
char stack[100],input[100];

void check()
{
	if(stack[p_stack]=='a' || stack[p_stack]=='b')
	{
	
			printf("Reduce E -> %c\n",stack[p_stack]);
			stack[p_stack]='E';
			
	}
	if(p_stack>=3 && stack[1]=='E' && stack[3]=='E'&&(stack[2]=='+' || stack[2]=='-' || stack[2]=='/' || stack[2]=='*') )
	{
		
			printf("Reduce E -> E%cE\n",stack[2]);
			strcpy(stack,"$E");
			p_stack=1;
	}
}

void main()
{
	printf("Enter the input \n");
	scanf("%s",input);
	stack[p_stack]='$';
	p_stack++;
	while(input[p_input]!='\0')
	{
		stack[p_stack]=input[p_input];
		printf("Shift %c\n",input[p_input]);
		check();
		p_input++;
		p_stack++;
		stack[p_stack] ='\0';
		
	}
	if(strcmp(stack,"$E")==0)
	{
		printf("Parsing Sucessful\n");
	}
	else
	{
		printf("Parsing Failed\n");
	}
}
