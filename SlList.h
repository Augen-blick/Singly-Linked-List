#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;  //自定义类型语句
typedef struct LNode   //每个结点的类型用LinkNode表示
{
	ElemType data;
	struct LNode* next;
} LinkNode;

void InitList(LinkNode*& L);                        //初始化单链表
void DestroyList(LinkNode*& L);                     //销毁单链表
bool ListEmpty(LinkNode* L);                        //判断单链表是否为空表
int ListLength(LinkNode* L);                        //求单链表的长度
void DispList(LinkNode* L);                         //输出单链表
bool GetElem(LinkNode* L, int i, ElemType& e);      //求单链表第i个元素的值
int LocateElem(LinkNode* L, ElemType e);            //求e在单链表中的位置
bool ListInsert(LinkNode*& L, int i, ElemType e);   //将e插入在单链表第i个位置
bool ListDelete(LinkNode*& L, int i, ElemType& e);  //删除单链表第i个元素
void CreateListF(LinkNode*& L, ElemType a[], int n);//头插法
void CreateListR(LinkNode*& L, ElemType a[], int n);//尾插法

void InitList(LinkNode*& L)                        //初始化单链表
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

void DestroyList(LinkNode*& L)                     //销毁单链表
{
	LinkNode* pre = L, * p = L->next;   //pre指向结点p的前驱结点
	while (p != NULL)
	{
		free(pre);                      //释放pre结点
		pre = p;                        //pre、p同步后移一个结点
		p = pre->next;
	}
	free(pre);                          //循环结束时p为NULL，pre指向尾结点，释放它
}

bool ListEmpty(LinkNode* L)                        //判断单链表是否为空表
{
	return(L->next == NULL);
}

int ListLength(LinkNode* L)                        //求单链表的长度
{
	int i = 0;
	LinkNode* p = L;                   //p指向头结点，i置为0(即头结点的序号为0)
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

void DispList(LinkNode* L)                         //输出单链表
{
	LinkNode* p = L->next;                  //p指向首结点
	while (p)                               //p不为NULL，输出p结点的data域
	{
		cout << p->data << " ";
		p = p->next;                        //p移向下一个结点
	}
	cout << endl;
}

bool GetElem(LinkNode* L, int i, ElemType& e)      //求单链表第i个元素的值
{
	int j = 0;
	LinkNode* p = L;                        //p指向头结点,j置为0(即头结点的序号为0)
	if (i <= 0)                             //i错误返回false
		return false;
	while (j < i && p != NULL)              //找到第i个结点
	{
		j++;
		p = p->next;
	}
	if (p == NULL)                          //不存在第i个数据结点，返回false
		return false;
	else                                    //存在第i个数据结点，将数据赋给e并返回true
	{
		e = p->data;
		return true;
	}
}

int LocateElem(LinkNode* L, ElemType e)            //求e在单链表中的位置
{
	int i = 1;
	LinkNode* p = L->next;                 //将p指向首结点，i置为1(即首结点的句号为1)
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)                         //不存在e，返回0
		return 0;
	else                                   //存在e，返回逻辑序号i
		return i;
}

bool ListInsert(LinkNode*& L, int i, ElemType e)   //将e插入在单链表第i个位置
{
	int j = 0;
	LinkNode* p = L, * s;               //p指向头结点，j置为0(即头结点的序号为0)
	if (i <= 0)                         //i错误，返回false
		return false;
	while (p != NULL && j < i - 1)      //查找第i-1个结点p
	{
		j++;
		p = p->next;
	}
	if (p == NULL)                      //没有第i-1个结点，返回false
		return false;
	else                                //找到第i-1个结点p，插入新结点并返回true
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;                    //创建新结点s，其data域置为e
		s->next = p->next;				//将结点s插入到结点p之后
		p->next = s;
		return true;
	}
}

bool ListDelete(LinkNode*& L, int i, ElemType& e)  //删除单链表第i个元素
{
	int j = 0;
	LinkNode* p = L, * q;                    //p指向头结点，j置为0(即头结点的序号为0)
	if (i <= 0)                         //i错误，返回false
		return false;
	while (p != NULL && j < i - 1)      //查找第i-1个结点
	{
		j++;
		p = p->next;
	}
	if (p == NULL)                       //没有第i-1个结点，返回false
		return false;
	else                                 //找到第i-1个结点
	{
		q = p->next;                     //q指向第i个结点
		if (q == NULL)                   //若不存在第i个结点,返回false
			return false;
		e = q->data;
		p->next = q->next;				 //从单链表中删除q结点
		free(q);                         //释放q结点
		return true;					 //返回true表示成功删除第i个结点
	}
}

void CreateListF(LinkNode*& L, ElemType a[], int n)//头插法
{
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;					//创建头结点，其next域置为NULL
	for (int i = 0; i < n; i++)     //循环建立数据结点s
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];             //创建数据结点s
		s->next = L->next;          //将结点s插入到原首结点之前，头结点之后
		L->next = s;
	}
}

void CreateListR(LinkNode*& L, ElemType a[], int n)//尾插法
{
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));       //创建头结点
	r = L;                                         //r始终指向尾结点，初始时指向头结点
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];							   //创建数据结点s
		r->next = s;							   //将结点s插入到结点r之后
		r = s;
	}
	r->next = NULL;                                //尾结点的next域置为NULL
}