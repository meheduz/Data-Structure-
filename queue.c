#include<stdio.h>
#define CAPACITY 100

int QUEUE[CAPACITY];
int FRONT = -1;
int REAR = -1;

void insert(int value)
{
    if(FRONT==-1)
    {
        FRONT = REAR = 0;
        QUEUE[REAR] = value;
        printf("Inserted Element: %d\n",value);
    }
    else if(REAR+1<CAPACITY)
    {
        REAR++;
        QUEUE[REAR] = value;
        printf("Inserted Element: %d\n",value);
    }
    else printf("Full Queue!\n");
}

void delete()
{
    if(FRONT==-1 && REAR == -1)
        printf("Empty Queue!\n");
    else if(FRONT>=0 & FRONT == REAR)
    {
        printf("Deleted Element: %d\n",QUEUE[FRONT]);
        FRONT = REAR = -1;
    }
    else printf("Deleted Element: %d\n",QUEUE[FRONT++]);
}

void front()
{
    if(FRONT>=0)
        printf("Front Element: %d\n",QUEUE[FRONT]);
    else printf("Empty Queue!\n");
}
void rear()
{
    if(REAR<CAPACITY && REAR >=0)
        printf("Rear Element: %d\n",QUEUE[REAR]);
    else printf("Empty Queue!\n");
}

void print()
{
    printf("Queue Front:<| ");
    for(int i=FRONT; i<=REAR; i++) printf("%d ",QUEUE[i]);
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


