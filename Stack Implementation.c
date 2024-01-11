#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int top=-1;
int inp[SIZE];
void push();
void pop();
void display();
int main()
{
    int d;
    while (1)
    {
        printf("Performance operation on the stack");
        printf("N1.Push element\nN2.Pop element\nN3.Display Element");
        printf("\n\n\nEnter Choice 1|2|3|4");
        scanf("%d",&d);
        switch(d)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
        printf("\nInvalid Choice");
        }
    }
}
void push()
{
    int x;
    if(top==SIZE-1)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter the element to be added to the stack :");
        scanf("%d",&x);
        top=top+1;
        inp[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPoped element:%d",inp[top]);
        top=top-1;
    }
}
void display()
{
    if (top==-1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElement present in the stack:");
        for(int i=top;i>=0;i++)
        {
            printf("%d\n",inp[i]);
        }
    }
}
