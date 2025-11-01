%{
	#include<stdio.h>
	#include<stdlib.h>
	int odd=0,i;
%}
%%
[0-9] {i=atoi(yytext);
	if(i%2==0)
	odd=0;
	else
	odd=1;
}
[\t\n] 	{;}
.	{;}
%%
void main()
{
	printf("Enter the digit \n");
	yylex();
	if(odd)
	printf("ODD");
	else
	printf("Even");
}
int yywrap()
{
	return 1;
}
