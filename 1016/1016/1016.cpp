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
int toll[24];
struct record {
	char name[21];
	int date[4];
	char word[9];
	bool On_Off;
};
bool cmp(record& a, record& b) {
	if (strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
	else
		if (a.date[1] != b.date[1]) return a.date[1] < b.date[1];
		else
			if (a.date[2] != b.date[2]) return a.date[2] < b.date[2];
			else
				return a.date[3] < b.date[3];
}
double CountBill(record a, record b) {
	int bill = 0;
	while (a.date[1] < b.date[1] || a.date[2] < b.date[2] || a.date[3] < b.date[3]) {
		bill += toll[a.date[2]];
		a.date[3]++;
		if (a.date[3] == 60) {
			a.date[3] = 0;a.date[2]++;
		}
		if (a.date[2] == 24) {
			a.date[2] = 0;a.date[1]++;
		}
	}
	return bill*1.0 / 100;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	for (int i = 0;i < 24;i++)
		scanf("%d", &toll[i]);
	int n;
	scanf("%d", &n);
	vector<record> R;
	while (n--) {
		record r;
		scanf("%s %d:%d:%d:%d %s", r.name, &r.date[0], &r.date[1], &r.date[2], &r.date[3], r.word);
		if (strcmp(r.word, "on-line") == 0) r.On_Off = true;
		else r.On_Off = false;
		R.push_back(r);
	}
	sort(R.begin(), R.end(), cmp);
	size_t i = 0;
	while (i < R.size()) {
		size_t end = i;int pair = 0;
		while (end < R.size()&&strcmp(R[end].name, R[i].name) == 0) {
			if (pair == 0 && R[end].On_Off) pair = 1;
			if (pair == 1 && !R[end].On_Off) pair = 2;
			end++;
		}
		if (pair != 2) {
			i = end;continue;
		}
		printf("%s %02d\n", R[i].name, R[i].date[0]);
		size_t j = i;double sum = 0.0;
		while (i + 1 < end) {
			if (R[i].On_Off && !R[i + 1].On_Off) {
				printf("%02d:%02d:%02d ", R[i].date[1], R[i].date[2], R[i].date[3]);
				printf("%02d:%02d:%02d ", R[i + 1].date[1], R[i + 1].date[2], R[i + 1].date[3]);
				double bill = CountBill(R[i], R[i + 1]);sum += bill;
				int time = R[i + 1].date[1] * 24 * 60 + R[i + 1].date[2] * 60 + R[i + 1].date[3] - R[i].date[1] * 24 * 60 - R[i].date[2] * 60 - R[i].date[3];
				printf("%d $%.2f\n", time, bill);
				if (i + 2 < end) i += 2;
				else break;
			}
			else
				i++;
		}
		if (sum != 0) printf("Total amount: $%.2f\n", sum);
		i = end;
	}
	return 0;
}
/*
易错点：
pat测试点：

0  、1测试点：没有消费的用户不能输出

2测试点：on和off日期不在同一天却在同一个小时

3测试点：on和off日期同一天同一个小时(好坑)
收获：对于题目输入输出的描述
*/
//未完成：B1048
