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
	char A[10000];
	char f, a;
	scanf("%c%c", &f, &a);
	scanf(".%s", A);
	int i = 0;
	while (A[i] != 'E') i++;
	int j = i + 2;
	while (A[j] != '\0') j++;
	int exp = 0;
	for (int k = i + 2;k < j;k++) {
		exp *= 10;exp += A[k] - '0';
	}
	if (f == '-') printf("-");
	if (A[i + 1] == '+') {
		printf("%c", a);
		if (exp < i) 
			for (int k = 0;k < i;k++) {
				if (k == exp) printf(".");
				printf("%c", A[k]);
			}
		else
			for (int k = 0;k < exp;k++)
				if (k < i)
					printf("%c", A[k]);
				else
					printf("0");
	}
	else {
		printf("0.");
		while (--exp > 0) printf("0");
		printf("%c", a);
		for (int k = 0;k < i;k++)
			printf("%c", A[k]);
	}
	return 0;
}
//考虑要周全不要漏掉某些情况
//最好多动动笔
