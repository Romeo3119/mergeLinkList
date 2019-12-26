#include <iostream>

using namespace std;

typedef int SLDataType;

typedef struct SLNode{
	SLDataType data;
	struct SLNode* _next;
}SLNode;

typedef SLNode SList;

//��ʼ��
void initLinkList(SLNode* pHead)
{
	pHead->_next = nullptr;
	cout << "�����ʼ�����!" << endl;
}

//�����½ڵ�
SLNode* buyNewNode()
{
	SLNode* newNode = new SLNode();
	return newNode;
}

//β��
void pushBackData(SLNode* pHead, SLDataType data)
{
	SLNode* newNode = buyNewNode();
	newNode->data = data;
	//����Ϊ��
	if (pHead->_next == nullptr)
	{
		newNode->_next = pHead->_next;
		pHead->_next = newNode;
		return;
	}

	//��Ϊ��
	SLNode* pCur = pHead->_next;
	while (pCur->_next != nullptr)
	{
		pCur = pCur->_next;
	}
	pCur->_next = newNode;
	newNode->_next = nullptr;
}

//�ϲ�������������
SLNode* mergeLinkList(SLNode* pHead1, SLNode* pHead2)
{
	if (pHead1->_next == nullptr)
	{
		return pHead2;
	}
	if (pHead2->_next == nullptr)
	{
		return pHead1;
	}
	SLNode* pCur = new SLNode();
	SLNode* newHead = pCur;
	SLNode* l1 = pHead1->_next;
	SLNode* l2 = pHead2->_next;

	while (l1 && l2)
	{
		if (l1->data > l2->data)
		{
			pCur->_next = l2;
			l2 = l2->_next;
		}
		else
		{
			pCur->_next = l1;
			l1 = l1->_next;
		}
		pCur = pCur->_next;
	}
	if (l1 == nullptr)
	{
		pCur->_next = l2;
	}
	else
	{
		pCur->_next = l1;
	}
	return newHead;
}
//��ӡ
void printLinkList(SLNode* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "����Ϊ��!" << endl;
		return;
	}

	SLNode* pCur = pHead->_next;
	while (pCur != nullptr)
	{
		cout << pCur->data << "-->";
		pCur = pCur->_next;
	}
	cout << "nullptr";
	cout << endl;
}