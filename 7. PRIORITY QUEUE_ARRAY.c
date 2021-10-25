#include <stdio.h>
#include<stdlib.h>
#include <process.h>

void Insert_in_PQueue();
void Delete_from_PQueue();
void Display_PQueue();
void Check_Priority(int,int);

int PQueue[100],Priority[100],front=-1,rear=-1,size,k=-1;

int main()
{
  int i,choice;

  printf("Enter the size of Queue to be formed: ");
  scanf("%d",&size);
  for(i=0;i<size;i++)
      Priority[i]=-1;

  while(1)
  {
   printf("\n\nOPERATIONS ON PRIORITY QUEUE\n");
   printf("\nChoose:\n1 - Insertion in Priority Queue\n2 - Deletion in Priority Queue\n3 - Displaying the Priority Queue\n4 - Stop executing.\n");
   scanf("%d",&choice);

   switch(choice)
   {
	      case 1: Insert_in_PQueue();
		          break;
		  case 2: Delete_from_PQueue();
		          break;
          case 3: Display_PQueue();
                  break;
		  case 4: exit(0);
		          break;
		  default: printf("Wrong Choice!");
		           break;
   }
  }
  return 0;
}

void Insert_in_PQueue()
{
    int element,pri;
    {
       if(rear==size-1)
        {
          printf("\nOVERFLOW! The Queue is already full!\n");
          return;
        }
       else
       {
          printf("\nEnter element to be inserted in the Priority  Queue: ");
          scanf("%d",&element);
          printf("\nEnter the priority of %d in the Priority Queue: ",element);
          scanf("%d",&pri);
          if(rear==-1)
          {   front=0;
              rear=0;
              PQueue[rear]=element;
              Priority[rear]=pri;
          }
          else
          {
              rear++;
              Check_Priority(element,pri);
          }
          printf("\nElement %d with priority %d has been inserted in the Queue.\n",element,pri);
       }
    }
}

void Delete_from_PQueue()
{
     if(front==-1)
         printf("\nUNDERFLOW! Empty queue! No elements found for deletion.\n");
     else
     {
  	     if(front==rear)
  	        front=rear=-1;
  	     else
  	        front++;
          printf("\nElement %d has been deleted from the Queue.\n",PQueue[front-1]);
  	 }
}

void Display_PQueue()
{
	int i;
	if(front==-1)
	   printf("Empty queue! No elements found.\n");
	else
	{
	    printf("\nNow the Queue is: \n");
	    printf("\nELEMENTS :");
	    for(i=0;i<front;i++)
		     printf("  -  ");
		for(i=front;i<=rear;i++)
		     printf("  %d   ",PQueue[i]);
        printf("\nPRIORITY :");
        for(i=0;i<front;i++)
		     printf("  -  ");
		for(i=front;i<=rear;i++)
		     printf("  %d   ",Priority[i]);
	}

}


void Check_Priority(int item,int p)
{
     int i=0,j;
     while(Priority[i]>=p)
        i++;
     for(j=size-1;j>i;j--)
     {
         Priority[j]=Priority[j-1];
         PQueue[j]=PQueue[j-1];
     }
     PQueue[i]=item;
     Priority[i]=p;

}

