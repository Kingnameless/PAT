#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
typedef long long LL;
using namespace std;
LL gcd(LL a,LL b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r",stdin);
#endif
    int n;
    scanf("%d",&n);
    LL a1=0,a2=1,s1,s2;
    while(n--){
        scanf("%lld/%lld",&s1,&s2);
        a1=a1*s2+s1*a2;
        a2*=s2;
        LL g=gcd(abs(a1),abs(a2));
        a1/=g;a2/=g;
        if(a2<0){
            a1=-a1;a2=-a2;
        }
    }
    if(a1==0) printf("0");
    else
        if(a1/a2==0) printf("%lld/%lld",a1,a2);
        else
            if(a1%a2==0) printf("%lld",a1/a2);
            else printf("%lld %lld/%lld",a1/a2,abs(a1%a2),a2);
    return 0;
}
/*
注意点：约分时要是分子分母绝对值的公因数
收获：涉及分数的几个注意点：
1.若为整数，输出分子
2.若为假分数化为带分数
3.约分
4.分数为零，分母置一
5.分数为负，符号提前
*/


