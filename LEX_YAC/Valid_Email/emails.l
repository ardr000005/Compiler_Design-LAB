%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"emails.tab.h"
	#include<string.h>
	
	extern FILE *yyin;
%}

%%
[a-zA-Z0-9./%]+@[a-zA-Z]+\.[a-zA-Z]{2,} {yylval.str=strdup(yytext);return VALID_EMAIL;}
[ \t\n^] {;}
.+	{yylval.str=strdup(yytext);return INVALID_EMAIL;}
%%

int yywrap()
{
	return 1;
}



