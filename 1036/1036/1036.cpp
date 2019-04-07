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
	char maxinf[2][11], mininf[2][11];
	int max = -1, min = 101;
	int M;
	scanf("%d", &M);
	while (M--) {
		char name[11], gen, ID[11];int grade;
		scanf("%s %c %s%d", name, &gen, ID, &grade);
		if(gen=='M')
			if (grade < min) {
				min = grade;strcpy(mininf[0], name);strcpy(mininf[1], ID);
			}
		if(gen=='F')
			if (grade > max) {
				max = grade;strcpy(maxinf[0], name);strcpy(maxinf[1], ID);
			}
	}
	if (max != -1)
		printf("%s %s\n", maxinf[0], maxinf[1]);
	else
		printf("Absent\n");
	if (min != 101)
		printf("%s %s\n", mininf[0], mininf[1]);
	else
		printf("Absent\n");
	if (max != -1 && min != 101)
		printf("%d", max - min);
	else
		printf("NA");
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048