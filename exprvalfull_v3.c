#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
void push(int);
int pop();
void intopost(int);
int eval(int);
char infix[20];
char postfix[20];
int stack[30];
int top=-1;
int isEmpty();
int priority(char);
int main(){
	int result=0;
	int top=-1;
	int x=0;

	printf("Enter the expression to be evaluated");
	scanf("%s",infix);
	
	printf("enter the value of variable");
	scanf("%d",&x);

	intopost(x);
	result=eval(x);
	printf("%d",result);
}

void intopost(int x){
int i,p=0;
char next,symbol;
int flag=0;
for(int i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];		
		int no_dig=0;
		int rem=0;
		switch(symbol)
		{
			case '(' :
					push(symbol);
					break;
			case ')':
					while((next=pop())!='(')
						postfix[p++]=next;
					break;
			case '+' :
			case '-' :
			case '*' :
			case '/' :
			case '^' :
				while((!isEmpty()) && priority(stack[top])>=priority(symbol))
					postfix[p++]=pop();
				push(symbol);
				break;
			case 'x' :
			/*	while(x!=0)
				{
					rem=(rem*10)+x%10;
					x=x/10;
					
				}
				while(rem!=0)
				{
					x=rem%10;
					postfix[p++]=x+'0';
					rem=rem/10;
				}
*/
				postfix[p++]='x';
				//printf("%d%c",x,x+'0');
				
				
				break;
			default :
				//if(infix[i+1]
				postfix[p++]=symbol;
		}
	}
while(!isEmpty())
	{
	postfix[p++]=pop();
	}
postfix[p]='\0';
printf("%s \n",postfix);
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void push(int data)
{
	
	stack[++top]=data;
}

int pop()
{
	return stack[top--];
}

int priority(char symbol)
{

switch(symbol)
{
	case '(' : return 1;
	case '+' : return 2;
	case '-' : return 2;
	case '*' : return 3;
	case '/' : return 3;
	case '^' : return 4;
	default  : return 1;
}
}

int eval(int x)
{
	int temp;
	for(int i=0;i<strlen(postfix);)
	{
		if(isdigit(postfix[i]))
			{
				int val=postfix[i]-'0';
				
				while(isdigit(postfix[++i]))
				{	
					val=val*10+postfix[i]-'0';
					
				}
				
				push(val);
				
				
			}
		else if(postfix[i]=='x')
		{
			push(x);
			i++;
		}
		
		else
		{
			
			int a=pop();
			int b=pop();
			printf("popped charactere%d   %d\n",a,b);
			switch(postfix[i])
			{
				case '+' : temp=b+a; break;
				case '-' : temp=b-a; break;
				case '*' : temp=b*a; break;
				case '/' : temp=b/a; break;
				case '^' : temp=pow(b,a);break;
			}
			push(temp);
			i++;
			//printf("pushed on stack is%d\n",temp);
		}
	}	
int result=pop();
return result;
}
