#include<stdio.h>
#define   MAX 100
int main()
{
int arr[MAX],i,j,k,n;
printf("enter the no of element : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{ 
     printf("enter element %d :",i+1);
     scanf("%d",&arr[i]);
     }
     for(i=1;i<n;i++)
     {
         k=arr[i];
         for(j=i-1;j>=0;&& k<arr[j];j++)
             arr[j+1]=arr[j];
             arr[j+1]=k;
             }
             printf("sorted list is : \n");
             for(i=0;i<n;i++)
             printf("%d",arr[i]);
             printf("\n");
             return 0;
             }
