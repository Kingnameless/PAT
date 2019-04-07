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
	char name[11], id[11];
	int grade;
};
bool cmp(student& a, student& b) {
	return a.grade > b.grade;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int n;scanf("%d", &n);
	vector<student> record;
	while (n--) {
		student stu;
		scanf("%s%s%d", stu.name, stu.id, &stu.grade);
		record.push_back(stu);
	}
	sort(record.begin(), record.end(), cmp);
	int g1, g2;scanf("%d%d", &g1, &g2);
	bool print = false;
	for (size_t i = 0;i < record.size();i++) {
		if (record[i].grade >= g1&&record[i].grade <= g2) {
			print = true;
			printf("%s %s\n", record[i].name, record[i].id);
		}
	}
	if (!print) printf("NONE");
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 