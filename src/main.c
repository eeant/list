#include "list.h"
#include <stdio.h>
/*Print List L*/
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
/**Print L by P Point*/
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
/* BeforeP is the cell before the two adjacent cells that are to be swapped. */
/* Error checks are omitted for clarity. */
void SwapWithNext(Position BeforeP,List L)
{
	Position P,AfterP;
	
	P = BeforeP->Next;
	AfterP = P->Next;/* Both P and AfterP assumed not NULL. */
	
	BeforeP->Next = AfterP;
	P->Next = AfterP->Next;
	AfterP->Next = P;


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
	printf("L List's Elements are:\n");
	PrintList(L);	
	
	P = MakeEmpty(P);
	insertP = P;
	do{
		printf("Enter the P Element:");
		scanf("%d",&input);
		
		Insert(input,P,insertP);
	}while(input > 1);
	
	printf("P List's Elements are:\n");	
	PrintList(P);
	printf("L List's Elements in Points by P List's Elements are:\n");
	PrintLots(L,P);
	printf("before swap  Element:\n");
	PrintList(L);
	printf("afeter swap 2nd and 3rd element:\n");
	SwapWithNext(L->Next->Next,L);
	PrintList(L);	 
	DeleteList(L);
	DeleteList(P);
	return 0;
}
