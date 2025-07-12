#include<stdio.h>
#include<stdlib.h>

#define FOUND 1
#define NOT_FOUND 0

typedef struct node
{
    int INFO;
    struct node *NEXT;

} NODE;

NODE *FIRST,*LAST;

void insert(int value)
{
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->INFO = value;

    if (FIRST==NULL)
    {
        FIRST = LAST = new_node;
        FIRST->NEXT = LAST;
        LAST->NEXT = FIRST;
    }

    else
    {
        LAST->NEXT = new_node;
        LAST = new_node;
        LAST->NEXT= FIRST;
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
        free(ptr);
        printf("%d Deleted!\n",value);
        LAST->NEXT = FIRST;
    }
    else
    {
        NODE *curr_ptr, *prev_ptr;
        curr_ptr = prev_ptr = FIRST;

        int FLAG = NOT_FOUND;
        while(curr_ptr!=LAST)
        {
            if(curr_ptr->INFO != value)
            {
                prev_ptr = curr_ptr;
                curr_ptr = curr_ptr->NEXT;
            }
            else
            {
                FLAG = FOUND;
                prev_ptr->NEXT = curr_ptr->NEXT;
                free(curr_ptr);
                break;
            }
        }
        if(!FLAG && LAST->INFO==value)
        {
            prev_ptr->NEXT = FIRST;
            free(LAST);
            LAST = prev_ptr;
            FLAG =FOUND;
        }

        if(FLAG) printf("%d Deleted!\n",value);
        else printf("%d Not Found to delete!\n",value);
    }
}

void search(int value)
{

    if(FIRST == NULL)
        printf("Empty List!\n");
    else
    {
        NODE *curr_ptr = FIRST;
        int FLAG = NOT_FOUND;

        while(curr_ptr!=LAST)
        {
            if(curr_ptr->INFO != value)
                curr_ptr = curr_ptr->NEXT;
            else
            {
                FLAG = FOUND;
                break;
            }
        }
        if(LAST->INFO==value) FLAG = FOUND;

        if(FLAG) printf("%d Found!\n",value);
        else printf("%d Not Found!\n",value);
    }
}

void print()
{
    if(FIRST == NULL)
        printf("Nothing to Print!");
    else
    {
        printf("Linked List: ");
        NODE *curr_ptr = FIRST;
        while(curr_ptr!=LAST)
        {
            printf("%d ",curr_ptr->INFO);
            curr_ptr = curr_ptr->NEXT;
        }
        printf("%d ",LAST->INFO);
    }
    printf("\n");
}

void main()
{
    print();
    delete(2023);
    search(1971);
    insert(5);
    insert(15);
    print();
    insert(56);
    search(15);
    insert(25);
    print();
    search(1952);
    delete(15);
    print();
    search(15);
    delete(404);
    print();
    insert(100);
    print();
    search(100);
    print();
    delete(5);
    print();
    delete(100);
    print();
}
