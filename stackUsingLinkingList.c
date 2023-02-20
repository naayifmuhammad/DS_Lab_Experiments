#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
};

struct node *temp, *head;

void push();
void pop();
void top();
void display();

void main()
{

    int choice;

    printf("\n***********Stack Using Linked************");

    do
    {

        printf("\n 0.Exit");
        printf(" 1.Push");
        printf(" 2.Pop");
        printf(" 3.Top");
        printf(" 4.Display\n\n");

        scanf("%d", &choice);

        switch (choice)
        {

        case 0:
            printf("\n *********Exiting**********");
            break;
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            top();
            break;

        case 4:
            display();
            break;

        default:
            printf("\n Enter a valid operation");
        }

        temp = head;

    } while (choice != 0);
}

void pop()
{
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        printf("Popped element : [%d]", head->data);
        temp = head;
        head = head->next;
        free(temp);
    }
}

void top()
{

    struct node *tmp;

    if (head == NULL)
        printf("Stack Is Empty");
    else
    {
        printf("top element is : [%d]", head->data);
    }
}

void push()
{

    struct node *newnode;
    int data;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\n Enter the data you want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void display()
{

    if (head == NULL)
        printf("Stack is empty");
    else
    {
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}
