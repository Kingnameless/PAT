#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int solve(int n) {
	int a[4] = { n / 1000,n % 1000 / 100,n % 100 / 10,n % 10 };
	sort(a, a + 4);
	int s1 = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
	int s2= a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
	printf("%04d - %04d = %04d\n", s2, s1, s2 - s1);
	return s2 - s1;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int n;scanf("%d", &n);
	if (n == 6174) solve(n);
	while (n != 0 && n != 6174)
		n = solve(n);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 