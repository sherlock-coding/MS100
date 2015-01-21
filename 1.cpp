/*
 * 把二元查找树转变成排序的双向链表 
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int n;
int *p;

struct BSTreeNode{
	int m_nValue;
	BSTreeNode *m_pLeft;
	BSTreeNode *m_pRight;
};

BSTreeNode * BSTreeCreate(int i)
{
	BSTreeNode *root = NULL;
	if (i >= n)
		return NULL;
	else
		root = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	root->m_nValue = p[i];
	root->m_pLeft = BSTreeCreate(2*i+1);;
	root->m_pRight = BSTreeCreate(2*i+2);;
	
	return root;
}


/* 分别递归地对左右子树进行转换 */
BSTreeNode * TransToList(BSTreeNode *p, bool isLeft)
{
	if(!p)
		return NULL;
	
	BSTreeNode *pre = NULL;
	BSTreeNode *after = NULL;

	pre = TransToList(p->m_pLeft,true);
	after = TransToList(p->m_pRight,false);

	if (pre){
		pre->m_pRight = p;
		p->m_pLeft = pre;
	}

	if (after){
		p->m_pRight = after;
		after->m_pLeft = p;
	}
	


	if (isLeft) {
		while (p->m_pRight != NULL)
			p = p->m_pRight;	
	}
	else {
		while (p->m_pLeft != NULL)
			p = p->m_pLeft;
	}

	return p;
}

/* 利用中序进行转换 */
void MidTransToList(BSTreeNode *p, BSTreeNode * &last)
{
	if (!p)
		return;
	
	MidTransToList(p->m_pLeft,last);
	if (last){
		last->m_pRight = p;
		p->m_pLeft = last;
	}

	last = p;
	MidTransToList(p->m_pRight,last);
	
}

void MidPrint(BSTreeNode *root)
{
	if(!root)
		return ;
	MidPrint(root->m_pLeft);
	cout << root->m_nValue << " ";
	MidPrint(root->m_pRight);
}

void PrintList(BSTreeNode *head)
{
	while (head) {
		cout << head->m_nValue << " ";
		head = head->m_pRight;
	}
}
int main()
{
	int i;

	cin >> n;
	p = new int[n];
	for (i = 0;i < n; i++)
		cin >> p[i];

	BSTreeNode * root = BSTreeCreate(0);
	MidPrint(root);
	cout << endl;

//	BSTreeNode *head = TransToList(root, false);
	BSTreeNode *last = NULL;
	MidTransToList(root,last);
	PrintList(root);
	return 0;
}
