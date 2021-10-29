#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quo,rem,bin=0;
    printf("Enter a number to be converted to binary :\n");
    scanf("%d",&quo);
    if(quo%2==0)
    {
        quo=quo+1;
        while(quo!=0)
    {
        rem=quo%2;
        quo=quo/2;
        bin=bin*10 + rem;

    }
    bin=bin-1;
    printf("the binary is %d",bin);
    }
    else
    {
        while(quo!=0)
    {
        rem=quo%2;
        quo=quo/2;
        bin=bin*10 + rem;

    }
    printf("the binary is %d",bin);

    }

  return 0;
}

