#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
const char num[] = { '0','1','2','3','4','5','6','7','8','9' };
void D_To_Any(string &s, int n, int scale)
{
	if (n > 0)
	{
		s.insert(0, 1, num[n%scale]);
		D_To_Any(s, n / scale, scale);
	}
}
int Any_To_D(string s, int scale)
{
	int sum = 0;
	for (size_t i = 0;i < s.length();i++)
	{
		sum *= scale;
		sum += s[i] - '0';
	}
	return sum;
}
bool IsPrime(int n)
{
	if (n <= 1) return false;
	int t = (int)sqrt(1.0*n);
	for (int i = 2;i <= t;i++)
		if (n%i == 0)
			return false;
	return true;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif 
    int N, D;
	while (true) {
		string s;
		cin >> N; 
		if (N < 0) break;
		cin >> D;
		if (IsPrime(N)) {
			D_To_Any(s, N, D);cout << s << endl;reverse(s.begin(), s.end());cout << s << endl;
			if (IsPrime(Any_To_D(s, D))) cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
	}

	return 0;
}

/*
int get_reversre(int num, int r) {  //某数直接得到其r进制倒置
int res = 0, c = 0;
while (num != 0) {
c = num % r;
num /= r;
res = res * r + c;
}
return res;
}*/





