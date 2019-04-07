#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool IsZero(string& s){
    for(int i=0;i<s.size();i++)
        if(s[i]>='1'&&s[i]<='9') return false;
    return true;
}
string form(string& s,int n,int& m){//指数形式关键是找到尾数和指数
    string dig;
    if(IsZero(s)){
        dig.insert(0,n,'0');m=0;return dig;
    }
    int len=s.size(),p1=s.size(),p2;
    for(int i=0;i<len;i++)
        if(s[i]=='.') p1=i;//找小数点位置
    for(int i=0;i<len;i++)
        if(s[i]>='1'&&s[i]<='9')//找第一个非零数字位置
        {
            p2=i;break;
        }
    m=p1>p2?p1-p2:p1-p2+1;//0.00123与12.3计算指数的情况是不同的
    dig=s.substr(p2,len-p2);
    if(p1>p2&&p1<len) dig.erase(dig.begin()+p1-p2);//去小数点
    if(n<dig.size()) dig.erase(dig.begin()+n,dig.end());//多去掉
    else
        if(n>dig.size()) dig.insert(dig.size(),n-dig.size(),'0');//少补零
    return dig;
}
int main() {
#ifdef ONLINE_JUDGE
#else
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r",stdin);
#endif
	int n;string a,b;
	cin>>n>>a>>b;
	int pa,pb;
	string fa=form(a,n,pa),fb=form(b,n,pb);
	if((fa==fb)&&(pa==pb)) printf("YES 0.%s*10^%d",fa.c_str(),pa);
	else printf("NO 0.%s*10^%d 0.%s*10^%d",fa.c_str(),pa,fb.c_str(),pb);
	return 0;
}

/*
易错点：//注意指数的计算
          注意处理0的输出
收获：
*/
//未完成：B1048
