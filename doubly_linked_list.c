#include<stdio.h>
#include<stdlib.h>

#define FOUND 1
#define NOT_FOUND 0

typedef struct node
{
    int INFO;
    struct node *PREVIOUS;
    struct node *NEXT;

} NODE;

NODE *FIRST,*LAST;

void insert(int value)
{
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->INFO = value;
    new_node->PREVIOUS = new_node->NEXT = NULL;

    if (FIRST==NULL)
    {
        FIRST = LAST = new_node;
    }

    else
    {
        LAST->NEXT = new_node;
        new_node->PREVIOUS = LAST;
        LAST = new_node;
    }
    if(new_node!=NULL) printf("%d Inserted!\n",value);
    else printf("Insertion Failed!!!\n");

}

void delete(int value)
{
    if(FIRST == NULL)
        printf("Empty List!\n");
    else if(FIRST->INFO == value)
    {
        NODE *ptr = FIRST;
        FIRST = FIRST->NEXT;
        FIRST->PREVIOUS = NULL;
        free(ptr);
        printf("%d Deleted!\n",value);

    }
    else if(LAST->INFO == value)
    {
        NODE *ptr = LAST;
        LAST = LAST->PREVIOUS;
        LAST->NEXT = NULL;
        free(ptr);
        printf("%d Deleted!\n",value);
    }
    else
    {
        NODE *curr_ptr = FIRST;

        int FLAG = NOT_FOUND;
        while(curr_ptr!=NULL)
        {
            if(curr_ptr->INFO != value)
                curr_ptr = curr_ptr->NEXT;
            else
            {
                FLAG = FOUND;
                (curr_ptr->PREVIOUS)->NEXT = curr_ptr->NEXT;
                (curr_ptr->NEXT)->PREVIOUS = curr_ptr->PREVIOUS;
                free(curr_ptr);
                break;
            }
        }

        if(FLAG) printf("%d Deleted!\n",value);
        else printf("%d Not Found to delete!\n",value);
    }
}

void search_forward(int value)
{

    if(FIRST == NULL)
        printf("Empty List!\n");
    else
    {
        NODE *curr_ptr = FIRST;
        int FLAG = NOT_FOUND;

        while(curr_ptr!=NULL)
        {
            if(curr_ptr->INFO != value)
                curr_ptr = curr_ptr->NEXT;
            else
            {
                FLAG = FOUND;
                break;
            }
        }

        if(FLAG) printf("%d Found!\n",value);
        else printf("%d Not Found!\n",value);
    }
}

void search_backward(int value)
{

    if(FIRST == NULL)
        printf("Empty List!\n");
    else
    {
        NODE *curr_ptr = LAST;
        int FLAG = NOT_FOUND;

        while(curr_ptr!=NULL)
        {
            if(curr_ptr->INFO != value)
                curr_ptr = curr_ptr->PREVIOUS;
            else
            {
                FLAG = FOUND;
                break;
            }
        }

        if(FLAG) printf("%d Found!\n",value);
        else printf("%d Not Found!\n",value);
    }
}

void print_forward()
{
    if(FIRST == NULL)
        printf("Nothing to Print!");
    else
    {
        printf("Linked List: ");
        NODE *curr_ptr = FIRST;
        while(curr_ptr!=NULL)
        {
            printf("%d ",curr_ptr->INFO);
            curr_ptr = curr_ptr->NEXT;
        }
    }
    printf("\n");
}

void print_backward()
{
    if(LAST == NULL)
        printf("Nothing to Print!");
    else
    {
        printf("Linked List: ");
        NODE *curr_ptr = LAST;
        while(curr_ptr!=NULL)
        {
            printf("%d ",curr_ptr->INFO);
            curr_ptr = curr_ptr->PREVIOUS;
        }
    }
    //printf("DEBUG 3....\n");
    printf("\n");
}

void main()
{
    print_forward();
    print_backward();
    delete(2023);
    search_forward(1971);
    insert(5);
    insert(15);
    print_forward();
    print_backward();
    insert(56);
    search_backward(15);
    insert(25);
    print_forward();
    print_backward();
    search_forward(1952);
    delete(15);
    print_forward();
    print_backward();
    search_backward(15);
    delete(404);
    print_forward();
    print_backward();
    insert(100);
    print_forward();
    print_backward();
    search_forward(100);
    print_forward();
    print_backward();
    delete(5);
    print_forward();
    print_backward();
    delete(100);
    print_forward();
    print_backward();
    search_backward(25);
}
