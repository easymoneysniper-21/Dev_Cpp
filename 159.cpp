#include<bits/stdc++.h>

typedef struct linknode
{
	int data;
	struct linknode *next;
}lnode;

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

void createlist(lnode *L)
{
	int data;
	lnode *p;
	
	if(data!=0)
	{
		L=(lnode *)malloc(sizeof(lnode));
		p=L->next;
		p->data=data;
		p=p->next;
	}
}
int main()
{
	lnode *L;
	createlist(L);
	
}
