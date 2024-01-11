#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int front = -1, rear = -1;
int Q[MAX];

void insert(int item)
{
    if (rear == MAX - 1)
    {
        printf("Overflow\n");
        exit(EXIT_FAILURE);
    } else
    {
        if (rear == -1 && front == -1)
        {
            front = rear = 0;
            Q[rear] = item;
        }
    else
        {
            rear = rear + 1;
            Q[rear] = item;
        }
    }
}
int delete ()
{
    if (front == -1 || front > rear)
    {
        return -1;
    }
    else
    {
        return Q[front++];
    }
}
int main()
{
    int n,ele,d;
    do
    {
       printf("1. Insert element\n2. Delete element\n3. Exit\n");
        scanf("%d", &n);

        switch (n)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &ele);
                insert(ele);
                break;

            case 2:
                d = delete();
                if (d == -1)
                {
                    printf("Underflow\n");
                    exit(EXIT_FAILURE);
                }
                printf("The element deleted is: %d\n", d);
                break;
            case 3:
                printf("Exiting the program\n");
                break;
            default:
                printf("Please enter the right choice\n");
        }
    } while (n != 3);
    return 0;
}
