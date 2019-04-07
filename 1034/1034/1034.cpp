#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;//未完成
struct node {
	int name, time, w;
	node(int n=0,int t=0):name(n),time(t){}
};
vector<node> gang[1000];
map<string, int> m;
bool flag[1000] = { 0 };
int count = 0, maxw = -1;
void DFS(int a) {
	flag[a] = true;
	for (int i = 0;i < gang[a].size();i++) {
		if(!flag[gang[a][i].name])
	}
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int n, k;
	scanf("%d%d", &n, &k);
	int i = 0, t;string s1, s2;
	while (n--) {
		cin >> s1 >> s2 >> t;
		if (m.count(s1) == 0) {
			m[s1] = i;i++;
		}
		if (m.count(s2) == 0) {
			m[s2] = i;i++;
		}
		gang[m[s1]].push_back(node(m[s2], t));
	}
	for(int j=0;j<i;j++)

	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 