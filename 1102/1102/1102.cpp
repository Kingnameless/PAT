#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 11;
struct node {
	int Lc, Rc;
	node(int l=-1,int r=-1):Lc(l),Rc(r){}
};
bool flag[maxn] = { 0 };
node val[maxn];
int cnt = 0;
void InOrder(int root) {
	if (root == -1) return;
	InOrder(val[root].Lc);
	if (cnt != 0) printf(" ");
	printf("%d", root);cnt++;
	InOrder(val[root].Rc);
}
void LayerOrder(int root) {
	queue<int> q;
	q.push(root);
	int p;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (cnt != 0) printf(" ");
		printf("%d", p);cnt++;
		if (val[p].Lc != -1) q.push(val[p].Lc);
		if (val[p].Rc != -1) q.push(val[p].Rc);
	}
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C:/Users/Administrator.WIN-20160308UMZ/Desktop/PG/PAT/input.txt", "r", stdin);
#endif    
	int n;
	scanf("%d", &n);getchar();
	for (int i = 0;i < n;i++) {
		char L, R;
		scanf("%c %c", &R, &L);getchar();
		if (L != '-') {
			val[i].Lc = L - '0';flag[L - '0'] = true;
		}
		if (R != '-') {
			val[i].Rc = R - '0';flag[R - '0'] = true;
		}
	}
	int root;
	for(int i=0;i<n;i++)
		if (!flag[i]) {
			root = i;break;
		}
	LayerOrder(root);
	cnt = 0;
	cout << endl;
	InOrder(root);
	return 0;
}

/*
易错点：反转二叉树就是存储的时候所有左右结点都交换。
收获：
*/
