#include<stdio.h>
#include<ctype.h>
#define max 20
int stack[max];
int top=-1;
void push(int value)
{
    top++;
    stack[top]=value;
}
int pop()
{
    return stack[top--];
}
int eval(char *exp)
{
    int i,a,b;
    for(i=0;exp[i]!='\0';i++)
    {
        if(isdigit(exp[i]))
        {
            push(exp[i]-'0');
        }
        else
        {
            b=pop();
            a=pop();
            switch(exp[i])
            {
                case '+': push(a+b);break;
                case '-': push(a-b);break;
                case '*': push(a*b);break;
                case '/':push(a/b);break;
            }
        }
        
    }
    return pop();
}
int main(){
    char exp[max];
    printf("Expression: ");
    scanf("%s",exp);
    int result= eval(exp);
    printf("\nResult=%d",result);
}
