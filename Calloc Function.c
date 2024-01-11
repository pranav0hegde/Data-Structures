#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   int  *alloc;
   int n,i;
   printf ("Enter the number of elemnts");
   scanf("%d",&n);
   printf("Entered number of elemnts",n);
   alloc=(int*)calloc(15,sizeof(int));
   if(alloc==NULL)
   {
       printf("Memory not Allocated");
   }
   else
   {
    printf("Memory Allocation successful");
    for (i=0;i<n;i++)
    {
      alloc[i]=i+1;
    }
   printf("The elements of Array are");
   for(i=0;i<n;i++)
   {
     printf("%d,",alloc[i]);
   }
   }
   return 0;
}
