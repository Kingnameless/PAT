#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct station {
	double price, d;
};
bool cmp(station& a, station& b) {
	return a.d < b.d;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	double Cmax, D, Davg;int N;
	scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &N);
	station gas[501];
	for (int i = 0;i < N;i++)
		scanf("%lf%lf", &gas[i].price, &gas[i].d);
	gas[N].d = D;gas[N].price = 0.0;
	sort(gas, gas + N, cmp);
	const double MaxRun = Cmax*Davg;
	bool reach = true;double run = 0.0, cost = 0.0, Nowgas = 0.0;
	int i = 0;
	while (i < N) {
		if (gas[0].d != 0) {
			reach = false;break;
		}
		if (gas[i+1].d - gas[i].d > MaxRun) {
			run += MaxRun;reach = false;break;
		}
		int next = i + 1, minpos = i + 1;double minP = gas[i + 1].price;bool HasLow = false;
		while (next <= N&&gas[next].d - gas[i].d <= MaxRun) {
			if (gas[next].price < gas[i].price) {
				HasLow = true;break;
			}
			if (gas[next].price < minP) {
				minP = gas[next].price;minpos = next;
			}
			next++;
		}
		if (HasLow) {
			run += gas[next].d - gas[i].d;
			if (Nowgas < (gas[next].d - gas[i].d) / Davg) {
				cost += ((gas[next].d - gas[i].d) / Davg - Nowgas)*gas[i].price;
				Nowgas = 0.0;
			}
			else
				Nowgas -= (gas[next].d - gas[i].d) / Davg;
			i = next;
		}
		else {
			cost += (Cmax - Nowgas)*gas[i].price;run += gas[minpos].d - gas[i].d;
			Nowgas = Cmax - (gas[minpos].d - gas[i].d) / Davg;i = minpos;
		}
	}
	if (reach)
		printf("%.2f", cost);
	else
		printf("The maximum travel distance = %.2f", run);
	return 0;
}

/*
易错点:因为要把终点当作一个油价为零的加油站，所以gas数组的大小要比最大值大1；
收获：
*/
//未完成：B1048 