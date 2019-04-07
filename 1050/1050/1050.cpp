#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	char s1[10001];bool s2[130] = { 0 };
	cin.getline(s1, 10001);
	char c;
	while (scanf("%c", &c) != EOF)
		s2[c] = true;
	for (int i = 0;i < strlen(s1);i++) {
		if (!s2[s1[i]])
			printf("%c", s1[i]);
	}
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 