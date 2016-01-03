#ifndef __LIST_H
#define __LIST_H

struct Node;
typedef int 			ElementType;	/*定义数据项类型*/  
typedef struct Node 	*PtrToNode;		/*定义节点指针*/
typedef PtrToNode 		List;			/*定义链表指针*/
typedef PtrToNode 		Position;		/*定义节点位置指针*/

/* 
功能 
生成空链表L 
*/
List MakeEmpty(List L);		
/* 
功能 
判定链表是否为空 
*/ 		
int IsEmpty(List L);
/* 
功能 
判定位置P的节点是否为尾节点 
*/  
int IsLast(Position P, List L);
/* 
功能 
在链表L中查找数据项为E的第一个节点 
*/  
Position Find(ElementType E,List L);
/* 
功能 
在链表L中删除数据项为E的第一个节点 
*/  
void Delete(ElementType E,List L);
/* 
功能 
在链表L中查找数据项为E的第一个节点的前驱位置 
*/ 
Position FindPrevious(ElementType E,List L);
/* 
功能 
删除链表L所有节点 
*/  
void DeleteList(List L);
/* 
功能 
获得链表L中头节点位置 
*/ 
Position Header(List L);
/* 
功能 
获得链表L中第一个数据节点的位置 
*/  
Position First(List L);
/* 
功能 
获得P位置的后继节点位置 
*/ 
Position Advance(Position P);
/* 
功能 
获得P位置节点的数据项 
*/
ElementType Retrieve(Position P);
/* 
功能 
在链表L中P位置插入数据项为E的节点 
*/
List Insert(ElementType E,List L, Position P);

/*节点的定义*/  
struct Node
{
    ElementType Element;	/*数据域*/
    Position Next;			/*链域*/ 
};



#endif

