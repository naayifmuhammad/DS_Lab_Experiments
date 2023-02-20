#include <stdio.h>

#define max 20

int top = -1, size, stack[max] = {0};

void push(int);
int pop();
int topElement();
void display();
int isFull();

void main()
{
    int ch, data;
    printf("Enter the length of your desired stack: ");
    scanf("%d", &size);

    printf("Enter the operation you want to perform: \n");
    do
    {
        printf("\n1.Push 2.Pop 3.Display 4.Top: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            return;
            break;
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("Popped: [%d]", data);
            break;
        case 3:
            display();
            break;
        case 4:
            data = topElement();
            printf("Top element is: [%d]", data);
            break;
        default:
            printf("Please enter a valid operation: ");
        }
    } while (ch != 0);
}

void push(int data)
{
    if (!isFull())
    {
        stack[++top] = data;
    }
    else
        printf("Stack overflow Insertion not possible: \n");
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is underflow");
        return 0;
    }
    return stack[top--];
}

int topElement()
{
    if (top == -1)
    {
        printf("Stack is empty");
        return;
    }
    return stack[top];
}

void display()
{
    int i = top;
    if (top != -1)
    {
        printf("Stack elements are: \n");
        while (i >= 0)
        {
            printf(" %d ", stack[i--]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack is empty: display not possible: ");
    }
}

int isFull()
{
    if (top >= size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
