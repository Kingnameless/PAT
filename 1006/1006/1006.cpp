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
	int M;char ID[2][16];
	char early[] = "99999999", late[] = "00000000";
	scanf("%d", &M);
	while (M--) {
		char num[16], sign_in[9], sign_out[9];
		scanf("%s%s%s", num, sign_in, sign_out);
		if (strcmp(sign_in, early) < 0) {
			strcpy(early, sign_in);strcpy(ID[0], num);
		}
		if (strcmp(sign_out, late) > 0) {
			strcpy(late, sign_out);strcpy(ID[1], num);
		}
	}
	printf("%s %s", ID[0], ID[1]);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048