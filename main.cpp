#include "mergeLinkList.h"

int main()
{
	SList pHead1;
	SList pHead2;

	//≥ı ºªØ
	initLinkList(&pHead1);
	initLinkList(&pHead2);
	//Œ≤≤Â
	cout << "Œ≤≤Â£∫" << endl;
	pushBackData(&pHead1, 1);
	pushBackData(&pHead1, 2);
	pushBackData(&pHead1, 3);
	pushBackData(&pHead1, 4);
	pushBackData(&pHead1, 5);
	printLinkList(&pHead1);

	//Œ≤≤Â
	cout << "Œ≤≤Â£∫" << endl;
	pushBackData(&pHead2, 2);
	pushBackData(&pHead2, 6);
	pushBackData(&pHead2, 7);
	printLinkList(&pHead2);
	
	cout << "∫œ≤¢: ";
	SLNode* newHead = mergeLinkList(&pHead1, &pHead2);
	printLinkList(newHead);
	system("pause");
	return 0;

}