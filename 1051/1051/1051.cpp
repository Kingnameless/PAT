#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int PushSeq[1001];
bool Judge(int a[], int n,int m) {
	stack<int> s;
	int i = 1, j = 1;
	while (i <= n) {
		if (s.empty() || s.top() != a[i]) {
			if (j > n) return false;
			s.push(PushSeq[j++]);
			if (s.size() > m) return false;
		}
		else {
			i++;s.pop();
		}
	}
	return true;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	for (int i = 1;i <= n;i++)
		PushSeq[i] = i;
	int a[1001];
	while (k--) {
		for (int i = 1;i <= n;i++)
			scanf("%d", &a[i]);
		if (Judge(a, n, m)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 