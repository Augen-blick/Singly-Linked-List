#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;  //�Զ����������
typedef struct LNode   //ÿ������������LinkNode��ʾ
{
	ElemType data;
	struct LNode* next;
} LinkNode;

void InitList(LinkNode*& L);                        //��ʼ��������
void DestroyList(LinkNode*& L);                     //���ٵ�����
bool ListEmpty(LinkNode* L);                        //�жϵ������Ƿ�Ϊ�ձ�
int ListLength(LinkNode* L);                        //������ĳ���
void DispList(LinkNode* L);                         //���������
bool GetElem(LinkNode* L, int i, ElemType& e);      //�������i��Ԫ�ص�ֵ
int LocateElem(LinkNode* L, ElemType e);            //��e�ڵ������е�λ��
bool ListInsert(LinkNode*& L, int i, ElemType e);   //��e�����ڵ������i��λ��
bool ListDelete(LinkNode*& L, int i, ElemType& e);  //ɾ���������i��Ԫ��
void CreateListF(LinkNode*& L, ElemType a[], int n);//ͷ�巨
void CreateListR(LinkNode*& L, ElemType a[], int n);//β�巨

void InitList(LinkNode*& L)                        //��ʼ��������
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

void DestroyList(LinkNode*& L)                     //���ٵ�����
{
	LinkNode* pre = L, * p = L->next;   //preָ����p��ǰ�����
	while (p != NULL)
	{
		free(pre);                      //�ͷ�pre���
		pre = p;                        //pre��pͬ������һ�����
		p = pre->next;
	}
	free(pre);                          //ѭ������ʱpΪNULL��preָ��β��㣬�ͷ���
}

bool ListEmpty(LinkNode* L)                        //�жϵ������Ƿ�Ϊ�ձ�
{
	return(L->next == NULL);
}

int ListLength(LinkNode* L)                        //������ĳ���
{
	int i = 0;
	LinkNode* p = L;                   //pָ��ͷ��㣬i��Ϊ0(��ͷ�������Ϊ0)
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

void DispList(LinkNode* L)                         //���������
{
	LinkNode* p = L->next;                  //pָ���׽��
	while (p)                               //p��ΪNULL�����p����data��
	{
		cout << p->data << " ";
		p = p->next;                        //p������һ�����
	}
	cout << endl;
}

bool GetElem(LinkNode* L, int i, ElemType& e)      //�������i��Ԫ�ص�ֵ
{
	int j = 0;
	LinkNode* p = L;                        //pָ��ͷ���,j��Ϊ0(��ͷ�������Ϊ0)
	if (i <= 0)                             //i���󷵻�false
		return false;
	while (j < i && p != NULL)              //�ҵ���i�����
	{
		j++;
		p = p->next;
	}
	if (p == NULL)                          //�����ڵ�i�����ݽ�㣬����false
		return false;
	else                                    //���ڵ�i�����ݽ�㣬�����ݸ���e������true
	{
		e = p->data;
		return true;
	}
}

int LocateElem(LinkNode* L, ElemType e)            //��e�ڵ������е�λ��
{
	int i = 1;
	LinkNode* p = L->next;                 //��pָ���׽�㣬i��Ϊ1(���׽��ľ��Ϊ1)
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)                         //������e������0
		return 0;
	else                                   //����e�������߼����i
		return i;
}

bool ListInsert(LinkNode*& L, int i, ElemType e)   //��e�����ڵ������i��λ��
{
	int j = 0;
	LinkNode* p = L, * s;               //pָ��ͷ��㣬j��Ϊ0(��ͷ�������Ϊ0)
	if (i <= 0)                         //i���󣬷���false
		return false;
	while (p != NULL && j < i - 1)      //���ҵ�i-1�����p
	{
		j++;
		p = p->next;
	}
	if (p == NULL)                      //û�е�i-1����㣬����false
		return false;
	else                                //�ҵ���i-1�����p�������½�㲢����true
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;                    //�����½��s����data����Ϊe
		s->next = p->next;				//�����s���뵽���p֮��
		p->next = s;
		return true;
	}
}

bool ListDelete(LinkNode*& L, int i, ElemType& e)  //ɾ���������i��Ԫ��
{
	int j = 0;
	LinkNode* p = L, * q;                    //pָ��ͷ��㣬j��Ϊ0(��ͷ�������Ϊ0)
	if (i <= 0)                         //i���󣬷���false
		return false;
	while (p != NULL && j < i - 1)      //���ҵ�i-1�����
	{
		j++;
		p = p->next;
	}
	if (p == NULL)                       //û�е�i-1����㣬����false
		return false;
	else                                 //�ҵ���i-1�����
	{
		q = p->next;                     //qָ���i�����
		if (q == NULL)                   //�������ڵ�i�����,����false
			return false;
		e = q->data;
		p->next = q->next;				 //�ӵ�������ɾ��q���
		free(q);                         //�ͷ�q���
		return true;					 //����true��ʾ�ɹ�ɾ����i�����
	}
}

void CreateListF(LinkNode*& L, ElemType a[], int n)//ͷ�巨
{
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;					//����ͷ��㣬��next����ΪNULL
	for (int i = 0; i < n; i++)     //ѭ���������ݽ��s
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];             //�������ݽ��s
		s->next = L->next;          //�����s���뵽ԭ�׽��֮ǰ��ͷ���֮��
		L->next = s;
	}
}

void CreateListR(LinkNode*& L, ElemType a[], int n)//β�巨
{
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));       //����ͷ���
	r = L;                                         //rʼ��ָ��β��㣬��ʼʱָ��ͷ���
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];							   //�������ݽ��s
		r->next = s;							   //�����s���뵽���r֮��
		r = s;
	}
	r->next = NULL;                                //β����next����ΪNULL
}