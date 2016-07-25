#include<stdio.h>
#include<stdlib.h>
char n1[102];//necessary 101
char n2[102];//necessary 101
char carry[102];
char res[102];

void add(char*,char*);

void add(char n1[],char n2[])
{
printf("Enter number 1 ");
scanf("%s",n1);
printf("Enter number 2 ");
scanf("%s",n2);
int len1=printf("%s",n1);
int len2=printf("+%s=",n2)-2;

int ptr1=len1-1;
int ptr2=len2-1;

int lenres=(len1>len2?len1:len2)+1;
int i=lenres-1;
res[lenres]='\0';
for(int i=lenres-1;i>=0;i--)
{
	int resi=(n1[ptr1]-'0')+(n2[ptr2]-'0')+(carry[i]-'0');
	res[i]=(resi%10)+'0';
	//printf("%d %d %d \n",len1,len2,resi);
	//printf("%c",res[i]);
	carry[i-1]=(resi/10)+'0';
	if(ptr1>0)
		ptr1--;
	else
		ptr1=101;
	if(ptr2>0)
		ptr2--;
	else
		ptr2=101;
	
}

	
}
int main(){
for(int i=0;i<102;i++)
{
	n1[i]='0';
	n2[i]='0';
	carry[i]='0';
	res[i]='0';
}
add(n1,n2);
printf("%s",res);


}
