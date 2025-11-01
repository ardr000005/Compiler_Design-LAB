%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<ctype.h>
	#include"if3.tab.h"
%}
%%
[a-z] {yylval.c=toupper(yytext[0]); return LETTER;}
[A-Z] {yylval.c=toupper(yytext[0]); return LETTER;}
[ .\n\t] {;}
%%
int yywrap()
{
	return 1;
}
