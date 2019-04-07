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
#define R (long long)10e10
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	long long ABC[3][3] = { 0 };
	int T;
	scanf("%d", &T);
	for (int i = 0;i < T;i++) { 
		scanf("%lld %lld %lld", &ABC[0][0], &ABC[0][1], &ABC[0][2]);
		ABC[1][0] = ABC[0][0] / R;ABC[2][0] = ABC[0][0] % R;
		ABC[1][1] = ABC[0][1] / R;ABC[2][1] = ABC[0][1] % R;
		ABC[1][2] = ABC[0][2] / R;ABC[2][2] = ABC[0][2] % R;
		ABC[2][0] = (ABC[2][0] + ABC[2][1]) % R;
		ABC[1][0] = ABC[1][0] + ABC[1][1] + (ABC[2][0] + ABC[2][1]) / R;
		if (ABC[1][0] > ABC[1][2])
			printf("Case #%d: true\n", i + 1);
		else
			if (ABC[1][0] < ABC[1][2])
				printf("Case #%d: false\n", i + 1);
			else
				if (ABC[2][0] > ABC[2][2])
					printf("Case #%d: true\n", i + 1);
				else
					printf("Case #%d: false\n", i + 1);
	}
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048