%{
	#include"valid.tab.h"
	#include<stdio.h>
	#include<stdlib.h>
%}
%%
[a-zA-Z][a-zA-Z0-9]* {return IDD;}
[ \n\t]+	    {;}
.	    {return yytext[0];}
%%
int yywrap()
{
	return 1;
}

