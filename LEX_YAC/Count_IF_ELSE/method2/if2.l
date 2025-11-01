%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"if2.tab.h"
%}
%%
"if" {  return IF;}
"else" { return ELSE;}
[ .\n\t] {;}
%%
int yywrap()
{
	return 1;
}
