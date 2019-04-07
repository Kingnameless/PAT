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
struct Poly {
	double coe;
	int exp;
};
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif   
	double poly[2002] = { 0 };Poly a[2][10] = { 0 };
	for (int i = 0;i < 2;i++) {
		int K;scanf("%d", &K);
		for (int j = 0;j < K;j++)
			scanf("%d%lf", &a[i][j].exp, &a[i][j].coe);
	}
	for (int i = 0;i < 10;i++) {
		if (a[0][i].coe != 0)
			for (int j = 0;j < 10;j++)
				poly[a[0][i].exp + a[1][j].exp] += a[0][i].coe*a[1][j].coe;
	}
	for (int i = 0;i <= 2000;i++)
		if (poly[i] != 0) poly[2001]++;
	printf("%d", (int)poly[2001]);
	for (int i = 2000;i >= 0;i--)
		if (poly[i] != 0)
			printf(" %d %.1f", i, poly[i]);
	return 0;
}
