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

int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int N, b;
	scanf("%d%d", &N, &b);
	if (N == 0) {
		printf("Yes\n0");return 0;
	}
	int pal[32] = { 0 };
	int i = 0;
	while (N > 0) {
		pal[i++] = N % b;N /= b;
	}
	for (int j = 0;j < i;j++)
		if (pal[j] != pal[i - 1 - j]) pal[31] = 1;
	if (pal[31]) printf("No\n");
	else printf("Yes\n");
	while (i--) {
		printf("%d", pal[i]);
		if (i != 0) printf(" ");
	}
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048(A1031,A1019)