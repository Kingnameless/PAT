#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#define MAX 0x3f3f3f3f
using namespace std;

int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif   
	int n, m, sum[100001], D[100001];
	scanf("%d%d", &n, &m);
	sum[0] = 0;
	for (int i = 1;i <= n;i++) {
		scanf("%d", &D[i]);
		sum[i] = sum[i - 1] + D[i];
	}
	int i, Min = MAX, pos1, pos2;
	bool flag = false;
	for (i = 1;i <= n;i++) {
		pos1 = lower_bound(sum + i, sum + n + 1, m + sum[i] - D[i]) - sum;
		if (pos1<n+1&&sum[pos1] - sum[i] + D[i] == m) {
			printf("%d-%d\n", i, pos1);flag = true;
		}
		pos2 = upper_bound(sum + i, sum + n + 1, m + sum[i] - D[i]) - sum;
		if (pos2 < n + 1) Min = min(Min, sum[pos2] - sum[i] + D[i]);
	}
	if (!flag) {
		for (i = 1;i <= n;i++) {
			pos2 = upper_bound(sum + i, sum + n + 1, m + sum[i] - D[i]) - sum;
			if(pos2<n+1&& (sum[pos2] - sum[i] + D[i])==Min)
				printf("%d-%d\n", i, pos2);
		}
	}
	return 0;
}

/*
易错点：
收获：适当使用函数可简化代码
*/
//未完成：B1048 