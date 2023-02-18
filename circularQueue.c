#include <stdio.h>

#define maxSize 20

int queue[maxSize];
int size, f = -1, r = -1;

void enqueue();
void display();
void dequeue();
void peek();

void main()
{

    int choice;
    printf("Enter the size of the circular queue you want to create: ");
    scanf("%d", &size);
    printf("\n*************Circular Queue Using Array*************");

    do
    {

        printf("\n\t 0.Exit");
        printf("\n\t 1.Enqueue");
        printf("\n\t 2.Dequeue");
        printf("\n\t 3.Display");
        printf("\n\t 4. Peek\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("\n *********Exiting**********\n");
            break;

        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        default:
            printf("\n Enter a valid option\n");
        }

    } while (choice != 0);
}

void enqueue()
{

    int data;
    if (f == -1 && r == -1)
    {
        f = r = 0;
        printf("\nEnter value: ");
        scanf("%d", &data);
        queue[r] = data;
    }
    else if (f == (r + 1) % size)
    {
        printf("\nQueue is full");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &data);
        r = (r + 1) % size;
        queue[r] = data;
    }
}

void dequeue()
{

    if (f == -1 && r == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {

        printf("Deleted Element is [%d] :", queue[f]);

        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
            f = (f + 1) % size;
    }
}

void peek()
{
    printf("\nElement at front of the queue is: %d", queue[f]);
}

void display()
{
    int i = f;
    if (f == -1 && r == -1)
        printf("Queue is empty");
    else
    {
        printf("Circular queue elements are: \n");
        while (i != r)
        {
            printf("%d\t", queue[i]);
            i = (i + 1) % size;
        }
        printf("%d\r", queue[r]);
    }
}