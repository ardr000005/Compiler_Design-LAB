#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char stack[100],input[100],postfix[100];
int assign_c=0,top=-1,postfix_p=0;

void stack_c(char c)
{
	if(c=='(')
	{
		top++;
		stack[top]=c;
	}
	
	if(c == '/' )
	{
		while(stack[top]=='*' && top!= -1 )
		{
			postfix[postfix_p]=stack[top];
			postfix_p++;
			top--;
		}
		top++;
		stack[top]=c;
	}
	
	if(c == '*' )
	{
		while(stack[top]=='/' && top!= -1 )
		{
			postfix[postfix_p]=stack[top];
			postfix_p++;
			top--;
		}
		top++;
		stack[top]=c;
	}
	
	if(c == '+' )
	{
		while((stack[top]=='*' || stack[top]=='/' || stack[top]=='-') && top!= -1 )
		{
			postfix[postfix_p]=stack[top];
			postfix_p++;
			top--;
		}
		top++;
		stack[top]=c;
	}
	
	if(c == '-' )
	{
		while((stack[top]=='*' || stack[top]=='/' || stack[top]=='+') && top!= -1 )
		{
			postfix[postfix_p]=stack[top];
			postfix_p++;
			top--;
		}
		top++;
		stack[top]=c;
	}
	
	if(c == ')' )
	{
		while(stack[top]!='(' && top!=-1)
		{
			postfix[postfix_p]=stack[top];
			postfix_p++;
			top--;
		}
		top--;
	}
}

void postfix_c()
{
	int i=0;
	for(i=0;i<strlen(input);i++)
	{
		if(input[i]=='=')
		{
			postfix[i]=input[i];
			break;
		}
		postfix[i]=input[i];
		
	}
	
	assign_c=i+1;
	postfix_p=i+1;
	for(i=assign_c;i<strlen(input);i++)
	{
		if(input[i]>='a' && input[i]<='z')
		{
			postfix[postfix_p]=input[i];
			postfix_p++;	
		}
		else
		{
			stack_c(input[i]);
		}
	}
	while(top!=-1)
	{
		if(stack[top]!='(' || stack[top]!=')')
		{
		postfix[postfix_p]=stack[top];
		postfix_p++;
		}	
		top--;
	}
	postfix[postfix_p] = '\0'; 
	
}

void gTAC()
{
	int k=0;
	char temp[10];
	top=-1;
	for(int i=assign_c;i<postfix_p;i++)
	{
		if(postfix[i]>='a' && postfix[i]<='z')
		{
			top++;
			stack[top]=postfix[i];
		}
		else
		{
			
			sprintf(temp, "T%d", k++);
			printf("%s = %c %c %c\n",temp,stack[top-1],postfix[i],stack[top]);
			top=top-1;
			stack[top]=temp[1];	
		}
	}
	printf("%c %c T%c\n",postfix[0],postfix[1],stack[top]);
}

void main()
{
	printf("Enter an expression\n");
	scanf("%s",input);
	postfix_c();
	printf("%s\n",postfix);
	gTAC();
}

