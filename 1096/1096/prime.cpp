#include <stdio.h>
#include <cmath>

const int max = 1000000;
int prime[max] = { 0 }, pnum = 0;
bool p[max + 1] = { 0 };
bool isPrime(int n)   //寻找质数算法1：时间复杂度O(n*sqrt(n))
{
	if (n <= 1) return false;
	int top = (int)sqrt(1.0*n);
	for (int i = 2;i <= top;i++)
		if (n%i == 0) return false;
	return true;
}
void FindPrime1()
{
	for (int i = 2;i <= max;i++)
		if (isPrime(i))
			prime[pnum++] = i;
}
void FindPrime2()//寻找质数算法2：时间复杂度O(n*loglog(n))
{
	for (int i = 2;i <= max;i++)
	{
		if (!p[i])
		{  
			prime[pnum++] = i;
			for (int j = 2;j*i <= max;j++)
				p[j*i] = true;
		}
	}
}
int main()
{
	int M, N;
	scanf("%d%d", &M, &N);
	FindPrime2();
	for (int i = M;i <= N;i++)
		if ((i + 1 - M) % 10 == 0)
			printf("%d\n", prime[i-1]);
		else
			printf("%d ", prime[i-1]);
}

