%{
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include"cal.tab.h"
	
%}

%%
[0-9]+ {yylval=atoi(yytext);return NUMBER;}
\n  { return '\n'; }
[ \t] {;}
. {return yytext[0];}
%%

int yywrap()
{
	return 1;
}
