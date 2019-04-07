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
	char str[81];
	scanf("%s", str);
	int n = strlen(str);
	int H = (n + 2) / 3 < (n - 1) / 2 ? (n + 2) / 3 : (n - 1) / 2;
	int W = n - 2 * H + 2;
	for (int i = 0;i < H-1;i++) {
		printf("%c",str[i]);
		for (int j = 0;j < W-2;j++) printf(" ");
		printf("%c\n", str[n - 1 - i]);
	}
	for (int j = 0;j < W;j++)
		printf("%c", str[H -1+ j]);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048