#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>
			
char stack[20];
int top=-1;

void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
 
int precedence(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

void main()
{
	char exp[20],post[20];
	printf("Enter the Expression : ");
	scanf("%s",exp);
    int j=0,len=0,f=0;
    int count=0;
    while(exp[j]!='\0')
    {
        if(exp[j]=='(')
        {
            count++;
            len++;
            f=0;
        }
        if(exp[j]==')' && count!=0)
        {
            count--;
            len++;
            f=1;
        }
        else if(f==1)
        {
            count--;
        }
        j++;    
    }
    if(count!=0)
    {
        printf("Improper Brackets, try again\n");
        exit(0);
    }
    if(len==j)
    {
        printf("Enter Valid Expression\n");
    }
	int i=0;
	char x;
	while(exp[i]!='\0')
	{
    	if(isalnum(exp[i]))
    	{
    		printf("%c",exp[i]);
    		post[i]=exp[i];
    	}
    	else if(exp[i] == '(')
    	{
            push(exp[i]);
    	}
    	else if(exp[i] == ')')
    	{
            while((x = pop()) != '(')
            {
                printf("%c", x);
            }
    	}
    	else
    	{
            while(precedence(stack[top]) >= precedence(exp[i]))
    	    {        	        
    	       printf("%c",pop());
    	    }
            push(exp[i]);
    	}
    	i++;
    }
	while(top != -1)
	{
    	printf("%c",pop());
	}
    	
}
