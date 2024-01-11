#include <stdio.h>
int search(int a[3][3],int x);
int main ()
{
    int Array[3][3];
    int i,j;
    int result,number;
    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
        {
            printf(" Array[%d][%d]= ",i,j);
            scanf("%d", &Array[i][j]);
        }
    }
    printf("Enter The number you want:>");
    scanf("%d",&number);
    result=search(Array,number);
    if(search(Array,number))
        printf("Number exists\n");
    else
       printf("Number does not exists\n");
    return 0;
}
int search(int a[3][3],int x){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
           if (x==a[i][j])
               return 1;
           return 0;
        }
    }
}
