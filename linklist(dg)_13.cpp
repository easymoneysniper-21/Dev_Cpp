#include<bits/stdc++.h>

typedef struct st
{
	int data;
	struct st *next;
}lklist;

lklist * dgcrlk(int a[],int n)
{
	lklist *L;
	if(n)
	{
		L=(lklist *)malloc(sizeof(lklist));
		L->data=a[n-1];
		L->next=dgcrlk(a,n-1);
	}
	else
	L=NULL;
	return L;

}
void crlist(lklist *&L,int a[],int n)
{
	lklist *r,*p;
	L=(lklist *)malloc(sizeof(lklist));
	L->next=NULL;
	r=L;
	for (int i=0;i<n;i++)
	{
		p=(lklist *)malloc(sizeof(lklist));
		p->data=a[i];
		p->next=r->next;
		r->next=p;
	}
	r=r->next;
}
 void dgprlt(lklist *L)
 {
 	if (L)
 	{
 		printf("%d ",L->data);
 		dgprlt(L->next);
	 }
 }
 void prlist(lklist *L)
 {
 	lklist *p=L;
 	while (p!=NULL)
 	{
 		printf("%d ",p->data);
 		p=p->next;
	}
 	
 }
int  main()
{
	lklist *head;
	int a[10]={4,7,8,6,2,1,5,8,9,1};
	head=dgcrlk(a,10);
//  crlist(head,a,10);
	printf("Á´±íÎª:");
	dgprlt(head);
//	prlist(head);
	printf("\n");

//	printf("%d ",head->next->data);
	return 0;
}

