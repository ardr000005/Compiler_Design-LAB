%{
	#include<stdlib.h>
	#include<string.h>
	#include<stdio.h>
	int yylex(void);
	void yyerror(char* msg);
%}

%token NUMBER
%left '+' '-' 
%left '*' '/'

%%
	input:
		expr'\n' {printf("Result = %d\n",$1); }
		;
	expr: 
		 NUMBER {$$=$1;}
		|expr '+' expr {$$=$1+$3 ;}
		|expr '-' expr {$$=$1-$3; }
		|expr '*' expr {$$=$1*$3 ;}
		|expr '/' expr {if($3!=0)
				$$=$1/$3;
				else
				yyerror("Division by Zero"); }
		;
%%
int main()
{
	printf("Enter the value to calculate \n");
	yyparse();
	return 0;
}

void yyerror(char *msg)
{
	printf("%s",msg);
}

