#include<stdio.h>
#include<iostream>
using namespace std;
struct node {
	int data;
	node *LChild, *RChild;
	node(int d = 0, node* l = NULL, node* r = NULL) :data(d), LChild(l), RChild(r) {}
};
node* root = NULL;
void create(node* &root) {
	char op[5];
	if (cin >> op) {
		if (op[1] != 'o') {
			int x;cin >> x;
			root = new node(x);
			create(root->LChild);
			create(root->RChild);
		}
	}
}
int cnt = 0;
void postOrder(node* root) {
	if (root == NULL) return;
	postOrder(root->LChild);
	postOrder(root->RChild);
	if (cnt != 0) printf(" ");
	cnt++;
	printf("%d", root->data);
}
int main() {
	int n;cin >> n;
	create(root);
	postOrder(root);
	return 0;
}


/*
易错点：
收获：这道题的第一个数据n并没有什么用
柳神题解:https://www.liuchuo.net/archives/2168值得借鉴
*/
//未完成：B1048 