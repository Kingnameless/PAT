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
ע��㣺Լ��ʱҪ�Ƿ��ӷ�ĸ����ֵ�Ĺ�����
�ջ��漰�����ļ���ע��㣺
1.��Ϊ�������������
2.��Ϊ�ٷ�����Ϊ������
3.Լ��
4.����Ϊ�㣬��ĸ��һ
5.����Ϊ����������ǰ
*/


