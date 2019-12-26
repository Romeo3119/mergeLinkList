#include <iostream>

using namespace std;

typedef int SLDataType;

typedef struct SLNode{
	SLDataType data;
	struct SLNode* _next;
}SLNode;

typedef SLNode SList;

//初始化
void initLinkList(SLNode* pHead)
{
	pHead->_next = nullptr;
	cout << "链表初始化完毕!" << endl;
}

//申请新节点
SLNode* buyNewNode()
{
	SLNode* newNode = new SLNode();
	return newNode;
}

//尾插
void pushBackData(SLNode* pHead, SLDataType data)
{
	SLNode* newNode = buyNewNode();
	newNode->data = data;
	//链表为空
	if (pHead->_next == nullptr)
	{
		newNode->_next = pHead->_next;
		pHead->_next = newNode;
		return;
	}

	//不为空
	SLNode* pCur = pHead->_next;
	while (pCur->_next != nullptr)
	{
		pCur = pCur->_next;
	}
	pCur->_next = newNode;
	newNode->_next = nullptr;
}

//合并两个有序链表
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
//打印
void printLinkList(SLNode* pHead)
{
	if (pHead->_next == nullptr)
	{
		cout << "链表为空!" << endl;
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