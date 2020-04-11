#include<bits/stdc++.h>
typedef struct st
{
	int data[20];
	int length;
}sqlist;
void createlist(sqlist *&L,int a[],int n)
{
	int i,k=0;
	L=(sqlist *)malloc(sizeof(sqlist));
	L->length=0;
	for (i=0;i<n;i++)
	{
		L->data[k]=a[i];
		k++;
	}
	L->length=k;
}
void dgprint(sqlist *L,int n)
{
	if (n)
	{
		dgprint(L,n-1);
		printf("%d ",L->data[n-1]);
	}
}
void printlist(sqlist *L)
{
	int i;
	for (i=0;i<L->length;i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("\n");
}
void dgcreatelist(sqlist *&L,int a[],int n)
{
	if (n)
	{
		L->data[n-1]=a[n-1];
		dgcreatelist(L,a,n-1);
	}
}
bool inslist(sqlist *&L,int i,int e)
{
	int j;
	if (i<=0 || i>L->length+1 || i>20)
	{
		return false;
	}
	else
	{
		for (j=L->length-1;j>=i-1;j--)
		{
			L->data[j+1]=L->data[j];
		}
		L->data[i-1]=e;
		L->length++;
		return true;
	}
}
bool dellist (sqlist *&L,int i,int &e)
{
	int j;
	if (i<=0 || i>L->length)
	{
		return false;
	}
	else
	{
		e=L->data[i-1];
		for (j=i-1;j<=L->length-1;j++)
		{
			L->data[j]=L->data[j+1];
		}
		L->length--;
		return true;
	}
}
void delnode(sqlist *&L, int x)
{  int k=0, i;			
   for (i=0;i<L->length;i++)
      if (L->data[i]!=x)    	
      {   L->data[k]=L->data[i];
          k++;		 	
      }
   L->length=k;			
}
void swap(int &a,int &b)
{
	int t;
	t=a;a=b;b=t;
}
void pivot1(sqlist *&L)
{  int i=1,j=L->length-1;
   int  pi=L->data[0];
   while (i<j)
   {  while (i<j && L->data[j]>pi)
	 j--;	  	 	
      while (i<j && L->data[i]<=pi)
	 i++;			
      if (i<j)
         swap(L->data[i],L->data[j]);
   }
   swap(L->data[0],L->data[i]);
}
void pivotsort(sqlist *&L)
{
	int i,j,k;
	for (i=1;i<L->length;i++)
	{
		k=L->data[i];
		for (j=i-1;j>=0 && L->data[j]>=k;j--)
		{
			L->data[j+1]=L->data[j];
		}
		L->data[j+1]=k;
	}
}
int main()
{
	int a[10]={5,2,3,6,2,7,9,4,2,0};
	int e;
	sqlist *L;
//	L=(sqlist *)malloc(sizeof(sqlist));
//	L->length=10;
	dgcreatelist(L,a,10);
//	createlist(L,a,10);
//	delnode(L,2);
	printlist(L);
//	pivot1(L);
	pivotsort(L);
	printlist(L);
//	if (inslist(L,11,13))
//	{
//		printlist(L);
//	}
//	else
//	{
//		printf("insert fai ");
//	}
//	if (dellist(L,10,e))
//	{
//		printlist(L);
//		printf("É¾³ýµÄÊýÎª %d ",e);
//	}
//	else
//	{
//		printf("insert fai ");
//	}

//	L->data[0]=2;
//	printf("%p %p %d %d %d",a,&a[0],L,&L->data[0],&L->length);
	return 0;
}

