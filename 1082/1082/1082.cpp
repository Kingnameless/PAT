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
char num[10][5] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
char wei[5][5] = { "Shi","Bai","Qian","Wan","Yi" };

int main() {
	char s[11];
	scanf("%s", s);
	int len = strlen(s);
	int left = 0, right = len - 1;
	if (s[0] == '-') {
		printf("Fu");left++;
	}
	bool HaveZero = false;
	while (right - left > 3) right -= 4;
	while (left < len) {
		bool PrintWei = false;
		while (left <= right) {
			if (s[left] == '0'&&left > 0) {
				if (PrintWei&&left == right)
					HaveZero = false;
				else
					HaveZero = true;
			}
			else {
				if (left > 0) printf(" ");
				if (HaveZero) {
					printf("ling ");HaveZero = false;
				}
				if (left < right)
					printf("%s %s", num[s[left] - '0'], wei[right - left-1]);
				else
					printf("%s", num[s[left] - '0']);
				PrintWei = true;
			}
			left++;
		}
		if (right != len - 1 && PrintWei) printf(" %s", wei[(len - 1 - right) / 4 + 2]);
		right += 4;
	}
	return 0;
}

/*
易错点：就是想不到啊啊啊啊啊啊
收获：
*/