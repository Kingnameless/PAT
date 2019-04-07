#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	int s = (int)sqrt(1.0*N);
	int start = 2, Len = 0;
	for (int i = start ;i <= s;i++) {
		int j = 0, temp = 1;
		while (true) {
			temp *= (i + j);
			if (!(N%temp) == 0) break;
			if (j + 1 > Len) {
				start = i;Len = j + 1;
			}
			j++;
		}
	}
	if (Len == 0)
		printf("1\n%d", N);
	else {
		printf("%d\n%d", Len, start);
		for (int i = 1;i<Len;i++)
			printf("*%d", start + i);
	}
	return 0;
}
//写代码之前先理清算法流程
//考虑时间复杂度
//先整体后局部
//@@@@@注意2~sqrt(N)之间不存在被N整除的数的情况