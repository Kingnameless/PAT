/*#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream fin("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", ios::in);
int main()
{
	double p1[1002] = { 0 };
	double p2[1002] = { 0 };
	int k, n;
	fin >> k;
	for (int j = 0;j < k;j++)
	{
		fin >> n;
		fin >> p1[n];
	}
	fin >> k;
	for (int j = 0;j < k;j++)
	{
		fin >> n;
		fin >> p2[n];
	}
	for (int j = 0;j < 1001;j++)
	{
		if (p1[j] || p2[j])
		{
			p1[j] += p2[j];
			if(p1[j]) p1[1001] += 1;
		}
	}
	cout << p1[1001];
	for (int j = 1000;j>=0;j--)
	{
		if (p1[j])
			cout << " " << j << " " << setiosflags(ios::fixed) << setprecision(1) << p1[j];
	}
	cout << endl;
}*/

//本题注意事项：
//1.系数和为0，总个数会减少
//2.两多项式抵消，即系数和全为零，输出0（0后不能有空格）
//3.记得保留小数点后一位
//4.尽量少构造类，即尽量面向过程
//5.用数组表示一个多项式，数组下标为指数，元素值为系数
//6.一定要考虑到各种可能的情况
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

int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	double poly[1002] = { 0 };
	for (int i = 0;i < 2;i++) {
		int K;
		scanf("%d", &K);
		for (int j = 0;j < K;j++) {
			int exp;double coe;
			scanf("%d%lf", &exp, &coe);
			poly[exp] += coe;
		}
	}
	for (int i = 0;i <= 1000;i++)
		if (poly[i] != 0) poly[1001]++;
	printf("%d", (int)poly[1001]);
	for (int i = 1000;i >= 0;i--)
		if (poly[i] != 0)
			printf(" %d %.1f", i, poly[i]);
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048