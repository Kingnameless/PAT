#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define MAX 100
int main() {       //数组循环右移
#ifdef ONLINE_JUDGE
#else
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif
	int a[MAX] = { 0 };
	int N, M;
	scanf("%d%d", &N, &M);
	M %= N;cout << M << endl;
	for (int i = 0;i < N;i++)
		scanf("%d", &a[i]);
	int d = M;
	while (N%d != 0 || M%d != 0)
		d--;
	cout << d << endl;
	int temp, count = 0;
	for (int i = N - M;i <= N-M+d-1;i++) {
		temp = a[i];
		int k = i;
		while (k != (i + M) % N) {
			a[k] = a[(k - M + N) % N];
			k = (k - M + N) % N;
			count++;
		}
		a[k] = temp;
	}
	for (int i = 0;i < N;i++)
		printf("%d ", a[i]);
	cout << "\n" << count << endl;
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048
