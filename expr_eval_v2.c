#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include <string.h>
double evaluate(char*, char, int, int);

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

	double result = evaluate(input , variable, x, length);
	printf("%f",result);//here
}

double evaluate(char input[], char variable, int x, int length)
{
	double res = (input[0] == variable) ? x : input[0] - '0';
	
	for(int i = 1; i < length; i = i + 2)	
	{	
		if(input[i] == '+')
		{
			if( input[i+1] == variable )
				res += x;
			else
				res += input[i+1] - '0';
		}
		else if(input[i] == '-')
		{
			if( input[i+1] == variable )
				res -= x;
			else
				res -= input[i+1] - '0';
		}
		else if(input[i] == '*')
		{
			if( input[i+1] == variable )
				res *= x;
			else
				res *= input[i+1] - '0';
		}
		else if(input[i] == '/')
		{
			if( input[i+1] == variable )
				res /= x;
			else		
				res /= input[i+1] - '0';
		}
		else if(input[i] == '^')
		{
			if( input[i+1] == variable )
				res = pow(res, x);
			else	
				res = pow(res, input[i+1] - '0');
		}
	}
	
	return res;
}


