#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int M, N, L, T, vol;
int a[100][1300][130];
bool flag[100][1300][130] = { 0 };
int direct[6][3] = {
	0,0,1,
	0,0,-1,
	0,-1,0,
	0,1,0,
	1,0,0,
	-1,0,0
};
struct core {
	int x, y, z;
	core(int i=0,int j=0,int k=0):x(i),y(j),z(k){}
};
bool Judge(int x, int y, int z) {
	bool f1 = (x >= 0) && (x < L);
	bool f2 = (y >= 0) && (y < M);
	bool f3 = (z >= 0) && (z < N);
	return f1&&f2&&f3 && (a[x][y][z] == 1) && (!flag[x][y][z]);
}
void BFS(int x, int y, int z) {
	flag[x][y][z] = true;vol++;
	core c(x, y, z);
	queue<core> q;
	q.push(c);
	while (!q.empty()) {
		c = q.front();
		q.pop();
		for (int i = 0;i < 6;i++) {
			core next;
			next.x = c.x + direct[i][0];
			next.y = c.y + direct[i][1];
			next.z = c.z + direct[i][2];
			if (Judge(next.x, next.y, next.z)) {
				flag[next.x][next.y][next.z] = true;
				q.push(next);vol++;
			}
		}
	}
}
void DFS(int x, int y, int z) {
	if (!Judge(x, y, z)) return;
	flag[x][y][z] = true;
	vol++;
	for (int i = 0;i < 6;i++)
		DFS(x + direct[i][0], y + direct[i][1], z + direct[i][2]);
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	scanf("%d%d%d%d", &M, &N, &L, &T);
	for (int i = 0;i < L;i++)
		for (int j = 0;j < M;j++)
			for (int k = 0;k < N;k++)
				scanf("%d", &a[i][j][k]);
	int total = 0;
	for (int i = 0;i < L;i++)
		for (int j = 0;j < M;j++)
			for (int k = 0;k < N;k++) {
				vol = 0;
				if (a[i][j][k] == 1 && (!flag[i][j][k])) {
					BFS(i, j, k);
				}
				if (vol >= T) total += vol;
			}
	printf("%d", total);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 