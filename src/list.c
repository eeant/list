#include "list.h"
#include "fatal.h"
#include <stdlib.h>

/*Place in the interface file*/

List MakeEmpty(List L)
{
	if (L != NULL)	
		DeleteList(L);
	L = malloc(sizeof(struct Node));
	if (L == NULL)
		FatalError("Out of memory");
	L->Next = NULL;
	return L;
}
/*Return true if L is empty*/
int IsEmpty(List L)
{
	return L->Next == NULL;
}

/*Return true if P is the last position in list L*/
/*Parameter L is unused in this implemention*/
/*Return Position of X in L; NULL if not found*/
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
Position Find(ElementType X,List L)
{
	Position P;
	
	P = L->Next;
	while(P !=NULL && P->Element != X)
		P = P->Next;

	return P;
}

/*Delete form a list*/
/*Cell pointed to by P->Next is wiped out*/
/*Aussume that the position is legal*/
/*Assume use of a header node*/
void Delete(ElementType X, List L)
{
	Position P,TmpCell;
	
	P = FindPrevious(X,L);
	
	if ( !IsLast(P, L)) /*iAssumption of header use*/
	{		    /*X is found;delete it*/
		TmpCell = P->Next;
		P->Next = TmpCell->Next; /*bypass deleted cell*/
		free(TmpCell);
	}
}
/*If X is nod found, then Next field of returned value is NULL*/
/*Assumes a header*/
Position FindPrevious(ElementType X, List L)
{
	Position P;
	P =  L->Next;
	while(P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;

}
/*Insett after legal position P*/
/*Header implementatioon assumed*/
/*Parameter L is unused in this implementtation*/
List Insert(ElementType X,List L, Position P)
{
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		FatalError("Out of space!!!");
	
	TmpCell->Element = X;
	
	if (P == NULL)
	{
		TmpCell->Next = L->Next;
		L->Next=TmpCell;
	}
	else
	{
		TmpCell->Next = P->Next;
		P->Next = TmpCell;
	}


	return L;
}

void DeleteList(List L)
{
	Position P,Tmp;
	P = L->Next;/*Header assumed*/
	L->Next= NULL;
	while(P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}


Position Header(List L)
{
	return L;
}

Position First(List L)
{
	return L->Next;
}

Position Advance(Position P)
{
	Position ReturnP;
	if (P == NULL)
	{
		ReturnP = NULL;
	}
	else
	{
		ReturnP = P->Next;
	}
	return ReturnP;
}
ElementType Retrieve(Position P)
{
	return P->Element;
}
