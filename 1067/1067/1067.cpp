#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif  
	int pos[100000], n, d;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &d);
		pos[d] = i;
	}
	int count = 0, k = 1;
	while (k<n) {
		if (pos[0] != 0) {
			int p = pos[0];
			pos[0] = pos[pos[0]];
			pos[p] = p;count++;
			if (p == k) k++;
			while (k < n&&pos[k] == k) k++;
		}
		else {
			pos[0] = pos[k];pos[k] = 0;count++;
		}
	}
	for (int i = 0;i < n;i++)
		cout << pos[i] << " ";
	printf("%d", count);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 
/*
int swap[100000], n, zero_pos;
scanf("%d", &n);
for (int i = 0;i < n;i++) {
scanf("%d", &swap[i]);
if (swap[i] == 0) zero_pos = i;
}
int times = 0;
while (true) {
if (zero_pos == 0) {
int i;
for (i = 1;i < n;i++) {
if (swap[i] != i) {
swap[0] = swap[i];swap[i] = 0;zero_pos = i;times++;
break;
}
}
if (i == n) break;
}
else {
for (int j = 0;j < n;j++) {
if (swap[j] == zero_pos) {
swap[zero_pos] = swap[j];swap[j] = 0;zero_pos = j;times++;
break;
}
}
}
}
printf("%d", times);
*/