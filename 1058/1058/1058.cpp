#include<iostream>
#include<stdio.h>
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


	int g1, g2, s1, s2, k1, k2;
	scanf("%d.%d.%d", &g1, &s1, &k1);
	scanf("%d.%d.%d", &g2, &s2, &k2);
	printf("%d.%d.%d", (s1 + s2 + (k1 + k2) / 29) / 17 + g1 + g2, (s1 + s2 + (k1 + k2) / 29) % 17, (k1 + k2) % 29);
	return 0;
}

