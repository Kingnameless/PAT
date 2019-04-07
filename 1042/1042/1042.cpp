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
	int K;char s[6] = "SHCDJ";
	scanf("%d", &K);
	int pos[55] = { 0 }, order[55] = { 0 }, NowPos[55] = { 0 };
	for (int i = 1;i < 55;i++) {
		scanf("%d", &order[i]);
		pos[i] = i;
	}
	while (K--) {
		for (int i = 1;i < 55;i++)
			NowPos[order[i]] = pos[i];
		for (int i = 1;i < 55;i++)
			pos[i] = NowPos[i];
	}
	for (int i = 1;i < 55;i++) {
		printf("%c%d", s[(pos[i] - 1) / 13], (pos[i] - 1) % 13 + 1);
		if (i != 54) printf(" ");
	}
	return 0;
}

/*
易错点：如果只用一个数组，原数组元素会被覆盖
收获：空间换时间
*/
//未完成：B1048