%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char* msg);
	int yylex(void);
%}

%union{
char c;
}

%token <c> LETTER;

%%

input : 

	|input LETTER{printf("%c",$2);}
	;
%%

int main()
{
	printf("Enter the Letter\n");
	yyparse();
	return 0;
}

void yyerror(char* msg)
{
	printf("Error\n");
}
