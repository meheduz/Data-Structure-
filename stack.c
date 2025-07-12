#include<stdio.h>
#define CAPACITY 100

int STACK[CAPACITY];
int SP_TOP = -1;

void push(int value)
{
    if(SP_TOP+1<CAPACITY)
    {
        SP_TOP++;
        STACK[SP_TOP] = value;
        printf("Pushed Element: %d\n",value);
    }
    else printf("Full Stack!\n");
}

void pop()
{
    if(SP_TOP>=0)
    {
        printf("Popped Element: %d\n",STACK[SP_TOP]);
        SP_TOP--;
    }
    else printf("Empty Stack!\n");
}

void top()
{
    if(SP_TOP>=0)
        printf("Top Element: %d\n",STACK[SP_TOP]);
    else printf("Empty Stack!\n");
}

void print()
{
    printf("---Stack Top>\n");
    for(int i=SP_TOP; i>=0; i--) printf("%d\n",STACK[i]);
    printf("---Stack Bottom>\n");
}
void main()
{
    push(12);
    push(15);
    push(5);
    print();
    top();
    pop();
    print();
    top();
    push(7);
    print();
    top();
    pop();
    print();
    top();
    push(52);
    push(101);
    print();
}

