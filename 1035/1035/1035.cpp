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
	char name[1000][11], password[1000][11];
	int N, modifyNum = 0;
	bool flag[1000] = { 0 };
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%s%s", name[i], password[i]);
		for (int j = 0;password[i][j] != '\0';j++) {
			if (password[i][j] == '1') {
				password[i][j] = '@';flag[i] = true;continue;
			}
			if (password[i][j] == '0') {
				password[i][j] = '%';flag[i] = true;continue;
			}
			if (password[i][j] == 'l') {
				password[i][j] = 'L';flag[i] = true;continue;
			}
			if (password[i][j] == 'O') {
				password[i][j] = 'o';flag[i] = true;continue;
			}
		}
		if (flag[i]) modifyNum++;
	}
	if (modifyNum == 0)
		if (N > 1)
			printf("There are %d accounts and no account is modified", N);
		else
			printf("There are 1 account and no account is modified");
	else {
		printf("%d\n", modifyNum);
		for (int i = 0;i < N;i++)
			if (flag[i])
				printf("%s %s\n", name[i], password[i]);
	}
	return 0;
}

/*
�״�㣺1.�ô���һ��Ҫ��ϸ��������2.ע��N=1��N>1���������ǲ�ͬ�ģ��ӣ���
�ջ�
*/