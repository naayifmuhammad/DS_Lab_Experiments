#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
};

struct node *temp = NULL, *head = NULL;

void Display();
void InsertAtEnd();
void InsertAtBeginning();
void InsertAtPosition();
void DeleteAtEnd();
void DeleteAtBeginning();
void DeleteAtPosition();
void Search();

void main()
{
    int choice;
    printf("\n*************Singly Linked List Operations*************");
    do
    {

        printf("\n\n\t 0.Exit");
        printf("\n\t 1.Insert At Begining");
        printf("\n\t 2.Insert At End");
        printf("\n\t 3.Insert At Particular Position");
        printf("\n\t 4.Delete At Begining");
        printf("\n\t 5.Delete At End");
        printf("\n\t 6.Delete At Particular Position");
        printf("\n\t 7.Search");
        printf("\n\t 8.Display\n");

        scanf("%d", &choice);

        switch (choice)
        {

        case 0:
            printf("\n *********Exiting**********");
            break;

        case 1:
            InsertAtBeginning();
            break;
        case 2:
            InsertAtEnd();
            break;
        case 3:
            InsertAtPosition();
            break;
        case 4:
            DeleteAtBeginning();
            break;
        case 5:
            DeleteAtEnd();
            break;
        case 6:
            DeleteAtPosition();
            break;

        case 7:
            Search();
            break;
        case 8:
            Display();
            break;

        default:
            printf("\n Enter a valid operation: ");
        }
    } while (choice != 0);
}

void DeleteAtEnd()
{
    struct node *ptr;

    if (head == NULL)
        printf("Linked list is Empty");
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
        printf("\n%d is Deleted ", temp->data);
        free(temp);
    }
}

void DeleteAtBeginning()
{

    if (head == NULL)
        printf("Linked list is Empty");
    else
    {

        temp = head;
        printf("\n%d is Deleted ", temp->data);
        head = temp->next;
        free(temp);
    }
}

void DeleteAtPosition()
{

    int pos, i = 1;
    struct node *ptr;

    if (head == NULL)
        printf("Linked list is Empty");
    else
    {
        printf("\n Enter the position: ");
        scanf("%d", &pos);
        if (pos == 1)
        {
            DeleteAtBeginning();
            return;
        }
        temp = head;

        while (i < pos)
        {
            ptr = temp;
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            DeleteAtEnd();
            return;
        }
        ptr->next = temp->next;
        printf("\n%d is Deleted ", temp->data);

        free(temp);
    }
}

void InsertAtPosition()
{

    struct node *newnode;
    int pos, i = 1;
    printf("\n Enter the position");
    scanf("%d", &pos);
    if (pos == 1 || head == NULL)
    {
        InsertAtBeginning();
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the data you want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void InsertAtEnd()
{
    if (head == NULL)
    {
        InsertAtBeginning();
        return;
    }
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data to insert at the end of list: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void InsertAtBeginning()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void Display()
{

    printf("\n******The List data****\n");

    temp = head;

    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
void Search()
{
    int key, flag = 0, pos = 1;
    printf("Enter the key value to search for: ");
    scanf("%d", &key);
    temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (flag == 1)
    {
        printf("The key value is found in linked list at position %d", pos);
    }
    else
    {
        printf("The key value is not found in the linked list");
    }
}
