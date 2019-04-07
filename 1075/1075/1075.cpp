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
int record[10001][7];
struct sub {
	int id, score[6], perfect;
};
bool cmp(sub& a, sub& b) {
	if (a.score[0] != b.score[0]) return a.score[0] > b.score[0];
	else
		if (a.perfect != b.perfect) return a.perfect > b.perfect;
		else
			return a.id < b.id;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif 
	memset(record, -1, sizeof(record));
	int n, k, m;
	int Fmark[5] = { 0 };
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0;i < k;i++)
		scanf("%d", &Fmark[i]);
	while (m--) {
		int id, i, j;
		scanf("%d%d%d", &id, &i, &j);
		if (j >= 0) record[id][6]++;//记录是否有有效提交
		record[id][i] = j >= record[id][i] ? j : record[id][i];
		if (record[id][i] == -1) record[id][i] = 0;
	}
	vector<sub> R;
	for (int i = 0;i < 10001;i++) {
		int sum = 0;sub r = { 0 };
		if (record[i][6]!=-1) {
			for (int j = 1;j <= k;j++) {
				if (record[i][j] == Fmark[j - 1]) r.perfect++;
				r.score[j] = record[i][j];
				if (record[i][j] != -1) sum += record[i][j];
			}
			r.id = i;r.score[0] = sum;
			R.push_back(r);
		}
		if (R.size() == n) break;
	}
	sort(R.begin(), R.end(), cmp);
	int rank = 1;
	for (size_t i = 0;i < R.size();i++) {
		if (i > 0 && R[i].score[0] != R[i - 1].score[0])
			rank = i + 1;
		printf("%d %05d", rank, R[i].id);
		for (int j = 0;j <= k;j++) {
			if (R[i].score[j] == -1) printf(" -");
			else {
				if (R[i].score[j] == -1) R[i].score[j] = 0;
				printf(" %d", R[i].score[j]);
			}
		}
		printf("\n");
	}
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 