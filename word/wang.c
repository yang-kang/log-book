#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ie
{
  char tag[9];
  unsigned int len;
  char *value;
  struct ie *next;  
}IE;

int getIE(IE *p_ie)
{
  int i=0;
  char temp[8]="";
  char ch;
  int n=0;
  //读取8字节，存到p_ie->tag;
  i=0;
  while(i<8&&(ch=getchar())!='\n')
  {
      temp[i]=ch;
      i++;
  }
  if(i==0)
  {
    return 4;
  }
  if(i<8)
  {
    return 1;  
  }
  else
  {
    strcpy(p_ie->tag,temp);  
  }
  //读取4字节，转换为整型，存到p_ie->len
  i=0;
  while(i<4&&(ch=getchar())!='\n')
  {
      temp[i]=ch;
      i++;
  }
  if(i<4)
  {
    return 2;  
  }
  else
  {
    for(i=0;i<4;i++)
    {
      n<<=4;
      n+=(temp[i]>'9'?temp[i]-'a'+10:temp[i]-'0');  
    }
    p_ie->len=n;
  }
  //申请p_ie->len*2+1个字节的空间，给p_ie->value
  p_ie->value=malloc(p_ie->len*2+1);
  //读取p_ie->len*e个字节数据，存到p_ie->value    
  i=0;
  while(i<(p_ie->len)*2&&(ch=getchar())!='\n')
  {
      p_ie->value[i]=ch;
      i++;
  }
  if(i<p_ie->len*2)
  {
    return 3;  
  }
  else
  {
    p_ie->value[i]='\0';  
  }
  p_ie->next=NULL;
  return 0;
}

void putIE(IE *p)
{
  printf("%s",p->tag);  
  printf("%04x",p->len);  
  printf("%s",p->value);  
}
IE *insertIE(IE *head,IE *new)
{
  IE *p1,*p2;

  p1=p2=head;
  while(p1!=NULL&&strcmp(p1->tag,new->tag)<0)
  {
    p2=p1;
    p1=p1->next;  
  }
  if(p1==p2)
  {
    head=new;
    new->next=p1;
  }
  else
  {
    p2->next=new;
    new->next=p1;  
  }
  return head;  
}
IE *getTLV(IE *head)
{
  IE *n_ie=NULL;
  int rt=0;
  while(1)
  {
    //得到IE  getIE
    n_ie=malloc(sizeof(IE));
    rt=getIE(n_ie);//暂未实现
    if(rt==0)
    { //将IE插入链表 
      head=insertIE(head,n_ie);
    }
    else if(rt==4)
    {
      head=insertIE(head,n_ie);
      break;  
    }
    else
    {
      free(n_ie);
      break;  
    }
  }
  return head;
}

IE *orderTLV(IE *head)
{
  return head;  
}
void putTLV(IE *head)
{
  while(head!=NULL)
  {
    putIE(head);
    head=head->next;  
  }
}
void freeTLV(IE *head)
{
  
}
int main()
{
  IE *head=NULL;
  int n=0;
  head=malloc(sizeof(IE));
  n=getIE(head);
  putIE(head);
  //1.从数据流读取ie到链表
  head=getTLV(head);
  //2.排序链表
  //3.输出链表到数据流
  putTLV(head);

  freeTLV(head);
  return 0;  
}
