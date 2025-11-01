%{
	#include<stdio.h>
	#include<stdlib.h>
	int p_c=0,s_c=0;
	extern FILE *yyin;
%}
%%

printf {printf("readf"); p_c++;	}
scanf {printf("writef"); s_c++;	}
[./t/n] {printf("%s",yytext);}

%%
void main()
{
	FILE *fp = fopen("input.txt","r");
	yyin = fp;
	yylex();
	printf("The no of printf is %d \n The no of scanf is %d \n",p_c,s_c);
	fclose(fp);
}
int yywrap()
{
	return 1;
}
