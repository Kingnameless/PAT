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
	int apper[128] = { 0 };
	char shop[1001], eva[1001];
	scanf("%s%s", shop, eva);
	int len1 = strlen(shop), len2 = strlen(eva);
	for (int i = 0;i < len1;i++)
		apper[shop[i]]++;
	int count = 0;
	for (int i = 0;i < len2;i++)
		if (apper[eva[i]]>0) {
			count++;apper[eva[i]]--;
		}
	if (count < len2)
		printf("No %d", len2 - count);
	else
		printf("Yes %d", len1 - len2);
	return 0;
}

/*
�״�㣺//���Ƽ򵥣�����ܶ࣬����Ҫ����ĳ��ĸ�Ƿ���֣���Ҫע����ֵĴ����Ƿ��㹻
�ջ�
*/
//δ��ɣ�B1048 