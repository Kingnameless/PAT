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
	int lottery[10001] = { 0 };
	int n;scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		int number;scanf("%d", &number);
		if (lottery[number] > 0)
			lottery[number] = -1;
		else
			if (lottery[number] == 0)
				lottery[number] = i;
	}
	int minOrder = n + 1, minNum;
	for (int i = 1;i < 10001;i++) {
		if (lottery[i] > 0)
			if (lottery[i] < minOrder) {
				minOrder = lottery[i];
				minNum = i;
			}
	}
	if (minOrder == n + 1)
		printf("None");
	else
		printf("%d", minNum);
	return 0;
}

/*
�״�㣺
�ջ�//�븴���ˣ�ֻҪ���������ִ��������У�Ȼ������˳�����ĸ�ֻ����һ�ξ���
*/
//δ��ɣ�B1048