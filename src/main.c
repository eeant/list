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


int main(int argc,char *argv[])
{
	List L = NULL;
	Position insertP = NULL;
	int input = -1;
	L = MakeEmpty(L);
	insertP = L;
	do
	{
		printf("Enter the Element:");
		scanf("%d",&input);
		
		Insert(input,L,insertP);		
	}while(input!=-1);
	
	PrintList(L);	

	DeleteList(L);
	return 0;
}
