#include <iostream>
#include "SlList.h"
using namespace std;

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9 };
	LinkNode* L, * L2;

	//ͷ����β���½�������
	CreateListF(L, a, 9);
	CreateListR(L2, a, 9);

	//ɾ��Ԫ��
	int e;
	ListDelete(L, 3, e);
	cout << "ɾ����Ԫ���ǣ�" << e << endl;

	//����������
	DispList(L);

	//��ȡԪ��λ��
	int y = 4;
	cout << y << "�ڱ��е�λ����" << LocateElem(L, y) << endl;

	//ʹ����Ż��Ԫ��
	int z;
	GetElem(L, 6, z);
	cout << "���е�6λԪ��λ���ǣ�" << z << endl;

	//����Ԫ��
	int x = 0;
	ListInsert(L, 9, x);
	cout << "�ڱ�ĵ�9λ����" << x << endl;

	//����������
	DispList(L);

	//����������
	DispList(L);
	DispList(L2);

	//���ٵ�����
	DestroyList(L);
	DestroyList(L2);

	return 0;
}