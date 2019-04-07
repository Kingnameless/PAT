#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct player {
	int weight, rank;
};
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int Np, Ng;
	scanf("%d%d", &Np, &Ng);
	queue<int> q;player p[1000];
	for (int i = 0;i < Np;i++) {
		scanf("%d", &p[i].weight);
	}
	int turn[1000];
	for (int i = 0;i < Np;i++) {
		scanf("%d", &turn[i]);q.push(turn[i]);
	}
	int t = 1, g, len = q.size();
	while (true) {
		if (len % Ng == 0) g = len / Ng;
		else g = len / Ng + 1;
		for (int i = 0;i < len;i += Ng) {
			int maxn = q.front();
			for (int j = i;j < min(i + Ng, len);j++) {
				p[q.front()].rank = g + 1;
				if (p[q.front()].weight > p[maxn].weight) {
					maxn = q.front();
				}
				q.pop();
			}
			q.push(maxn);
		}
		t++;len = q.size();
		if (len == 1) {
			p[q.front()].rank = 1;break;
		}
	}
	for (int i = 0;i < Np;i++) {
		if (i != 0) printf(" ");
		printf("%d", p[i].rank);
	}
	return 0;
}

/*
易错点：
收获：//未晋级的老鼠的排名为组数加1
*/
//未完成：B1048 