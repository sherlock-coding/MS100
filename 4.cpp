/*
 * 在二元树中找出和为某一值的所有路径（树）
 */

#include <iostream>
#include <vector>
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

void print(vector<int> route) 
{
	for (vector<int>::iterator it = route.begin();it!=route.end();it++)
		cout << *it << " ";
	cout << endl;
}

void GetRoutes(BSTreeNode *p, int key, vector<int> &route)
{
	if(!p)
		return;
	if (p->m_pLeft==NULL && p->m_pRight==NULL) {
		if(key == p->m_nValue) {
			route.push_back(p->m_nValue);
			print(route);
			route.pop_back();
		}
		return;
	}

	route.push_back(p->m_nValue);
	GetRoutes(p->m_pLeft, key-p->m_nValue, route);
	GetRoutes(p->m_pRight, key-p->m_nValue, route);
	route.pop_back();
}

int main()
{
	int i;
	vector<int> route;

	cin >> n;
	p = new int[n];
	for (i = 0;i < n; i++)
		cin >> p[i];

	BSTreeNode * root = BSTreeCreate(0);

	GetRoutes(root, 24, route);

	return 0;
}
