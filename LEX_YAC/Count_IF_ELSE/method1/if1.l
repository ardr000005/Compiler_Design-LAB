%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"if1.tab.h"
	int if_count=0,else_count=0;
%}
%%
"if" {if_count++;  return IF;}
"else" {else_count++; return ELSE;}
[ .\n\t] {;}
%%
int yywrap()
{
	return 1;
}
