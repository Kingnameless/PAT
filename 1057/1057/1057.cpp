#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*int main()//查询时前缀的运用
{
	int a[] = { 1,4,-6,-2,7,3,-6,-2,6,9,12,-23,5,21,-15,2,31 };
	int sum[17];sum[0] = a[1];int MIN = INT_MAX;int ans = INT_MIN;
	for (int i = 1;i < 17;i++) sum[i] = sum[i - 1] + a[i];
	for (int R = 1;R < 17;R++)
	{
		MIN = min(MIN, sum[R - 1]);
		ans = max(ans, sum[R] - MIN);
	}
	cout << ans << endl;
}*/
//利用树状数组求解
struct BiTreeArray
{
	static const int MAX = 100010;
	vector<int> a;//a为树状数组
	BiTreeArray() { a = vector<int>(MAX, 0); }
	int lowbit(int i)
	{
		return i&(-i);
	}
	void adjust(int val, int i)
	{
		while (i < MAX)
		{
			a[i] += val;
			i += lowbit(i);
		}
	}
	int sum(int i)//求树状数组所对应实际数组的前i项和
	{
		int ans = 0;
		while (i > 0)
		{
			ans += a[i];
			i -= lowbit(i);
		}
		return ans;
	}
	int find(int pos, int l = 0, int r=MAX-1)
	{
		if (l == r)
			return l;
		int med = (l + r) / 2;
		if (sum(med) < pos)
			return find(pos, med + 1, r);
		else
			return find(pos, l, med);
	}
};
int main()
{
	BiTreeArray a;
	stack<int> key;
	int k = 0;
	char command[20];
	int N = 0;
	scanf("%d", &N);
	for (int i = 0;i < N;i++)
	{
		scanf("%s", &command);
		switch (command[1])
		{
		case'u':
			scanf("%d", &k);key.push(k);
			a.adjust(1, k);
			break;
		case'o':
			if (key.empty())
				cout << "Invalid" << endl;
			else
			{
				k = key.top();
				a.adjust(-1, k);
				key.pop();
				cout << k << endl;
			}
			break;
		case'e':
			if (key.empty())
				cout << "Invalid" << endl;
			else
				cout << a.find((key.size() + 1) / 2) << endl;
			break;
		}
	}
	return 0;
}