%{
	#include<stdio.h>
	#include<string.h>
	int v=0;
	int c=0;	
%}

%%
[AEIOUaeiou] {v++;}
[A-Za-z]  {c++;}
.         {;}
%%

void main()
{
	printf("Enter the String");
	yylex();
	printf("No of Vowels is %d No of Consonants %d",v,c);
}
int yywrap()
{
	return 1;
}
