#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int mod = 1000000007;
/*
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int Apos[100000] = { 0 };
	char s[100001];
	scanf("%s", s);
	int len = strlen(s);
	int	count = 0;
	for (int i = 0;i < len;i++) {
		if (s[i] == 'P') count++;
		if (s[i] == 'A') Apos[i] = count;
	}
	int sum = 0;count = 0;
	for (int i = len - 1;i >= 0;i--) {
		if (s[i] == 'T') count++;
		if (s[i] == 'A') sum = (sum + Apos[i] * count%mod) % mod;
	}
	printf("%d", sum);
	return 0;
}*/

/*
易错点：
收获：
*/
//未完成：B1048 
//更好的方法

int main() {
#ifdef ONLINE_JUDGE
#else
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif
	char s[100001];
	scanf("%s", s);
	int p = 0, a = 0, t = 0, len = strlen(s);
	for (int i = 0;i < len;i++) {
		if (s[i] == 'P') p++;
		if (s[i] == 'A') {
			a += p;a %= mod;
		}
		if (s[i] == 'T') {
			t += a;t %= mod;
		}
	}
	printf("%d", t);
	return 0;
}