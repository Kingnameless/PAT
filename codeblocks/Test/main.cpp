#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int gys(int a,int b){return !b?a:gys(b,a%b);} //大的数字为负数，则返回负数
int main(){
#ifdef ONLINE_JUDGE
#else
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r",stdin);
#endif
    int n,f; scanf("%d",&n);
    int s1,s2; scanf("%d/%d",&s1,&s2);
    for(int i=1;i<n;i++){
        int t1,t2; scanf("%d/%d",&t1,&t2);
        s1=s1*t2+t1*s2; s2=s2*t2; //先算s1后算s2，避免先改变s2
        int t=gys(s2,s1);
        s2/=t; s1/=t;
        if(s2<0) s2*=-1,s1*=-1; //保证s2为正数
    }
    s1<0?f=-1,s1*=-1:f=1;
    if(s1%s2==0){ //0%6,0/6 = 0
        printf(f>0||!s1?"%d":"-%d",s1/s2);
    }else{
        if(s1/s2==0) printf(f>0?"%d/%d":"-%d/%d",s1,s2);
        else printf(f>0?"%d %d/%d":"-%d %d/%d",s1/s2,s1%s2,s2);
    }
    return 0;
}
