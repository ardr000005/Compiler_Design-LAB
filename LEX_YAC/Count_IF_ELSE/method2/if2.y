%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char* msg);
	int yylex(void);
	int if_count=0,else_count=0;
%}


%token  IF;
%token ELSE;

%%

input:
	
	|input expr
	;

expr:
	IF{if_count++;}
	|ELSE{else_count++;}
	;

final: input { printf("%d %d",if_count,else_count);}
	;
%%

int main()
{
	printf("Enter the Program\n");
	yyparse();
	return 0;
}

void yyerror(char* msg)
{
	printf("Error\n");
}
