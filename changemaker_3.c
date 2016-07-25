#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MIN(x, y) (((x) > (y)) ? (y) : (x))
int res(int[],int,int);
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );//for ascending order
}

int main()
{
	
	int den[50];
	int i=0,j=0;
	
	printf("enter the amount");
	int amount=0;
	scanf("%d",&amount);

	printf("enter the number of denominations");
	int n;
	scanf("%d",&n);
	
	printf("enter the denominations");
	for(i=0;i<n;i++)
	{
		scanf("%d",&den[i]);
	
	}
	qsort(den,n, sizeof(int), cmpfunc);

	int result=res(den,amount,n);
	printf("%d",result);
	//DP
}

int res(int den[],int amount,int n)
{
	
	int dp[n][amount+1];
	for(int i=0;i<n;i++)
	{
		dp[i][0]=0;
		for(int j=1;j<=amount;j++)
		{
			if(den[i]>j)
			{
				if(i==0)
				{
					dp[i][j]=0;
				}
				
				else
				{
					dp[i][j]=dp[i-1][j];
				}
			}
			else
			{
				if(i==0)
				{
					dp[i][j]=dp[i][j-den[i]]+1;
				}
				else
					dp[i][j]=MIN(dp[i-1][j],dp[i][j-den[i]]+1);
			}
		}
	}
	return dp[n-1][amount];
}
