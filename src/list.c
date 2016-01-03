#include "list.h"
#include "fatal.h"
#include <stdlib.h>

/* 
List MakeEmpty(List L)
参数 
L 要生成的空链表名 
返回值 
返回生成的空链表名 
功能 
生成空链表 
*/

List MakeEmpty(List L)
{
	if ( !IsEmpty(L) )	/*不是空链表,删除*/
		DeleteList(L);
		
	L = (List)malloc(sizeof(struct Node));
	if (L == NULL)
		FatalError("Out of memory");
	L->Next = NULL;
	
	return L;
}

/* 
int IsEmpty(List L)
参数 
L 要判定的链表名 
返回值 
若L为空返回1，否则返回0 
功能 
判断链表L是否为空 
*/
int IsEmpty(List L)
{
	return (L==NULL || L->Next == NULL);
}

/* 
int IsLast(Position P, List L)
参数 
P 要判定的位置 
返回值 
若P为为最后一个节点则返回1，否则返回0 
功能 
判断位置P的节点是否是链表最后一个节点 
*/ 
int IsLast(Position P, List L)
{
	
	return P->Next == NULL;
}
/* 
Position Find(ElementType E,List L)
参数 
E 要查找的数据项 
L 要查找的链表 
返回值 
若E在L中存在则返回第一个匹配节点的位置，否则返回NULL 
功能 
判断位置P的节点是否是链表最后一个节点 
*/
Position Find(ElementType E,List L)
{
	Position P;
	
	P = L->Next;
	while( P !=NULL && P->Element != E )
		P = P->Next;

	return P;
}

/* 
void Delete(ElementType E, List L)
参数 
E 要删除的数据项 
L 要删除节点所在的链表 
返回值 
无 
功能 
在链表L中删除查找到的第一个数据项为E的节点 
*/ 
void Delete(ElementType E, List L)
{
	Position P,tmpCell;
	
	P = FindPrevious(E, L);
	
	if ( !IsLast(P, L)) /*找到*/
	{		    		
		tmpCell = P->Next;
		P->Next = tmpCell->Next; 
		free(tmpCell);
	}
}
/* 
Position FindPrevious(ElementType E, List L)
参数 
E 要查找的数据项 
L 要查找的链表 
返回值 
若E在L中存在则返回第一个匹配节点的前驱位置，否则返回NULL 
功能 
返回链表L中数据项为X的节点的前驱节点位置 
*/ 
Position FindPrevious(ElementType E, List L)
{
	Position P;
	P =  L->Next;
	while(P->Next != NULL && P->Next->Element != E)
		P = P->Next;
	return P;

}
/*
List Insert(ElementType E,List L, Position P) 
参数 
E 要插入的数据项 
L 要插入的链表 
返回值 
无 
功能 
在链表L中P位置之后插入数据项为E的新节点 
*/
List Insert(ElementType E,List L, Position P)
{
	Position tmpCell;
	
	tmpCell = malloc(sizeof(struct Node));
	if (tmpCell == NULL)
		FatalError("Out of space!!!");
	
	tmpCell->Element = E;
	
	if (P == NULL)
	{
		tmpCell->Next = L->Next;
		L->Next=tmpCell;
	}
	else
	{
		tmpCell->Next = P->Next;
		P->Next = tmpCell;
	}


	return L;
}
/* 
void DeleteList(List L) 
参数 
L 要删除节点的链表 
返回值 
无 
功能 
删除链表L中所有节点 
*/ 
void DeleteList(List L)
{
	Position P,tmp;
	
	P = L->Next;
	L->Next= NULL;
	while(P != NULL)
	{
		tmp = P->Next;
		free(P);
		P = tmp;
	}
}

/* 
Position Header(List L) 
参数 
L 要查找的链表 
返回值 
返回链表L的头节点位置 
功能 
返回头节点 
*/ 
Position Header(List L)
{
	return L;
}
/* 
Position First(List L) 
参数 
L 要查找的链表 
返回值 
若链表非空则返回第一个数据节点，否则返回NULL 
功能 
返回第一个数据节点位置 
*/ 
Position First(List L)
{
	return L->Next;
}
/* 
Position Advance(Position P) 
参数 
P 当前节点位置 
返回值 
若P位置后继节点存在则返回其位置，否则返回NULL 
功能 
获得位置P后继节点位置 
*/  
Position Advance(Position P)
{
	Position ret;
	
	if (P != NULL)
		ret = P->Next;
	else
		ret = NULL;
	
	return ret;
}
/* 
Item Retrieve(Position P) 
参数 
P 当前节点位置 
返回值 
若P非空则返回其数据项的值 
功能 
返回P位置的数据项 
*/ 
ElementType Retrieve(Position P)
{
	if (P != NULL)
		return P->Element;
	else
		FatalError("P is null");
}
