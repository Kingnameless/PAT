#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> temp, ans;
int n, k, p, maxs = -1, MaxFac;
void DFS(int i, int num, int sum, int sums) {//将i从大到小枚举，可避免字典序的判断
	if (num == k&&sums == n) {
		if (sum > maxs) {
			maxs = sum;ans = temp;
		}
		return;
	}
	if (i < 1 || num > k || sums > n) return;
	temp.push_back(i);
	DFS(i, num + 1, sum + i, sums + (int)pow(i, p));
	temp.pop_back();
	DFS(i - 1, num, sum, sums);
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	scanf("%d%d%d", &n, &k, &p);
	MaxFac = (int)sqrt(n - k + 1) + 1;
	DFS(MaxFac, 0, 0, 0);
	if (ans.empty()) {
		printf("Impossible");return 0;
	}
	printf("%d = ", n);
	for (size_t i = 0;i < ans.size();i++) {
		if (i != 0) printf(" + ");
		printf("%d^%d", ans[i], p);
	}
	return 0;
}

/*
易错点：尽量在DFS中使用O(1)的判断，不然容易超时
收获：
*/
//未完成：B1048 