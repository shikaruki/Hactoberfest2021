// problem_code-CHEFRECP 
#include <stdio.h>

int main(void) {int t;
scanf("%d\n",&t);
for(int r=0;r<t;r++)
{
    int n;
    scanf("%d\n",&n);
    int s[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d ",&s[i]);
    }
    int fr1[n],ctr,c=0,d=0;
    for(int i=0;i<n;i++)
    {
      if(s[i]!=s[i+1])
      {
        for(int j=i+2;j<n;j++)
        {
            if(s[i]==s[j])
            d++;
        }
      }
    }
       for(int i=0;i<n;i++)
       {
		  fr1[i] = -1;
	    }
    for(int i=0; i<n; i++)
    {
        ctr = 1;
        for(int j=i+1; j<n; j++)
        {
            if(s[i]==s[j])
            {
                ctr++;
                fr1[j] = 0;
            }
        }

        if(fr1[i]!=0)
        {
            fr1[i] = ctr;
        }
    }
    for(int i=0;i<n;i++)
    {   if(fr1[i]!=0)
        {
        for(int j=i+1;j<n;j++)
        {
            if(fr1[i]==fr1[j])
            {
             c++;
            }
        }
        }
    }
    if(c!=0 || d!=0)
    {
        printf("NO\n");
    }else printf("YES\n");
}

	// your code goes here
	return 0;
}

