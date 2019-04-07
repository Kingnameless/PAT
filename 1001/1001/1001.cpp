/*#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//第一次做
int main()
{
	int a, b;
	cin >> a >> b;
	int c = a + b;
	if (c < 0)
	{
		c = -c;
		cout << "-";
	}
	string s;
	stringstream ss;
	ss << c;ss >> s;
	string::iterator k = s.end();
	k--;
	int i = 0;
	for (;k!=s.begin();k--)
	{
		if (i == 2) s.insert(k, ',');
		i++;i %= 3;
	}
	cout << s << endl;
	return 0;
}*/
//第二次做
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
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = a + b;
	if (ans < 0) printf("-");
	ans = ans >= 0 ? ans : -ans;
	if (ans > 999999)
		printf("%d,%03d,%03d", ans / 1000000, ans / 1000 % 1000, ans % 1000);//不足3位记得补0
	else
		if (ans > 999)
			printf("%d,%03d", ans / 1000, ans % 1000);//不足3位记得补0
		else
			printf("%d", ans);
	return 0;
}

//易错点：不足3位记得补0
//收获：1.能穷举的情况尽量穷举，可简化代码
//2.若使用cout，在使用setw(int n)和setfill(string s)控制输出格式时，需要包括头文件iomanip。
//其中setfill是设置填充填充字符，setw设置输出的宽度，它们的只作用表现在紧接着输入的字符串上
//英语生词：1.commas:逗号；
