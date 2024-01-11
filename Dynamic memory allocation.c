#include<stdio.h>
#include<stdlib.h>
int main()
{
    int*al;
    int n,i;
    printf("Enter the number of elements");
    scanf("%d",&n);
    printf("Enter the number of elements",n);
    al=(int*)malloc(n*sizeof(int));
    if(al==NULL)
    {
        printf("Memory not allocated");
    }
    else
    {
        printf("Memory Allocation successfull!!");
        for(i=0;i<n;i++)
        {
            al[i]=i+1;
        }
        printf("The elements of the array are");
        for(i=0;i<n;i++)
        {
            printf("%d",al[i]);
        }
    }
    return(0);
}
