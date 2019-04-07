#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(string& a, string& b) {
	return a + b < b + a;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	string seg[10000];
	int n;cin >> n;
	for (int i = 0;i < n;i++)
		cin >> seg[i];
	sort(seg, seg + n,cmp);
	string res;
	for (int i = 0;i < n;i++)
		res += seg[i];
	while (!res.empty() && res[0] == '0')
		res.erase(res.begin());
	if (res.empty()) cout << 0;
	else
		cout << res;
	return 0;
}

/*
易错点：使用erase函数时，序列的长度会变化
收获：
*/
//未完成：B1048 