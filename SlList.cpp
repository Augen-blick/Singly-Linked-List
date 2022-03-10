#include <iostream>
#include "SlList.h"
using namespace std;

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9 };
	LinkNode* L, * L2;

	//头插与尾插新建单链表
	CreateListF(L, a, 9);
	CreateListR(L2, a, 9);

	//删除元素
	int e;
	ListDelete(L, 3, e);
	cout << "删除的元素是：" << e << endl;

	//遍历单链表
	DispList(L);

	//获取元素位置
	int y = 4;
	cout << y << "在表中的位置是" << LocateElem(L, y) << endl;

	//使用序号获得元素
	int z;
	GetElem(L, 6, z);
	cout << "表中第6位元素位置是：" << z << endl;

	//插入元素
	int x = 0;
	ListInsert(L, 9, x);
	cout << "在表的第9位插入" << x << endl;

	//遍历单链表
	DispList(L);

	//遍历单链表
	DispList(L);
	DispList(L2);

	//销毁单链表
	DestroyList(L);
	DestroyList(L2);

	return 0;
}