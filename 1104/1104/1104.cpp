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
	int n;scanf("%d", &n);
	double sum = 0, a;
	for (int i = 1;i <= n;i++) {
		scanf("%lf", &a);
		sum += a*i*(n + 1 - i);
	}
	printf("%.2f", sum);
	return 0;
}

/*
易错点：
收获：//纯粹找规律
*/
//未完成：B1048 