/*#include <iostream>
#include <sstream>
#include <string>
using namespace std;
//��һ����
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
//�ڶ�����
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
		printf("%d,%03d,%03d", ans / 1000000, ans / 1000 % 1000, ans % 1000);//����3λ�ǵò�0
	else
		if (ans > 999)
			printf("%d,%03d", ans / 1000, ans % 1000);//����3λ�ǵò�0
		else
			printf("%d", ans);
	return 0;
}

//�״�㣺����3λ�ǵò�0
//�ջ�1.����ٵ����������٣��ɼ򻯴���
//2.��ʹ��cout����ʹ��setw(int n)��setfill(string s)���������ʽʱ����Ҫ����ͷ�ļ�iomanip��
//����setfill�������������ַ���setw��������Ŀ�ȣ����ǵ�ֻ���ñ����ڽ�����������ַ�����
//Ӣ�����ʣ�1.commas:���ţ�
