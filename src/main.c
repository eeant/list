#include "list.h"
#include <stdio.h>

void PrintList(List L)
{
	Position P = NULL;
	P =  L->Next;
	while(P != NULL)
	{
		printf("%d\n",P->Element);
		P = P->Next;
	}
}

void PrintLots(List L, List P)
{
	int  count = 0;
	Position Lpos,Ppos;
	Lpos = First(L);
	Ppos = First(P);
	count = 1;
	while(Lpos != NULL && Ppos != NULL)
	{
		if (Ppos->Element == count++)
		{
			printf("%d\n",Lpos->Element);
			Ppos = Advance(Ppos);
		}
		Lpos = Advance(Lpos);
	}
}


int main(int argc,char *argv[])
{
	List L = NULL;
	Position insertP = NULL;
	List P = NULL;
	int input = -1;
	L = MakeEmpty(L);
	insertP = L;
	do
	{
		printf("Enter the L Element:");
		scanf("%d",&input);
		
		Insert(input,L,insertP);		
	}while(input!=-1);
	
	PrintList(L);	
	
	P = MakeEmpty(P);
	insertP = P;
	do{
		printf("Enter the P Element:");
		scanf("%d",&input);
		
		Insert(input,P,insertP);
	}while(input > 1);
	
	
	PrintList(P);
	PrintLots(L,P);
	DeleteList(L);
	DeleteList(P);
	return 0;
}
