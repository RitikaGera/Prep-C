#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct den_frq{
	int deno;
	int fr;
}arr[10];

int cmpfunc (const void * a, const void * b)
{
   struct den_frq *s1=(struct den_frq *)a;
   struct den_frq *s2=(struct den_frq *)b;
   return ( *(int*)s2 - *(int*)s1 );//for decreasing order, it returns1 when b>a
}



void res(struct den_frq[],int,int);
int main()
{
	
	int den[50];
	int frq[50];
	int i=0,j=0;
	
	printf("enter the amount");
	int amount=0;
	scanf("%d",&amount);

	char input[50];
	printf("enter the denominations and their frequency");
	scanf("%s",input);
	
	char delims[]={',',':'};
	char *token;
	token=strtok(input,delims);
	//printf("%s",token);
	
	int var=0;
	int k=0;
	while(token!=NULL)
	{
		sscanf (token, "%d", &var);
		if(k%2==0)
    			den[i++] = var;
		else
			frq[j++]=var;
		k++;
		token = strtok(NULL, delims);
	}
	int length=j;
	for(int i=0;i<length;i++)
	{
		arr[i].deno=den[i];
		arr[i].fr=frq[i];
	}
	
	
	res(arr,length,amount);
}
//INTENDED TO SHOW HOW YOU CAN SEPARATE INTEGERS FROM A COMMA AND OTHER DELIMS SEPARATED LIST

void res(struct den_frq arr[],int length, int amount)
{
	qsort(arr,length,sizeof(struct den_frq),cmpfunc);
	
	int x=0;
	int no=0;
	int count=0;
	for(int i=0;i<length&&(arr[i].deno!='\0'||amount!=0);i++)//check without deno
	{
			count=0;
			while(arr[i].fr!=0&&amount>=arr[i].deno)
			{
				
				x=amount-arr[i].deno;
				if(x>=0)
				{
					count++;
					arr[i].fr--;
					amount=x;
				}
				
			}
			printf("%d:%d,",arr[i].deno,count);

		
		
	}

} 



