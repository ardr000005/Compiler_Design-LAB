%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex(void);
	void yyerror(char* msg);
%}

%token LETTER NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS

%%
input:
	
	|expr {printf("Valid Expression\n");}
	;
expr:
	 expr '+' expr {}
	|expr '-' expr {}
	|expr '/' expr {}
	|expr '*' expr {}
	|'-' expr %prec UMINUS {}
	|'(' expr ')' {}
	|NUMBER {}
	|LETTER {}
	;
%%
int main()
{
	printf("Enter the Expression");
	yyparse();
	return 0;
}
void yyerror(char* msg)
{
	printf("Invalid Expression");
}
