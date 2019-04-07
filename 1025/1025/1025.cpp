/*#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm> 
#include<map>
#include<vector>
#include<queue>  
using namespace std;
struct Player {
	long long reg_num;
	int FRank, LocNum, LocRank, score;
};
bool cmp(Player a, Player b) {
	if (a.score != b.score) return a.score > b.score;
	else return a.reg_num < b.reg_num;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif   
	Player RankList[30001] = { 0 };
	int N, K, sum = 0;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &K);
		for (int j = 1+sum;j <= K+ sum;j++) {
			long long num;int s;
			scanf("%lld %d", &num, &s);
			RankList[j].LocNum = i + 1;RankList[j].reg_num = num;RankList[j].score = s;
		}
		sort(RankList + sum +1, RankList + sum+K+1, cmp);
		RankList[sum + 1].LocRank = 1;
		for (int j = 2 + sum;j <= K + sum;j++) {
			if (RankList[j].score == RankList[j - 1].score)
				RankList[j].LocRank = RankList[j - 1].LocRank;
			else
				RankList[j].LocRank = j - sum;
		}
		sum += K;
	}
	sort(RankList + 1, RankList + sum + 1, cmp);RankList[1].FRank = 1;
	printf("%d\n", sum);
	printf("%lld %d %d %d\n", RankList[1].reg_num, RankList[1].FRank, RankList[1].LocNum, RankList[1].LocRank);
	for (int i = 2;i <= sum;i++) {
		if (RankList[i].score == RankList[i - 1].score)
			RankList[i].FRank = RankList[i - 1].FRank;
		else
			RankList[i].FRank = i;
		printf("%lld %d %d %d\n", RankList[i].reg_num, RankList[i].FRank, RankList[i].LocNum, RankList[i].LocRank);
	}
	return 0;
}*/

/*
易错点：
收获：
*/
//未完成：B1048
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm> 
#include<map>
#include<vector>
#include<queue>  
using namespace std;
struct INFO {
	string id;
	int AllRank, LocalRank, LocalNum, score;
};
bool cmp(INFO &a, INFO &b) {
	if (a.score != b.score) return a.score > b.score;
	else return a.id < b.id;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	vector<INFO> RList;
	int N, K, num = 0;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> K;
		for (int j = num;j < num +K;j++) {
			INFO stu;
			cin >> stu.id >> stu.score;stu.LocalNum = i + 1;
			RList.push_back(stu);
		}
		vector<INFO>::iterator it = RList.begin() + num;
		sort(it, RList.end(), cmp);RList[num].LocalRank = 1;
		for (int j = num +1;j < num + K;j++) {
			if (RList[j].score == RList[j - 1].score)
				RList[j].LocalRank = RList[j - 1].LocalRank;
			else
				RList[j].LocalRank = j - num + 1;
		}
		num += K;
	}
	sort(RList.begin(), RList.end(), cmp);
	cout << num << endl;RList[0].AllRank = 1;
	cout << RList[0].id << " " << RList[0].AllRank << " " << RList[0].LocalNum << " " << RList[0].LocalRank << endl;
	for (int i = 1;i < num;i++) {
		if (RList[i].score == RList[i - 1].score)
			RList[i].AllRank = RList[i - 1].AllRank;
		else
			RList[i].AllRank = i + 1;
		cout << RList[i].id << " " << RList[i].AllRank << " " << RList[i].LocalNum << " " << RList[i].LocalRank << endl;
	}
	return 0;
}

/*
易错点：
收获：如果使用Sort等函数，感觉使用string和STL更契合，方便
*/
//未完成：B1048