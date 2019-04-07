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
	int N, D[100000] = { 0 }, total = 0;
	scanf("%d", &N);
	int d;
	for (int i = 1;i <= N;i++) {
		scanf("%d", &d);
		total += d;D[i] = total;
	}
	int M;
	scanf("%d", &M);
	int ex1, ex2;
	while (M--) {
		scanf("%d%d", &ex1, &ex2);
		d = min(fabs(D[ex1 - 1] - D[ex2 - 1]), total - fabs(D[ex1 - 1] - D[ex2 - 1]));
		printf("%d\n", d);
	}
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048