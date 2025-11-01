#include<stdio.h>
#include<string.h>
void main()
{
	int i,n;
	char store[10][10];
	
	printf("Enter the number of equations\n");
	scanf("%d",&n);
	
	printf("Enter the Equations\n");
	for(i=0;i<n;i++)
	{
		scanf("%s",store[i]);
	}
	int j=0;
	char symbol[10];
	printf("\n");
	for(int i=0;i<n;i++)
	{
		char op = store[i][3];
		switch(op)
		{
			case '+' :strcpy(symbol,"ADD");
				   break;
			case '-' :strcpy(symbol,"SUB");
				   break;
			case '/' :strcpy(symbol,"DIV");
				   break;
			case '*' :strcpy(symbol,"MUL");
				   break;
		}
		printf("MOV %c , R%d\n",store[i][2],j);
		printf("%s R%d , %c\n",symbol,j,store[i][4]);
		printf("MOV R%d , %c\n",j,store[i][0]);
		j++;
	}
	
	
}
