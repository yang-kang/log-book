#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
  char *data;
  int size;
  int i;  
}Stack;

void stack_init(Stack *s,char n)
{
  s->size=n;
  s->data=malloc(sizeof(char)*n);
  s->i=0;  
}

void stack_push(Stack *s,char data)
{
    if(s->i==s->size)
    {
      printf("栈满!\n");
      return ;  
    }
    s->data[s->i]=data;
    s->i++;
}

char stack_pop(Stack *s)
{
  if(s->i==0)
  {
    printf("栈空!\n");
    return -1;  
  }
  s->i--;
  return s->data[s->i];
}
int main()
{
  Stack s;
  char ch;
  int n=0;
  int count=0;
  char input[100]={'\0'};
  char *p;
  stack_init(&s,100);
    gets(input);
    p=input;
  while(*p!='\0')
  {
	ch=*p;
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
	{
	    stack_push(&s,ch);
	}
	if((ch>='0'&&ch<='9')||ch==' ')
	{   
	     	if(s.i>0)
		{
		    for(n=s.i;n>0;n--)
	    	    {
	               printf("%c",stack_pop(&s));
	    	    }
                    printf("%c",ch);
		}
		else
		{	
	    	    printf("%c",ch);
		}
	}
   	p++;
  }
  for(n=s.i;n>0;n--)
  {
        printf("%c",stack_pop(&s));
  }
  printf("\n");
  return 0;  
}
