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
struct INFO {
	char name[9];
	int age, worth;
};
bool cmp(INFO& a, INFO& b) {
	if (a.worth != b.worth) return a.worth > b.worth;
	else
		if (a.age != b.age) return a.age < b.age;
		else
			return strcmp(a.name, b.name) < 0;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int n, k;
	scanf("%d%d", &n, &k);
	vector<INFO> rank;
	while (n--) {
		INFO peo;
		scanf("%s%d%d", peo.name, &peo.age, &peo.worth);
		rank.push_back(peo);
	}
	sort(rank.begin(), rank.end(), cmp);
	for (int i = 0;i < k;i++) {
		printf("Case #%d:\n", i + 1);
		int times, Amin, Amax;scanf("%d%d%d", &times, &Amin, &Amax);
		int count = 0;
		for (size_t j = 0;j < rank.size()&&count<times;j++) {
			if (rank[j].age >= Amin&&rank[j].age <= Amax) {
				printf("%s %d %d\n", rank[j].name, rank[j].age, rank[j].worth);count++;
			}
		}
		if (count == 0) printf("None\n");
	}
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 