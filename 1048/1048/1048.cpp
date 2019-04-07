#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

/*int main() {//散列
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int n, amount;int coin[1001] = { 0 };
	scanf("%d%d", &n, &amount);
	while (n--) {
		int d;scanf("%d", &d);
		coin[d]++;
	}
	int i;
	for (i = 1;i < (amount >> 1) + 1;i++)
		if (coin[i]-->0)
			if (coin[amount - i]-- > 0) {
				printf("%d %d", i, amount - i);break;
			}
	if (i >= (amount >> 1) + 1) printf("No Solution");
	return 0;
}*/

/*
易错点：注意coin的范围不是500，因为amount<1000,所以amount-i可能大于500；
收获：
*/
//未完成：B1048 
/*
int main() {//二分法
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int n, amount, coin[100000];
	scanf("%d%d", &n, &amount);
	for (int i = 0;i < n;i++)
		scanf("%d", &coin[i]);
	sort(coin, coin + n);
	for (int i = 0;i < n;i++) {
		int pos = lower_bound(coin + i + 1, coin + n, amount - coin[i]) - coin;
		if (pos < n&&coin[pos] + coin[i] == amount) {
			printf("%d %d", coin[i], coin[pos]);return 0;
		}
	}
	printf("No Solution");
	return 0;
}*/

int main() {//two pointer
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int n, amount, coin[100000];
	scanf("%d%d", &n, &amount);
	for (int i = 0;i < n;i++)
		scanf("%d", &coin[i]);
	sort(coin, coin + n);
	int i = 0, j = n - 1;
	while (i<j) {
		if ((coin[i] + coin[j]) == amount) {
			printf("%d %d", coin[i], coin[j]);return 0;
		}
		else
			if ((coin[i] + coin[j]) > amount) j--;
			else i++;
	}
	printf("No Solution");
	return 0;
}