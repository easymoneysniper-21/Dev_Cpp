#include<bits/stdc++.h>
typedef struct linknode
{   char data;	
    struct linknode *next;	
}  LinkStNode;
void InitStack(LinkStNode *&s)
{  s=(LinkStNode *)malloc(sizeof(LinkStNode)); 
   s->next=NULL;
}
void DestroyStack(LinkStNode *&s)
{
	LinkStNode *p,*q;
	p=s;
	q=s->next;
	while (q!=NULL)
	{
		free(p);
		p=p->next;
		q=q->next;
	}
	free(p);
}
bool StackEmpty(LinkStNode *s)
{
    return(s->next==NULL);
}
void Push(LinkStNode *&s,char e)
{  LinkStNode *p;
   p=(LinkStNode *)malloc(sizeof(LinkStNode));
   p->data=e;	
   p->next=s->next;	
   s->next=p;
}
bool Pop(LinkStNode *&s,char &e)
{  LinkStNode *p;
   if (s->next==NULL)		
     return false;
   p=s->next;		
   e=p->data;
   s->next=p->next;	
   free(p);			
   return true;
}
bool GetTop(LinkStNode *s,char &e)
{  if (s->next==NULL)	
     return false;
   e=s->next->data;
   return true;
}
bool symmetry(char str[])
{  int i,j=0;  char e; 
   LinkStNode *st;
   InitStack(st);			

   for (i=0;i<strlen(str);i++)		
      Push(st,str[i]);		

    while (!StackEmpty(st))           //for (i=0;i<strlen(str);i++)
   {  Pop(st,e);		
      if (str[j++]!=e)	 		
      {  DestroyStack(st);		
	  return false;
      }
   }
   DestroyStack(st);	 	
   return true;
}
bool symm(char str[])
{
	int i,j=0;
	LinkStNode *p,*q,*r;
	LinkStNode *stl;
	stl=(LinkStNode *)malloc(sizeof(LinkStNode));
	stl->next=NULL;
	for (i=0;i<strlen(str);i++)
	{
		p=(LinkStNode *)malloc(sizeof(LinkStNode));
		p->data=str[i];
		p->next=stl->next;
		stl->next=p;
	}
	while (stl->next!=NULL)
	{
		q=stl->next;
		r=q->next;
		if (q->data!=str[j++])
		{
			DestroyStack(stl);
			return false;
		}
		else
		stl->next=r;
		free(q);
		q=r;
	}
	DestroyStack(stl);
	return true;
}
bool Match(char exp[],int n)
{  int i=0; char e;  

   bool match=true; 

   LinkStNode *st;

   InitStack(st);		
   while (i<n && match)		
   { 
      if (exp[i]=='(')
          Push(st,exp[i]);
else if (exp[i]==')') 	
      {  if (st->next!=NULL)
	   
		Pop(st,e);    		
	 
	  else match=false;  	
      }

      i++;				
  }
if (!StackEmpty(st))	
	match=false;

    DestroyStack(st);	     
    return match;
}

int main()
{
	LinkStNode *stl;
	InitStack(stl);

	char a[]="abccba";
	char b[]="(()()))";
	int i;
	if (symm(a))
	printf("yes");
	else
	printf("No");
	if (Match(b,7))
	printf("yes");
	else
	printf("no");
//	for (i=0;i<strlen(a);i++)
//	{
//		Push(stl,a[i]);
//	}
//	LinkStNode *p=stl->next;
//	while (p!=NULL)
//	{
//		printf("%c",p->data);
//		p=p->next;
//	}
	return 0;
}

