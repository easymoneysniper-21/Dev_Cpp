#include<bits/stdc++.h>
typedef struct 
{  char data[20]; 
   int top;	
}SqStack;
bool Match(char exp[],int n)
{  int i=0; char e; 

   bool match=true; 

   SqStack *s;

   s=(SqStack *)malloc(sizeof(SqStack));
  	s->top=-1;		
   while (i<n && match)		
   { 
      if (exp[i]=='(')
    {
		 if (s->top==19)
		 {
			   	
	       return false;
           s->top++;		   
           s->data[s->top]=e;	   
           return true;
         }
   }
else if (exp[i]==')') 	
      {  
	     if (s->top!=-1)
         {	
		 return false;
         e=s->data[s->top];
         s->top--;		
         return true;    		
	
	     }
	else match=false;  	
     }

      i++;				
  }
  if (s->top!=-1)
  {
	match=false;

    free(s);	     
    return match;
 }
}
int main()
{
	char b[]="(()()))";
	//int i;
	if (Match(b,7))
	printf("yes");
	else
	printf("no");
	return 0;
}
