/*#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int *pos;
	int left;
	int right;
	Node():pos(NULL),left(0),right(0){}
};
void PI(int *PO, int *IO, int n)
{
	if (n == 0)
		;
	else
	{
		queue<Node> Q;
		Node p, q;
		int i = 0;
		p.pos = PO + n - 1;
		p.left = 0;p.right = n - 1;
		Q.push(p);
		while (!Q.empty())
		{
			p = Q.front();
			Q.pop();i++;
			if (i == n)
				cout << *p.pos;
			else
				cout << *p.pos << " ";
			int k = 0;
			while (*p.pos != *(IO + k)) k++;
			if (k > p.left)
			{
				q.left = p.left;q.right = k - 1;q.pos = p.pos - p.right + k - 1;Q.push(q);
			}
			if (k < p.right)
			{
				q.left = k + 1;q.right = p.right;q.pos = p.pos - 1;Q.push(q);
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int po[30] = { 0 };
	int io[30] = { 0 };
	for (int i = 0;i < n;i++)
	{
		scanf_s("%d", &po[i]);
	}
	for (int i = 0;i < n;i++)
	{
		scanf_s("%d", &io[i]); 
	}
	PI(po, io, n);
	return 0;
}

//注意点：
//1.输入输出最好用printf和scanf  ??有待深究
//2.while(scanf("%d",&n)!=EOF){...} ??有待深究
*/
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 100;
struct node {
	int data;
	node *Lch, *Rch;
	node(int d=0,node* L=NULL,node* R=NULL):data(d),Lch(L),Rch(R){}
};
int postList[maxn], inList[maxn];
node* root = NULL;
node* BulitTree(int pL, int pR, int iL, int iR) {
	if (pL > pR) return NULL;
	int k = iL;
	while (inList[k] != postList[pR]) k++;
	node* root = new node(postList[pR]);
	root->Lch = BulitTree(pL, pL + k - iL - 1, iL, k - 1);
	root->Rch = BulitTree(pL + k - iL, pR - 1, k + 1, iR);
	return root;
}
void LayerOrder(node* root) {
	queue<node*> q;
	q.push(root);
	node* p;
	bool first = true;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (first) {
			printf("%d", p->data);first = false;
		}
		else printf(" %d", p->data);
		if (p->Lch) q.push(p->Lch);
		if (p->Rch) q.push(p->Rch);
	}
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", &postList[i]);
	for (int i = 0;i < n;i++)
		scanf("%d", &inList[i]);
	root = BulitTree(0, n-1, 0, n-1);
	LayerOrder(root);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 
