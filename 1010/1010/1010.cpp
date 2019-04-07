#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;
int ToDig(char c) {
	if (c <= '9'&&c >= '0') return c - '0';
	if (c >= 'a'&&c <= 'z') return c - 'a' + 10;
	return 0;
}
LL ToDec(string& s, LL r) {
	LL sum = 0;
	for (size_t i = 0;i < s.length();i++) {
		sum = sum*r + ToDig(s[i]);
	}
	return sum;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	string n[2];int tag;LL rad;
	cin >> n[0] >> n[1] >> tag >> rad;
	LL s = ToDec(n[tag - 1], rad);
	LL left = -1, right, mid;
	for (size_t i = 0;i < n[2 - tag].length();i++) {
		int t = ToDig(n[2 - tag][i]) + 1;
		if (t > left) left = t;
	}
	right = left > s ? left + 1 : s + 1;
	bool find = false;
	while (left <= right) {
		mid = (left + right) / 2;
		LL sum = ToDec(n[2 - tag], mid);
		if (sum == s) {
			find = true;break;
		}
		else
			if (sum > s||sum<0)
				right = mid - 1;
			else
				left = mid + 1;
	}
	if (find) printf("%lld", mid);
	else
		printf("Impossible");
	return 0;
}

/*
�״�㣺1.��Ŀ˵���ַ�Χ��0-36,������ָrad�ķ�Χ,rad���Ժܴ�
2.ע��ת��Ϊʮ������ʱ�������   3.ʹ�ö��ַ�ʱע����ȷ���߽緶Χ
�ջ�
*/
//δ��ɣ�B1048 