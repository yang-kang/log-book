#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
  int *data;
  int size;
  int i;  
}Stack;

void stack_init(Stack *s,int n)
{
  s->size=n;
  s->data=malloc(sizeof(int)*n);
  s->i=0;  
}

void stack_push(Stack *s,int data)
{
    if(s->i==s->size)
    {
      printf("栈满!\n");
      return ;  
    }
    s->data[s->i]=data;
    s->i++;
}

int stack_pop(Stack *s)
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

  stack_init(&s,5);
  stack_push(&s,1);
  stack_push(&s,2);
  stack_push(&s,3);
  printf("出栈:%d\n",stack_pop(&s));
  stack_push(&s,4);
  printf("出栈:%d\n",stack_pop(&s));
  printf("出栈:%d\n",stack_pop(&s));
  return 0;  
}
