#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
char ToUp(char c) {
	if (c < 'a'||c > 'z') return c;
	else
		return c + 'A' - 'a';
}
bool apper[200] = { 0 };
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r",stdin);
#endif    
	char ori[81], out[81];
	scanf("%s%s", ori, out);
	int i = 0, j = 0;
	while (i < strlen(ori)) {
		if (j < strlen(out)&&ori[i] == out[j]) {
			i++;j++;
		}
		else {
			if (!apper[ToUp(ori[i])]) {
				cout << ToUp(ori[i]);apper[ToUp(ori[i])] = true;
			}
			i++;
		}
	}
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 