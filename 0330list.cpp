#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
#include "malloc.h"

typedef struct LNode{
	int data;
	struct LNode * next;
} LinkNode; 

//�������� 
void createListR(LinkNode * &L);
void createListR02(LinkNode *&L,int a[],int n);
void displayList(LinkNode * L);

int main(){
	LinkNode * LA;
	LinkNode * LB;
	LinkNode * LC;
	
	
	int a1[] = {1,3,5,7};
	int a2[] = {2,4,6,8}; 
	
	createListR02(LA,a1,4);
	createListR02(LB,a2,4);
	

	displayList(LA);
    displayList(LB);
    
	return 0;
}

//����ʵ�� 
void createListR02(LinkNode * &L,int a[],int n){
	int i;
	LinkNode * p;   //�½����ָ�� 
	LinkNode * q;   //q��ָ��ǰ��������һ������ָ�� 
	int data; 
	
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
	q = L; 
	
	for(i=0;i<n;i++){
	p = (LinkNode *)malloc(sizeof(LinkNode));
	p->data=a[i];
	
	q->next = p;
	q = q->next;
	}
	q->next = NULL;
}



//�������� 
void displayList(LinkNode * L) {
	LinkNode * pL;
	
	pL = L->next;
	while(pL != NULL){
		cout<<setw(4)<<pL->data;
		pL = pL->next;
	}
	cout<<endl;
}

