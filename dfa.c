#include<stdio.h>
#include<string.h>

void main()
{
	char string[10];
	printf("Enter the String to parse through DFA \n");
	scanf("%s",string);
	
	int state =0;
	
	for(int i=0;i<strlen(string);i++)
	{
		char ch = string[i];
		
		switch(state)
		{
			case 0 : if(ch == 'a')
				 state = 1;
				 if(ch == 'b')
				 state = 0;
				 break;
			case 1 : if(ch == 'a')
				 state = 1;
				 if(ch == 'b')
				 state = 2;
				 break;
			case 2 : if(ch == 'a')
				 state = 1;
				 if(ch == 'b')
				 state = 0;
				 break;
		}
	}
	
	if(state ==2)
	printf("String Accepted\n");
	else
	printf("Not Accepted\n");
}


















