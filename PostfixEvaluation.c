#include<stdio.h>
#include<ctype.h>
			
float stack[20];
int top=-1;

void push(float x)
{
    stack[++top] = x;
}
float pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
void display()
{
	int k;
	for(k=top;k>=0;k--)
	{
 		printf("%f\n",stack[k]);
	}	
}
void main()
{
	char exp[20];
	printf("Enter the Expression : ");
	scanf("%s",exp);
	int i=0,k;
	char x,operator;
	float ans=0;
	float a,b,val;
	while(exp[i]!='\0')
	{
		if(isalnum(exp[i]))
		{
			printf("Enter the value of the variable %c:",exp[i]);
			scanf("%f",&val);
			push(val);
		}
    	else
    	{	
		
	    	b=pop();
			a=pop();
			operator=exp[i];
			if(operator=='+')
			{
				ans=(a+b);
			}
			else if(operator=='-')
			{
				ans=(a-b);
			}
			else if(operator=='*')
			{
				ans=(a*b);
			}
			else if(operator=='/')
			{
				ans=(a/b);
			}
			push(ans);
	    }
	    	i++;
    }
	printf("The value of the expression is : %f",ans); 
    	
}
