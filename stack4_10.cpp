#include<bits/stdc++.h>
typedef struct 
{  char data[20]; 
   int top;	
}SqStack;
void InitStack(SqStack *&s)
{  
	s=(SqStack *)malloc(sizeof(SqStack));
  	s->top=-1;
} 
void DestroyStack(SqStack *&s)
{
  free(s);
}
bool StackEmpty(SqStack *s)
{
  return(s->top==-1);
}
bool Push(SqStack *&s,char e)
{  if (s->top==19) 	
	return false;
   s->top++;		   
   s->data[s->top]=e;	   
   return true;
}
bool Pop(SqStack *&s,char &e)
{  if (s->top==-1)	
	return false;
   e=s->data[s->top];
   s->top--;		
   return true;
}
bool GetTop(SqStack *s,char &e)
{	
   if (s->top==-1)	   		   
      return false;
    e=s->data[s->top];   	
    return true;
}
bool symmetry(char str[])
{  int i,j=0;  char e; 
   SqStack *st;
   InitStack(st);			

   for (i=0;i<strlen(str);i++)		
      Push(st,str[i]);		

    while (st->top!=-1)            //for (i=0;i<strlen(str);i++)
   {  Pop(st,e);		
      if (st->data[j++]!=e)	 		
      {  DestroyStack(st);		
	  return false;
      }
   }

   DestroyStack(st);	 	
   return true;
}

void trans(int n)
{
  char e;
  SqStack *st;
  InitStack(st);
  while (n>0)
  {  Push(st,n%2);
     n=n/2;
  }
  while (!StackEmpty(st))   
  {  Pop(st,e);
     printf("%d",e);
  }
  printf("\n");
  DestroyStack(st);
}

int main()
{
	SqStack *s;
	int i;
	char a[]="abcba";
	char b[]="(()()))";
	InitStack(s);
//	printf("%d ",strlen(a));
//	printf("%d ",sizeof(a));
	if (symmetry(b))
	printf("yes");
	else
	printf("No");
	trans(10);
	return 0;
}

