#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define LL long long
/*LL seq[100000];//二分法
int n, p;
int perfectSeq(int left, int right) {
	int mid;LL m = seq[left - 1];
	if (seq[right] <= m * p) return right + 1;//整个序列都满足的特殊情况
	while (left < right) {
		mid = (left + right) / 2;
		if (seq[mid] > m * p)
			right = mid;
		else
			left = mid + 1;
}
	return left;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	scanf("%d%d", &n, &p);
	for (int i = 0;i < n;i++)
		scanf("%lld", &seq[i]);
	sort(seq, seq + n);
	int Max = -1;
	for (int i = 0;i < n;i++) {
		Max = max(Max, perfectSeq(i + 1, n - 1) - i);
		if (Max >= n - i) break;
	}
	printf("%d\n", Max);
	return 0;
}*/

/*
易错点：
收获：复杂度:O(nlogn)
*/
//未完成：B1048 
LL seq[100000];
int n, p;
int twoPoint(int left, int right) {//超时
	if(left<=right){
		if (seq[left] * p >= seq[right]) return right - left + 1;
		return max(twoPoint(left + 1, right), twoPoint(left, right - 1));
	}
	else return 0;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	scanf("%d%d", &n, &p);
	for (int i = 0;i < n;i++)
		scanf("%lld", &seq[i]);
	sort(seq, seq + n);
	int i = 0, j = 0, m = -1;
	while (i < n&&j < n) {
		while (j < n&&seq[i] * p >= seq[j]) j++;
		m = max(m, j - i);
		i++;
	}
	printf("%d", m);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 