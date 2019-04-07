#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int a[100000], n;
	scanf("%d", &n);
	bool p[100000] = { 0 };int max = -1;
	for (int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
		if (a[i] > max) {
			p[i] = true;max = a[i];
		}
	}
	int min = (1 << 30) - 1;vector<int> res;
	for (int i = n - 1;i >= 0;i--) {
		if (a[i] < min) {
			min = a[i];
			if (p[i]) res.push_back(a[i]);
		}
	}
	sort(res.begin(), res.end());
	if (res.empty()) printf("%d\n\n", 0);
	else {
		printf("%d\n", res.size());
		for (size_t i = 0;i < res.size();i++) {
			if (i != 0) printf(" ");
			printf("%d", res[i]);
		}
	}
	return 0;
}

/*
易错点：当个数为0时，要输出一个空格（坑）
收获：
*/
//未完成：B1048 