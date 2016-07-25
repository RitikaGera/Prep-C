#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int b[n];
	int count=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	
	
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
		{
			
        		if(a[i]==b[j])
			{
				count++;
				//printf("%d 	%d",b[j],count);
				b[j]=-1;
				break;
				
			}			
		}
	}
	if(count==n)
		printf("%d",n-1);
	else
		printf("%d",count+1);
}
