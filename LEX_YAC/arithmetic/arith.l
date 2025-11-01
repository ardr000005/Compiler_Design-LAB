%{
	#include"y.tab.h"
	#include<stdio.h>
	#include<stdlib.h>
%}

%%
[0-9]+ {yylval = atoi(yytext); return NUMBER;}
[a-zA-Z] {return LETTER;}
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
")" {return ')';}
"(" {return '(';}
[ \n\t] {;}
. {return yytext[0];}
%%

int yywrap()
{
	return 1;
}
