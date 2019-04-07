#include<stdio.h>
using namespace std;

int main() {
	char week[7][4] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	char strings[4][61];int i;
	scanf("%s%s%s%s", strings[0], strings[1], strings[2], strings[3]);
	for (i = 0;strings[0][i] != '\0'&&strings[1][i] != '\0';i++)
		if (strings[0][i] == strings[1][i] && strings[0][i] >= 'A'&&strings[0][i] <= 'G') {
			printf("%s ", week[strings[0][i] - 'A']);break;
		}
	for (i = i + 1;strings[0][i] != '\0'&&strings[1][i] != '\0';i++)
		if (strings[0][i] == strings[1][i])
			if (strings[0][i] >= '0'&&strings[0][i] <= '9') {
				printf("%02d", strings[0][i] - '0');break;
			}
			else
				if (strings[0][i] >= 'A'&&strings[0][i] <= 'N') {
					printf("%02d", strings[0][i] - 'A' + 10);break;
				}
	for (int j = 0;strings[2][j] != '\0'&&strings[3][j] != '\0';j++)
		if (strings[2][j] == strings[3][j] && ((strings[2][j] >= 'a' && strings[2][j] <= 'z') || (strings[2][j] >= 'A' && strings[2][j] <= 'Z'))) {
			printf(":%02d", j);break;
		}
	return 0;
}

//此题题意不明，太坑了
//当题意不明时，先考虑简单情况，无法通过在考虑复杂情况