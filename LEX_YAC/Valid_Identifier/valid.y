%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex(void);
	void yyerror(char* msg);
	
%}

%token IDD

%%
	input:
		IDD {printf("Valid Identifier\n");return 1;}
		;
%%

int main()
{
	printf("Enter the Identifier");
	yyparse();
	return 0;
}
void yyerror(char *msg)
{
	printf("Invalid Identifier\n");
}
