#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MIN(x, y) (((x) > (y)) ? (y) : (x))
void res(int[],int[],int,int);
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );//for ascending order
}

int main()
{
	
	int den[50],amount[50];
	int i=0,j=0;
	
	

	//printf("enter the number of denominations");
	int n;
	scanf("%d",&n);

	//printf("enter the number of amounts");
	int m;
	scanf("%d",&m);
	
	//printf("enter the denominations");
	for(i=0;i<n;i++)
	{
		scanf("%d",&den[i]);
	
	}

	//printf("enter the amounts");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&amount[i]);
	}
	qsort(den,n, sizeof(int), cmpfunc);
	
	res(den,amount,n,m);
	//printf("%d",result);
	//DP
}

void res(int den[],int amount[],int n,int m)
{
	
	
	for(int p=0;p<m;p++)
	{
		int dp[n][amount[p]+1];
		for(int i=0;i<n;i++)
		{
			dp[i][0]=0;
			for(int j=1;j<=amount[p];j++)
			{
				if(den[i]>j)
				{
					if(i==0&&j!=0)
					{
						dp[i][j]=99;
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
						if((j-den[i])%den[i]!=0)
							dp[i][j]=99;
						else
							dp[i][j]=dp[i][j-den[i]]+1;
					}
					else
					{	
						dp[i][j]=MIN(dp[i-1][j],dp[i][j-den[i]]+1);
					}
				}
			}
		}
		//printf("%d \n",dp[n-1][amount[p]]);
		
		int r=0;
		int a=n-1;
		int b=amount[p];
		int count=0;
		int k=0;
		while(count<dp[n-1][amount[p]])
		{
			if(a>0 && dp[a][b]!=dp[a-1][b]){
				while(dp[a][b]!=dp[a-1][b])
				{	
					//a=a;
					b=b-den[a];
					k++;
				}
			}
			else if(a>0&&(dp[a][b]==dp[a-1][b]))
			{
				if(k>0)
				{
					if(count==0)
						printf("\n%d:%d", den[a],k);
					else
						printf(",%d:%d", den[a],k);
				}
				count+=k;
				k=0;
				a=a-1;
			}	
			else if(a==0&&dp[a][b]!=0)
			{
				if(count==0)
					printf("\n%d:%d",den[a],dp[a][b]);
				else
					printf(",%d:%d",den[a],dp[a][b]);
				count=count+dp[a][b];
			}
		}

	}
}
