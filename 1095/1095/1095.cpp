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
struct record {
	char pNum[8], status[4];
	int date[3], sum;
};
struct Pair {
	int in[3], out[3], sum[2], ptime;
	char pNum[8];
};
bool cmp1(record& a, record& b) {
	if (strcmp(a.pNum, b.pNum) != 0) return strcmp(a.pNum, b.pNum) < 0;
	else
		return a.sum < b.sum;
}
bool cmp2(Pair& a, Pair& b) {
	return a.sum[0] < b.sum[0];
}
bool cmp3(Pair& a, Pair& b) {
	if (a.ptime != b.ptime) return a.ptime > b.ptime;
	else
		return strcmp(a.pNum, b.pNum) < 0;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int n, k;
	scanf("%d%d", &n, &k);
	vector<record> R;
	while (n--) {
		record r;
		scanf("%s%d:%d:%d%s", r.pNum, &r.date[0], &r.date[1], &r.date[2], r.status);
		r.sum = r.date[0] * 3600 + r.date[1] * 60 + r.date[2];
		R.push_back(r);
	}
	sort(R.begin(), R.end(), cmp1);
	vector<Pair> pair;size_t i = 0;
	while (i < R.size()) {
		size_t end = i;int ptime = 0;
		while (end + 1 < R.size() && strcmp(R[end].pNum, R[end + 1].pNum) == 0) end++;
		while (i + 1 <= end) {
			if (strcmp(R[i].status, "in") == 0 && strcmp(R[i + 1].status, "out") == 0) {
				Pair p;strcpy(p.pNum, R[i].pNum);p.sum[0] = R[i].sum;p.sum[1] = R[i + 1].sum;
				ptime += (R[i + 1].sum - R[i].sum);p.ptime = ptime;
				for (int j = 0;j < 3;j++) {
					p.in[j] = R[i].date[j];p.out[j] = R[i + 1].date[j];
				}
				pair.push_back(p);i += 2;
			}
			else
				i++;
		}
		i = end + 1;
	}
	sort(pair.begin(), pair.end(), cmp2);
	while (k--) {
		int date[3];scanf("%d:%d:%d", &date[0], &date[1], &date[2]);
		int count = 0, sum = 0;sum = date[0] * 3600 + date[1] * 60 + date[2];
		cout << "sum:" << sum << endl;
		for (size_t i = 0;i < pair.size();i++) {
			if (pair[i].sum[0] > sum) break;
			cout << "psum:" << pair[i].pNum << " " << pair[i].sum[0] << " " << pair[i].sum[1] << " " << pair[i].ptime << endl;
			if (sum >= pair[i].sum[0] && sum < pair[i].sum[1])
				count++;
		}
		printf("%d\n", count);
	}
	sort(pair.begin(), pair.end(), cmp3);
	printf("%s ", pair[0].pNum);
	for (size_t i = 1;i < pair.size();i++) {
		if (pair[i].ptime == pair[i - 1].ptime) printf("%s ", pair[i].pNum);
		else {
			printf("%02d:%02d:%02d", pair[i - 1].ptime / 3600, pair[i - 1].ptime % 3600 / 60, pair[i - 1].ptime % 60);
			break;
		}
	}
	return 0;
}*/

/*
易错点：time.in<=time<time.out时，才计数
收获：1.区间求和想到用前缀数组或树状数组
2.映射用map
3.
*/
//未完成：B1048 
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm> 
#include<map>
#include<vector>
#include<queue>  
#include<string>
using namespace std;
struct car {
	char id[8];
	bool status;
	int date;
};
bool cmp(car& a, car& b) {
	if (strcmp(a.id, b.id) != 0) return strcmp(a.id, b.id) < 0;
	else
		return a.date < b.date;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r",stdin);
#endif    
	int n, k;
	scanf("%d%d", &n, &k);
	vector<car> rec;
	while (n--) {
		int h, m, s;car c;char io[4];
		scanf("%s%d:%d:%d%s", c.id, &h, &m, &s, io);
		if (strcmp(io, "in") == 0) c.status = true;
		else
			c.status = false;
		c.date = h * 3600 + m * 60 + s;
		rec.push_back(c);
	}
	sort(rec.begin(), rec.end(), cmp);
	map<string, int> ptime;int p[24 * 60 * 60] = { 0 }, maxtime = -1;size_t i = 0;
	while (i + 1 < rec.size()) {
		if (strcmp(rec[i].id, rec[i + 1].id) == 0 && rec[i].status && (!rec[i + 1].status)) {
			p[rec[i].date]++;p[rec[i + 1].date]--;
			if (ptime.count(rec[i].id) == 0) ptime[rec[i].id] = 0;
			ptime[rec[i].id] += rec[i + 1].date - rec[i].date;
			maxtime = max(maxtime, ptime[rec[i].id]);
			i += 2;
		}
		else
			i++;
	}
	for (int i = 1;i < 24 * 60 * 60;i++)
		p[i] += p[i - 1];
	while (k--) {
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		printf("%d\n", p[h * 3600 + m * 60 + s]);
	}
	map<string, int>::iterator it = ptime.begin();
	while (it != ptime.end()) {
		if (it->second == maxtime) cout << it->first << " ";
		it++;
	}
	printf("%02d:%02d:%02d", maxtime / 3600, maxtime % 3600 / 60, maxtime % 60);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 