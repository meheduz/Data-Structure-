#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int INFO;
    struct node *NEXT;

} NODE;

NODE *TOP;

void push(int value)
{
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->INFO = value;
    new_node->NEXT = NULL;

    if (TOP==NULL)
        TOP = new_node;
    else
    {
        new_node->NEXT = TOP;
        TOP = new_node;
    }
    if(new_node!=NULL) printf("Pushed Element: %d\n",value);
    else printf("Push Failed!!!\n");

}

void pop()
{
    if(TOP == NULL)
        printf("Empty Stack!\n");
    else
    {
        NODE* ptr = TOP->NEXT;
        printf("Popped Element: %d\n",TOP->INFO);
        free(TOP);
        TOP = ptr;
    }
}

void top()
{

    if(TOP == NULL)
        printf("Empty Stack!\n");
    else
        printf("Top Element: %d\n",TOP->INFO);
}

void print()
{
    printf("---Stack Top>\n");
    NODE* curr_ptr = TOP;
    while(curr_ptr!=NULL)
    {
        printf("%d\n",curr_ptr->INFO);
        curr_ptr = curr_ptr->NEXT;
    }
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


