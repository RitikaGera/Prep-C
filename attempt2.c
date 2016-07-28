#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include <string.h>
int evaluate(char*, char, int, int);

int main(){
	char input[100];
	char variable;
	int x;
	printf("enter the expression to evaluate ");
	scanf("%s", input);
	int length = strlen(input);
	for (int i = 0; i < length; ++i)
	{
		if ( !isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '/' && input[i] != '*' && input[i] != '^' )
		{
			variable = input[i];
			printf("enter the value of %c", variable);
			scanf("%d", &x);
			break;
		}
	}	

	int result = evaluate(input , variable, x, length);
	printf("%d",result);//here
}

int evaluate(char input[], char variable, int x, int length)
{
	char a;
	for(i=0;i<length;)
	{
		switch(input[i])
		{
			case '(':
				while(input[i]!=')')
				{
					if(isalpha(input[i+1]))
					{
						int k=x;
						i++;
						break;
					}
					else if(isdigit(input[i+1]))
					{
						int k=input[i+1]-'0';
						i++;
						while(isdigit(input[i+1]))
						{
							k=k*10+input[i+1];
							i++;
						}
						i++;
					}
					else
					{	
						a=input[i];
						i++;
					}
					
				}break;
		}
	}	
}
