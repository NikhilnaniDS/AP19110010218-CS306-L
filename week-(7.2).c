#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int i=0,top=0;
char a[20],ip[20];

void push(char b)
{
	if (top>=20)
		printf("stack Overflow");
	else
		a[top++]=b;
}

void pop(void)
{
	if(top<0)
		printf("stack underflow");
	else
		top--;
}

void error(void)
{
    printf("\nString is invalid\n");
    getch();
    exit(0);
}

int main()
{
    int num;
    
    printf("Enter the string to be parsed:\n");
    scanf("%s",ip);
    num=strlen(ip);
    ip[num]='$';
    ip[num+1]='\0';
    push('$');
    push('E');
    printf("\nproductions\t\t\tcharacter match\n");
    while(ip[i]!='\0')
    { 
        if(ip[i]=='$' && a[top-1]=='$')
        {
            printf("\n\n Successfully parsed \n");
            return(1);
            
        }
        else if(ip[i]==a[top-1])
    	{
    	    printf("\t\tmatch of %c occured ",ip[i]);
    	    i++;
    	    pop();
    	}
    	else
    	{
    		if(a[top-1]=='E' && ip[i]=='d')
    		{
    		    printf("\nE ->TA\t\t");
    		    pop();
    		    push('A');
    		    push('T');
    		}
    		else if(a[top-1]=='E' && ip[i]=='(')
    		{
    		    printf("\nE ->TA\t\t");
    			pop();
    			push('A');
    			push('T');
    		}
    		else if(a[top-1]=='A' && ip[i]=='+')
    		{
    		    printf("\nA -> +TA\t");
    		    pop();
    		    push('A');
    		    push('T');
    		    push('+');
    		}
    		else if(a[top-1]=='A' && ip[i]==')')
    		{
    		    printf("\nA -> epsilon\t");
    		    pop();
    		}
    		else if(a[top-1]=='A' && ip[i]=='$')
    		{
    		    printf("\nA -> epsilon\t");
    		    pop();
    		}
    		else if(a[top-1]=='T' && ip[i]=='d')
    		{
    		    printf("\nT ->FB\t\t");
    		    pop();
    		    push('B');
    		    push('F');
    		}
    		else if(a[top-1]=='T' && ip[i]=='(')
    		{
    		    printf("\nT ->FB\t\t");
    			pop();
    			push('B');
    			push('F');
    		}
    		else if(a[top-1]=='B' && ip[i]=='+')
    		{
    		    printf("\nB -> epsilon\t");
    		    pop();
    		}
    		else if(a[top-1]=='B' && ip[i]=='*')
    		{
    		    printf("\nB -> *FB\t");
    		    pop();
    		    push('B');
    		    push('F');
    		    push('*');
    		}
    		else if(a[top-1]=='B' && ip[i]==')')
    		{
    		    printf("\nB -> epsilon\t");
    		    pop();
    		}
    		else if(a[top-1]=='B' && ip[i]=='$')
    		{
    		    printf("\nB -> epsilon\t");
    		    pop();
    		}
    		else if(a[top-1]=='F' && ip[i]=='d')
    		{
    		    printf("\nF -> d\t\t");
    		    pop();
    		    push('d');
    		}
    		else if(a[top-1]=='F' && ip[i]=='(')
    		{
    		    printf("\nF -> (E)\t");
    		    pop();
    		    push(')');
    		    push('E');
    		    push('(');
    		}
    		else
    		{
    		    error();
    		}
    	}
     }
}
