#include "list.h"
#include <stdio.h>
List IntertList(List L1, List L2);
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
	List Result = NULL;
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
		
    Result = IntertList(L, P);
    printf("Intert List:\n");	
	PrintList(Result);
	
	printf("before swap  Element:\n");
	PrintList(L);
	printf("afeter swap 2nd and 3rd element:\n");
	SwapWithNext(L->Next->Next,L);
	PrintList(L);	 

	
	DeleteList(L);
	DeleteList(P);
	DeleteList(Result);
	return 0;
}

List IntertList(List L1, List L2)
{
	List Result = NULL;
	Position L1Pos = NULL;
	Position L2Pos = NULL;
	Position ResultPos = NULL;
	
	Result = MakeEmpty(NULL);
	L1Pos = First(L1);
	L2Pos = First(L2);
	ResultPos = First(Result);
	
	while(L1Pos != NULL && L2Pos != NULL)
	{
		if (L1Pos->Element < L2Pos->Element)
		{
			L1Pos = L1Pos->Next;			
		}
		else if (L1Pos->Element > L2Pos->Element)
		{
			L2Pos = L2Pos->Next;
		}
		else
		{
			Result = Insert(L1Pos->Element,Result,ResultPos);
			if (ResultPos==NULL)
			{
				ResultPos = First(Result);
			}
			else
			{
				ResultPos = Advance(ResultPos);
			}
			
			L1Pos = Advance(L1Pos);
			L2Pos = Advance(L2Pos);
		}
	}

      return Result;
}
