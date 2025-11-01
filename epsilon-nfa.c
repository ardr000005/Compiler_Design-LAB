#include<stdio.h>
#include<string.h>

char input[10][10],output[10][10];
int n,t,o_p=0;

void add_out(char temp[10])
{
	for(int i=0;i<o_p;i++)
	{
		if(strcmp(output[i],temp)==0)
		return;
	}
	strcpy(output[o_p],temp);
	o_p++;
}

void check_epsilon()
{
	char state[2][2],temp[10];
	for(int i=0;i<t;i++)
	{
		state[0][0]=input[i][0];
		state[0][1]=input[i][1];
		
		snprintf(temp, sizeof(temp), "%c%c", state[0][0], state[0][1]);
		add_out(temp);
		
		for(int j=0;j<t;j++)
		{
			if(state[0][0]==input[j][0] && state[0][1]==input[j][1] && input[j][2] == 'e')
			{
				state[0][0]=input[j][3];
				state[0][1]=input[j][4];
				snprintf(temp, sizeof(temp), "%c%c", state[0][0], state[0][1]);
				add_out(temp);
			}
		}
		printf("\nEpsilon Closure of %c%c is { ",input[i][0],input[i][1]);
		for(int j=0;j<o_p;j++)
		{
			printf(" %s ,",output[j]);
		}
		printf(" } \n");
		o_p=0;
		
	}
}

void main()
{
	printf("Enter the no of transactions\n");
	scanf("%d",&t);
	printf("Enter the no of Q states\n");
	scanf("%d",&n);
	
	for(int i=0;i<t;i++)
	{
		scanf("%s",input[i]);
	}
	
	check_epsilon();
}
