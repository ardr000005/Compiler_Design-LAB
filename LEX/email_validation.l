%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%%
[a-zA-Z0-9._%]+@[a-zA-Z]+\.[a-zA-Z]{2,} {printf("Valid Email"); return 1;}
. {printf("Invalid Email");return 1;}
%%
int main()

{
	char input[100];
	printf("Enter an email\n");
	yylex();
	return 0;
}

int yywrap()
{
	return 1;
}
