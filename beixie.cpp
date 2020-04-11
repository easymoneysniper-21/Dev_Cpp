#include<bits/stdc++.h>

typedef struct linknode
{
	int data;
	struct linknode *next;
}lnode;
void initlist(lnode *&L)
{
	L=(lnode *)malloc (sizeof(lnode));
	L->next=NULL;
}
void creatlistf(lnode *&L,int a[],int n)
{
	lnode *p;
	int i;
	initlist(L);
	for (i=0;i<n;i++)
	{
		p=(lnode *)malloc(sizeof(lnode));
		p->data=a[i];
		p->next=L->next;
		L->next=p;
	}
}
void creatlistr(lnode *&L,int a[],int n)
{
	lnode *p,*q;
	int i;
	initlist(L);
	q=L;
	for (i=0;i<n;i++)
	{
		p=(lnode *)malloc(sizeof(lnode));
		p->data=a[i];
		p->next=q->next;
		q->next=p;
		q=q->next;		
	}
}
void displist(lnode *L)
{
	lnode *p=L->next;
	while (p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void deslist(lnode *&L)
{
	lnode *p=L->next,*pre=L;
	while (p!=NULL)
	{
		free(pre);
		pre=pre->next;
		p=p->next;
	}
	free(pre);
}
int listlen(lnode *L)
{
	int n=0;
	lnode *p=L->next;
	while (p!=NULL)
	{
		n++;
		p=p->next;
	}
	return (n);
}
bool getelem(lnode *L,int i,int &e)
{
	lnode *p=L->next;
	int j=1;
	if (i<=0)
	{
		return false;
	}
	while (p!=NULL && j<i)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)
	{
		return false;
	}
	else
	{
		e=p->data;
		return true;
	}	

}
int locatlist(lnode *L,int e)
{
	lnode *p=L->next;
	int i=1;
	while (p!=NULL&& p->data!=e)
	{
		i++;
		p=p->next;
	}
	if (p==NULL)
	{
		return 0;
	}
	else 
	{
		return i;
	}
}
bool insertlist(lnode *&L,int i,int e)
{
	lnode *p=L,*s;
	int j=0;
	while (p!=NULL && j<i-1)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)
	{
		return false;
	}
	else
	{
		s=(lnode *)malloc(sizeof(lnode));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
	}
}
bool deletelist(lnode *&L,int i,int &e)
{
	lnode *p=L,*q;
	int j=0;
	while (p!=NULL && j<i-1)
	{
		j++;
		p=p->next;
	}
	if (p==NULL)
	{
		return false;
	}
	else
	{
		q=p->next;
		if (q!=NULL)
		{
			e=q->data;
			p->next=q->next;
			free(q);
			return true;
		}
		else
		return false;
	}
}
void splitlist(lnode *&L,lnode *&L1,lnode *&L2)
{
	lnode *p,*q,*r;
	p=L->next;
	L->next=NULL;
	L1=L;
	r=L1;
	L2=(lnode *)malloc(sizeof(lnode));
	L2->next=NULL;
	while (p!=NULL)
	{
		r->next=p;
		r=p;
		p=p->next;
		if (p!=NULL)
		{
			q=p->next;
			p->next=L2->next;
			L2->next=p;
			p=q;
		}
		
	}
	r->next=NULL;
}
void splitlist1(lnode *&L,lnode *&L1,lnode *&L2)
{
	lnode *p,*q,*r,*s;
	p=L->next;
	L->next=NULL;
	L1=L;
	r=L1;
	L2=(lnode *)malloc(sizeof(lnode));
	L2->next=NULL;
	while(p!=NULL)
	{
		q=p->next;
		p->next=NULL;
		r->next=p;
		r=r->next;
		if (q!=NULL)
		{
			s=q->next;
			q->next=L2->next;
			L2->next=q;
			p=s;
		}
		else
		{
			p=q;
		}
	}
}

void deletmax(lnode *&L)
{
	lnode *p=L->next,*pre=L,*max=p,*maxpre=pre;
	while (p!=NULL)
	{
		if(max->data<p->data)
		{
			max=p;
			maxpre=pre;
		}
		p=p->next;
		pre=pre->next;
	}
	maxpre->next=max->next;
	free(max);
}
void sortlist(lnode *&L)
{
	lnode *p,*q,*r;
	p=L->next->next;
	L->next->next=NULL;
	while (p!=NULL)
	{
		q=p->next;
		r=L;
		while(r->next!=NULL && r->next->data<p->data)
		{
			r=r->next;
		}
		p->next=r->next;
		r->next=p;
		p=q;
	}
}
int main()
{
	int a[10]={6,5,8};
//	int e;
	lnode *L;
//	lnode *L1,*L2;
	//creatlistf(L,a,10);
	//displist(L);
	creatlistr(L,a,3);
	displist(L);
//	printf("%d %p %d %p %d %p ",L->data,L,L->next->data,L->next,L->next->next->data,L->next->next);

//	printf("%d \n",listlen(L));
//	if (getelem(L,9,x))
//	{
//		printf("%d \n",x);
//	}
//	else
//	{
//		printf("mistake\n");
//	}
//	printf("%d ",locatlist(L,18));
//	if (insertlist(L,6,18))
//	{
//		displist(L);
//	}
//	else
//	{
//		printf("mistake\n");
//	}
//	if (deletelist(L,5,e))
//	{
//		displist(L);
//		printf("%d ",e);
//	}
//	else
//	{
//		printf("mistake");
//	}
//	splitlist1(L,L1,L2);
//	displist(L1);
//	displist(L2);
	sortlist(L);
	displist(L);

	return 0;
}

