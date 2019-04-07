#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<Windows.h>
using namespace std;

int main() {
	int month[2][12] =
	{ 31,28,31,30,31,30,31,31,30,31,30,31,
	  31,29,31,30,31,30,31,31,30,31,30,31 };
	int date1, date2;
	scanf("%d%d", &date1, &date2);
	int temp;
	if (date1 < date2) {
		temp = date1;
		date1 = date2;
		date2 = temp;
	}
	int day = 1;
	while (date1 != date2) {
		date2++;day++;
		int y = date2 / 10000, m = date2 % 10000 / 100, d = date2 % 100;
		if (d > month[(y % 4 == 0 && y % 100 != 0) || y % 400 == 0][m-1]) {
			date2 = date2 - d + 101;
			if (m > 12)
				date2 = date2 - 1200 + 10000;
		}
	}
	printf("%d\n", day);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048
