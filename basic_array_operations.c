#include<stdio.h>
#define N 20
void insertarray(int *a,int x,int *n)
{ 
	int i;
	i=*n;
	while(i>0 && a[i-1]>x)
	{
		a[i]=a[i-1];
		i--;
	}
	a[i]=x;
	(*n)++;
}
void deletearray(int *a,int x,int *n)
{
	int i=0,j;
		while(i<*n && a[i]!=x)
		i++;
		if (i<*n)
		{
			for(j=i;j<*n-1;j++)
			a[j]=a[j+1];
			(*n)--;
		}
}
int linearsearch(int *a,int x,int n)
{
	int i=0;
	while(i<n && a[i]!=x)
	i++;
	if (i==n)
	return -1;
	else 
	return i;
}
void selectionsort(int *a,int n)
{
	printf("will be implemented later\n");
}
void traversearray(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
}

int main()
{
	int p[N]={1,3,5,7,9};
	int no=5,choice,v;
	do{
		printf("1. Enter a value\n");
		printf("2. Delete a value\n");
		printf("3. Search a value\n");
		printf("4. Sort values\n");
		printf("5. traverse and print\n");
		printf("6. EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
				printf("Give value to enter: ");
				scanf("%d",&v);
				if (no<N)
				insertarray(p,v,&no);
				else
				printf("array full, cannot enter\n");
				break;
		case 2:
				printf("give value to delete: ");
				scanf("%d",&v);
				deletearray(p,v,&no);
				break;
		case 3:
				printf("give value to search: ");
				scanf("%d",&v);	
				printf("value found at location: %d\n",linearsearch(p,v,no));
				break;
		case 4:
				selectionsort(p,no);
				printf("Sorting will be implemented later\n");
				break;
		case 5:
				traversearray(p,no);
				break;
		case 6:
				printf("Thank you, BYE\n");
				break;
		default:
				printf("invalid choice, enter again\n");
		}
	} while(choice!=6);	
}
