#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int INFO;
    struct node *NEXT;

} NODE;

NODE *FRONT,*REAR;

void insert(int value)
{
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->INFO = value;
    new_node->NEXT = NULL;

    if (FRONT==NULL)
        FRONT = REAR = new_node;
    else
    {
        REAR->NEXT = new_node;
        REAR = new_node;
    }
    if(new_node!=NULL) printf("Inserted Element: %d\n",value);
    else printf("Insertion Failed!!!\n");

}

void delete()
{
    if(FRONT == NULL)
        printf("Empty Queue!\n");
    else
    {
        NODE* ptr = FRONT->NEXT;
        printf("Deleted Element: %d\n",FRONT->INFO);
        free(FRONT);
        FRONT = ptr;
    }
}

void front()
{

    if(FRONT == NULL)
        printf("Empty Queue!\n");
    else
        printf("Front Element: %d\n",FRONT->INFO);
}

void rear()
{

    if(REAR == NULL)
        printf("Empty Queue!\n");
    else
        printf("Rear Element: %d\n",REAR->INFO);
}

void print()
{
    printf("Queue Front:<| ");
    NODE* curr_ptr = FRONT;
    while(curr_ptr!=NULL)
    {
        printf("%d ",curr_ptr->INFO);
        curr_ptr = curr_ptr->NEXT;
    }
    printf("|>:Queue Rear\n");
}
void main()
{
    insert(12);
    insert(15);
    insert(5);
    print();
    front();
    rear();
    delete();
    print();
    rear();
    insert(7);
    print();
    front();
    delete();
    print();
    rear();
    insert(52);
    delete();
    insert(101);
    print();
}


