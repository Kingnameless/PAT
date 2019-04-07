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
	char result[4] = "WTL";
	double weight = 1.0;char res[3];
	for (int i = 0;i < 3;i++) {
		double max = 0.0;
		for (int j = 0;j < 3;j++) {
			double odd;scanf("%lf", &odd);
			if (odd > max) {
				max = odd;res[i] = result[j];
			}
		}
		weight *= max;
	}
	printf("%c %c %c %.2f", res[0], res[1], res[2], 2 * (weight*0.65 - 1));
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048