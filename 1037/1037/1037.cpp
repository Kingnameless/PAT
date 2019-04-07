#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int Nc, Np, n;
	scanf("%d", &Nc);
	vector<int> cou1, cou2;
	while (Nc--) {
		scanf("%d", &n);
		if (n > 0) cou1.push_back(n);
		else cou2.push_back(n);
	}
	sort(cou1.begin(), cou1.end(), cmp);sort(cou2.begin(), cou2.end());
	scanf("%d", &Np);
	vector<int> pro1, pro2;
	while (Np--) {
		scanf("%d", &n);
		if (n > 0) pro1.push_back(n);
		else pro2.push_back(n);
	}
	sort(pro1.begin(), pro1.end(), cmp);sort(pro2.begin(), pro2.end());
	long long sum = 0;
	for (size_t i = 0;i < cou1.size() && i < pro1.size();i++)
		sum += cou1[i] * pro1[i];
	for (size_t i = 0;i < cou2.size() && i < pro2.size();i++)
		sum += cou2[i] * pro2[i];
	printf("%lld", sum);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 