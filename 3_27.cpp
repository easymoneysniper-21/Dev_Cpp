#include<bits/stdc++.h>
typedef struct st
{
	int data[20];
	int length;
}SqList;
typedef struct Node1		
{  int data[10];
   struct Node1 *next;		
} DList;
typedef struct Node2	
{  int Row,Col;		
   DList *next;		
}  HList;      
void CreateTable(HList *&h)
{  int i,j;  DList *r,*s;
   h=(HList *)malloc(sizeof(HList));    	
   h->next=NULL;
   printf("请输入线性表的行数和列数:");
   scanf("%d%d",&h->Row,&h->Col);      	
   for (i=0;i<h->Row;i++)		      	
   {  printf(" 输入第 %d 行:",i+1);
      s=(DList *)malloc(sizeof(DList));	
      for (j=0;j<h->Col;j++)		      
  	 scanf("%d",&s->data[j]);
      if (h->next==NULL)	            
        h->next=s;
      else				
        r->next=s;			
      r=s;				
   }
   r->next=NULL;			
}
void LinkTable(HList *h1,HList *h2,HList *&h)
{    int i,j,k;
     DList *p=h1->next,*q,*s,*r;

     printf("第一个聊表的第几列和第二个链表的第几列链接:");
     scanf("%d%d",&i,&j);

     h=(HList *)malloc(sizeof(HList));	//????????
     h->next=NULL;			//?next??NULL
     h->Row=0;				//????0
     h->Col=h1->Col+h2->Col;		//?????1??2????

   while (p!=NULL) 				//???1
   {  q=h2->next;				//q???2?????
      while (q!=NULL)				//???2
      {  if (p->data[i-1]==q->data[j-1])	  	//???????
  	  { 
            s=(DList *)malloc(sizeof(DList)); 	//????
	     for (k=0;k<h1->Col;k++)		//???1????
		 s->data[k]=p->data[k];
	     for (k=0;k<h2->Col;k++)		//???2????
		 s->data[h1->Col+k]=q->data[k];

		if (h->next==NULL)	//??????????
		    h->next=s;		//?s????????
		else			//?????????
		    r->next=s;		//?s???r????
		r=s;			//r???????

		h->Row++;		//????1
	     }
	     q=q->next;			//?2??????
	 }
	 p=p->next;			//?1??????
     }
     r->next=NULL;	 	 	//????next???
  }

void DispTable(HList *h)
{  int i,j;
   DList *p=h->next;		//p???????
  for (i=0;i<h->Row;i++)	//?????
   {  for (j=0;j<h->Col;j++)	//???????
	 printf("%4d",p->data[j]);
      printf("\n");
      p=p->next;			//p???????
  }
}

void CreateList(SqList *&L,int a[],int n)
{
	int i,k=0;
	L=(SqList *)malloc (sizeof(SqList));
	for (i=0;i<n;i++,k++)
	{
		L->data[k]=a[i];
	}
	L->length=k;
}
void DispList(SqList *L)
{
	int i;
	for (i=0;i<L->length;i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("\n");
}
void fun1(SqList *&L)
{
	int i,j=0;
	for (i=1;i<L->length;i++)
	if (L->data[i]>L->data[j])
	j=i;
	for (i=j;i<L->length-1;i++)
	L->data[i]=L->data[i+1];
	L->length--;
}
void fun2(SqList *&L,int x)
{
	int i,j=0;
	for (i=1;i<L->length;i++)
	if (L->data[i]<=L->data[j])
	j=i;
	for (i=L->length;i>j;i--)
	L->data[i]=L->data[i-1];
	L->data[j]=x;
	L->length++;
}
void  fun3(SqList *&L)
{
	int i,j;
	int m;
	for (i=1;i<=L->length-1;i++)
	{
		m=L->data[i];
//		j=i-1;
//		while (j>=0 && m<=L->data[j])
for (j=i-1;j>=0 && m<=L->data[j];j--)
		{
			L->data[j+1]=L->data[j];
//			j--;
		}
		L->data[j+1]=m;
	}
}

int main()
{
	HList *h,*h1,*h2;
	CreateTable(h1);
	CreateTable(h2);
	DispTable(h1);
	DispTable(h2);
	LinkTable(h1,h2,h);
	DispTable(h);
//	int a[10]={45,21,32,46,85,71,86,92,41,8};
	//	SqList *L;
//	CreateList(L,a,10);
//	DispList(L);
//	fun1(L);
//	DispList(L);
//	fun2(L,100);
//	DispList(L);
	return 0;
}

