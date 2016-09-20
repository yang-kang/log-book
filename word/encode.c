#include <stdio.h>

int countLen(int n)
{
  int i=0;
  
  do{
    n=n>>1;
    i++;   
  }while(n>0);
  return i;
}

void putPre(int n)
{
  int i=0;
  for(i=0;i<n-1;i++)
  {
    printf("1");  
  }
  printf("0");
}

void putBin(int n,int len)
{
    int i=0;
    for(i=len-1;i>=0;i--)
    {
      if((n>>i)&1)
      {
        printf("1");  
      }
      else
      {
        printf("0");  
      }
    }
}
int main()
{
  char temp;
  int i=0;
  int j=0;
  int flag=0;
  while(flag==0)
  {
    scanf("%c",&temp);
    switch(temp)
    {
        case '0':
          i++;
          break;
        case '1':
          j=countLen(i);
          putPre(j);
          putBin(i,j);
          i=0;
          break;
        case '\n':
          flag=1;
          break;
        default:
          break;
    }
  }
  printf("\n");
  return 0;
}
