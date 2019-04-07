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
struct record {
	int id, score;
	char name[9];
};
int c;
bool cmp(record& a, record& b) {
	if (c == 1) return a.id < b.id;
	if (c == 2) {
		if (strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
		else
			return a.id < b.id;
	}
	if (c == 3) {
		if (a.score != b.score) return a.score < b.score;
		else
			return a.id < b.id;
	}
	return false;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int n;
	scanf("%d%d", &n, &c);
	vector<record> R;
	while (n--) {
		record stu;
		scanf("%d%s%d", &stu.id, stu.name, &stu.score);
		R.push_back(stu);
	}
	sort(R.begin(), R.end(), cmp);
	for (size_t i = 0;i < R.size();i++) {
		printf("%06d %s %d\n", R[i].id, R[i].name, R[i].score);
	}
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 