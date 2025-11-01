%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char* msg);
	int yylex(void);
	extern int if_count,else_count;
%}


%token  IF;
%token ELSE;

%%

input : 

	|input statement{}
	;

statement :
	     IF{}
	    |ELSE{}
	    ;
%%

int main()
{
	printf("Enter the Program\n");
	yyparse();
	printf("if %d else %d",if_count,else_count);
	return 0;
}

void yyerror(char* msg)
{
	printf("Error\n");
}
