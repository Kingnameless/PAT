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
	char rad[] = "0123456789ABC";
	int R, G, B;
	scanf("%d%d%d", &R, &G, &B);
	printf("#%c%c%c%c%c%c", rad[R / 13], rad[R % 13], rad[G / 13], rad[G % 13], rad[B / 13], rad[B % 13]);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048(A1031,A1019,A1027)