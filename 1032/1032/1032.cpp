#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct node {
	int next, vist;
};
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int s1, s2, n;
	scanf("%d%d%d", &s1, &s2, &n);
	node LinkList[100000];
	while (n--) {
		int address;char c;
		scanf("%d %c", &address, &c);
		scanf("%d", &LinkList[address].next);LinkList[address].vist = 0;
	}
	while (LinkList[s1].next != -1) {
		LinkList[s1].vist = 1;
		s1 = LinkList[s1].next;
	}
	while (LinkList[s2].next != -1) {
		if (LinkList[s2].vist == 1) {
			printf("%05d", s2);return 0;
		}
		s2 = LinkList[s2].next;
	}
	printf("-1");
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 