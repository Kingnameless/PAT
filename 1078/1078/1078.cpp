#include<stdio.h>
#include<math.h>
using namespace std;

int Hash[100000] = { 0 };
bool IsPrime(int n)
{
	if (n <= 1) return false;
	int t = (int)sqrt(1.0*n);
	for (int i = 2;i <= t;i++)
		if (n%i == 0) return false;
	return true;
}
int main() 
{
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    

	int MSize, N;
	scanf("%d", &MSize);
	while (true) {
		if (IsPrime(MSize)) break;
		MSize++;
	}
	scanf("%d", &N);
	int n;
	scanf("%d", &n);Hash[n%MSize] = n;printf("%d", n%MSize);
	for (int i = 1;i < N;i++) {
		scanf("%d", &n);int j;
		for (j = 0;j < MSize;j++) {
			if (!Hash[(n%MSize + j*j)%MSize]) {
				Hash[(n%MSize + j*j) % MSize] = n;printf(" %d", (n%MSize + j*j) % MSize);
				break;
			}
		}
		if(j==MSize) printf(" -");
	}
	return 0;
}
//要注意n%MSize + j*j可能超过表长，所以要再次对MSize取模
//二次探测终止条件：若0<j<MSize无法找到位置，那么j>=MSize肯定找不到
