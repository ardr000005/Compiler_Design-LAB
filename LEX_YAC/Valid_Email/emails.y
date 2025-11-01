%{
	#include<stdlib.h>
	#include<stdio.h>
	void yyerror(char *msg);
	int yylex(void);
	extern FILE *yyin;
	FILE *valid_out,*invalid_out;
	
%}

%union
{
	char *str;
}

%token <str> VALID_EMAIL
%token <str> INVALID_EMAIL

%%
	input:
		
		| input email {}
		;
	email:
		 VALID_EMAIL {fprintf(valid_out,"%s\n",$1);free($1);}
		|INVALID_EMAIL {fprintf(invalid_out,"%s\n",$1);free($1);}
		;
%%

void main()
{
	yyin = fopen("email.txt","r");
	valid_out=fopen("valid.txt","w");
	invalid_out=fopen("invalid.txt","w");
	yyparse();
}

void yyerror(char *msg)
{
	printf("Error");
}

