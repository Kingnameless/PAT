#include <stdio.h>
#include <math.h>
struct factor {
	int val, num;
	factor() { val = num = 0; }
};
int prime[10000] = { 0 }, pnum = 0;
factor fac[10];
bool p[100000] = { 0 };
void FindPrime(int n)//寻找质数算法1：时间复杂度O(n*loglog(n))
{
	int top = (int)sqrt(1.0*n);
	for (int i = 2;i <= top;i++)
	{
		if (!p[i])
		{
			prime[pnum++] = i;
			for (int j = 2;j*i <= top;j++)
				p[j*i] = true;
		}
	}
}
void PrimeFactor(int n)
{
	if (n == 1) {
		fac[0].val = 1;fac[0].num = 1;
	}
	else {
		int i = 0, j = 0;
		while (j<pnum && n>1) {
			if (n%prime[j] == 0) {
				fac[i].val = prime[j];
				fac[i].num++;
				n /= prime[j];
			}
			else {
				if (fac[i].num != 0) {
					i++, j++;
				}
				else
					j++;
			}
		}
		if (n > 1) {
			fac[i].val = n;
			fac[i].num = 1;
		}
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	FindPrime(N);
	PrimeFactor(N);
	if(fac[0].num==1) printf("%d=%d", N, fac[0].val);
	else 
		printf("%d=%d^%d", N, fac[0].val, fac[0].num);
	int i = 1;
	while (fac[i].num!=0) {
		if(fac[i].num==1) printf("*%d", fac[i].val);
		else
			printf("*%d^%d", fac[i].val, fac[i].num);
		i++;
	}
}

//关于质因子的题要注意对1的特殊处理
//要理清算法逻辑