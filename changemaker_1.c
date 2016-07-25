#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void den(int[],int);

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)b - *(int*)a );//for decreasing order, it returns1 when b>a
}


int main()
{
	/*
	printf("enter the denominations");
	char input[20];
	scanf("%s",input);
	const char delimiter[]=",";
	const char *c=input;
	do
	{
		size_t field_len = strcspn(c, delimiter);
		printf("\"%.*s\"\n", (int)field_len, c);
		c += field_len;
	} while (*c++);

	*/
int amount;
printf("Enter the amount");
scanf("%d",&amount);
int input[]={1000,500,100,50,20,10,1};


qsort(input, 7, sizeof(int), cmpfunc);
input[7]='\0';
den(input,amount);

	
}

void den(int input[],int amount)
{
	int i=0;
	int no=0;
	for(i=0;input[i]!='\0'||amount!=0;i++)
	{
		no=amount/input[i];
		printf("%d : %d,",input[i],no);
		amount=amount%input[i];
	}
}




