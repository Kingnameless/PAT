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
struct student {
	int id, rank, nrank;
	int subject[4];//A,C,M,E
	char BestRank;
};
int now = 0;
bool cmp(student& a, student& b) {
	return a.subject[now] > b.subject[now];//还可以这么玩？？？
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int n, m;
	char r[5] = "ACME";
	scanf("%d%d", &n, &m);
	vector<student> Rank;
	for(int i=0;i<n;i++) {
		student stu;
		scanf("%d%d%d%d", &stu.id, &stu.subject[1], &stu.subject[2], &stu.subject[3]);
		stu.subject[0] = (stu.subject[1] + stu.subject[2] + stu.subject[3]) / 3;
		stu.rank = n + 1;
		Rank.push_back(stu);
	}
	while (now < 4) {
		sort(Rank.begin(), Rank.end(), cmp);
		for (int i = 0;i < n;i++) {
			if (i == 0)
				Rank[0].nrank = 1;
			else
				if (Rank[i].subject[now] == Rank[i - 1].subject[now])
					Rank[i].nrank = Rank[i - 1].nrank;
				else
					Rank[i].nrank = i + 1;
			if (Rank[i].nrank < Rank[i].rank) {
				Rank[i].rank = Rank[i].nrank;Rank[i].BestRank = r[now];
			}
		}
		now++;
	}
	for (int i = 0;i < m;i++) {
		int id;
		scanf("%d", &id);
		int j = 0;
		for (;j < n;j++) {
			if (Rank[j].id == id) {
				printf("%d %c\n", Rank[j].rank, Rank[j].BestRank);break;
			}
		}
		if (j == n) printf("N/A\n");
	}
	return 0;
}

/*
易错点：该题已说明id为string，PAT将id定义为int 或string 都可通过，但其他oj不行,要注意。
收获：将不同种类的分类标准，放在一个循环内完成（具体见代码）
*/
//未完成：B1048