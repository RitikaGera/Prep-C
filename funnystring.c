#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int test;
    scanf("%d",&test);
    char in[10000];
    char rev[10000];
    int k=0,count=0;
    for(int i=0;i<test;i++)
    {
	count=0;
	scanf("%s",in);
	int len=strlen(in);
	
	for(int j=0;j<len;j++)
	{
		rev[j]=in[len-j-1];

	}
	rev[len]='\0';
	
	for(int m=1;m<len;m++)
	{
		if(abs((in[m])-(in[m-1]))==abs((rev[m])-(rev[m-1])))
			count++;
	}
	if(count==len-1)
		printf("Funny\n");
	else
		printf("Not Funny\n");
	
    }

    
    return 0;
}
/*
Not Funny
Funny
Funny
Funny
Funny
Funny
Not Funny
Funny
Funny
Funny
*/
