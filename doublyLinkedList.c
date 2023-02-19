#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};

struct node *temp = NULL, *head = NULL, *latest = NULL, *newnode;

void Display();
void InsertAtEnd();
void InsertAtBeginning();
void InsertAtPosition();
void DeleteAtEnd();
void DeleteAtBeginning();
void DeleteAtPosition();
void Search();
void readNodeData();
int isEmpty();

void main()
{
    int choice;
    printf("\n*************Doubly Linked List Operations*************");
    do
    {

        printf("\n0.Exit");
        printf("  1.Insert At Beginning");
        printf("  2.Insert At End");
        printf("  3.Insert At Position");
        printf("  4.Delete At Beginning");
        printf("  5.Delete At End");
        printf("  6.Delete At Position");
        printf("  7.Search");
        printf("  8.Display\n\n");

        scanf("%d", &choice);

        switch (choice)
        {

        case 0:
            printf("\n *********Exiting**********");
            break;

        case 1:
            readNodeData();
            InsertAtBeginning();
            break;
        case 2:
            readNodeData();
            InsertAtEnd();
            break;
        case 3:
            readNodeData();
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

    if (isEmpty())
        return;
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

    struct node *tmp;

    if (isEmpty())
        return;
    else
    {

        tmp = head;
        printf("\n%d is Deleted ", tmp->data);
        head = tmp->next;
        tmp->prev = NULL;
        free(tmp);
    }
}

void DeleteAtPosition()
{

    int pos, i = 1;
    struct node *ptr;

    if (isEmpty())
        return;
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
            if (temp == NULL)
            {
                printf("Deletion at that position is not possible");
                return;
            }
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
        ptr = temp->next;
        ptr->prev = temp->prev;
        printf("\n%d is Deleted ", temp->data);

        free(temp);
    }
}

void InsertAtPosition()
{
    int pos, i = 1;
    printf("\n Enter the position for insertion: ");
    scanf("%d", &pos);
    if (pos == 1 || head == NULL)
    {
        InsertAtBeginning();
        return;
    }
    temp = head;
    while (i < pos - 1)
    {
        if (temp->next == NULL)
        {
            printf("Insertion at that position is not possible: Inserting at end  of list instead: ");
            InsertAtEnd();
            return;
        }
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
}

void InsertAtEnd()
{
    if (head == NULL)
    {
        InsertAtBeginning();
        return;
    }
    latest->next = newnode;
    newnode->prev = latest;
    latest = latest->next;
}

void InsertAtBeginning()
{
    if (head == NULL)
    {
        head = latest = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void Display()
{
    if (isEmpty())
        return;
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
    if (isEmpty())
        return;
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
        printf("The key value not found in the linked list");
    }
}

void readNodeData()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data for new node: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode->prev = NULL;
}
int isEmpty()
{
    if (head == NULL)
    {
        printf("Linked list is empty");
        return (1);
    }
    else
        return (0);
}