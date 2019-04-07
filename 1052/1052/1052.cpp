#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct node {
	int key, next, Address;
	int flag;
};
node LinkList[100000] = { 0 };
bool cmp(node& a, node& b) {
	if (a.flag != b.flag) return a.flag > b.flag;
	else return a.key < b.key;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int n, a;scanf("%d%d", &n, &a);
	if (a == -1) {
		printf("0 -1");return 0;
	}
	for (int i = 0;i < n;i++) {
		int adr;scanf("%d", &adr);LinkList[adr].Address = adr;
		scanf("%d%d", &LinkList[adr].key, &LinkList[adr].next);
	}
	int count = 0;
	while (a != -1) {
		LinkList[a].flag = 1;count++;
		a = LinkList[a].next;
	}
	sort(LinkList, LinkList + 100000, cmp);
	printf("%d %05d\n", count, LinkList[0].Address);
	for (int i = 0;i < count;i++) {
		printf("%05d %d ", LinkList[i].Address, LinkList[i].key);
		if (i < count - 1) printf("%05d\n", LinkList[i + 1].Address);
		else printf("-1\n");
	}
	return 0;
}

/*
易错点：1.当首地址为-1时，链表为空
       2.输入的结点并不全是链表上的结点
收获：
*/
//未完成：B1048 