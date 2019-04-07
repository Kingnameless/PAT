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
struct INFO{
	int id, vir, tal;
};
bool cmp(INFO& a, INFO& b) {
	if ((a.tal + a.vir) != (b.tal + b.vir))
		return (a.tal + a.vir) > (b.tal + b.vir);
	else
		if (a.vir != b.vir)
			return a.vir > b.vir;
		else
			return a.id < b.id;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int N, L, H;
	vector<INFO> gra[4];
	scanf("%d%d%d", &N, &L, &H);
	int sum = N;
	while (N--) {
		INFO per;
		scanf("%d%d%d", &per.id, &per.vir, &per.tal);
		if (per.tal < L||per.vir < L) {
			sum--;continue;
		}
		if (per.tal >= H&&per.vir >= H) {
			gra[0].push_back(per);continue;
		}
		if (per.tal < H&&per.vir >= H) {
			gra[1].push_back(per);continue;
		}
		if (per.tal < H&&per.vir < H&&per.vir >= per.tal) {
			gra[2].push_back(per);continue;
		}
		gra[3].push_back(per);
	}
	printf("%d\n", sum);
	for (int i = 0;i < 4;i++) {
		if (gra[i].size() != 0) {
			sort(gra[i].begin(), gra[i].end(), cmp);
			for (int j = 0;j < gra[i].size();j++)
				printf("%d %d %d\n", gra[i][j].id, gra[i][j].vir, gra[i][j].tal);
		}
	}
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048