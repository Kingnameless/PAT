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
string form(string& s,int n,int& m){//ָ����ʽ�ؼ����ҵ�β����ָ��
    string dig;
    if(IsZero(s)){
        dig.insert(0,n,'0');m=0;return dig;
    }
    int len=s.size(),p1=s.size(),p2;
    for(int i=0;i<len;i++)
        if(s[i]=='.') p1=i;//��С����λ��
    for(int i=0;i<len;i++)
        if(s[i]>='1'&&s[i]<='9')//�ҵ�һ����������λ��
        {
            p2=i;break;
        }
    m=p1>p2?p1-p2:p1-p2+1;//0.00123��12.3����ָ��������ǲ�ͬ��
    dig=s.substr(p2,len-p2);
    if(p1>p2&&p1<len) dig.erase(dig.begin()+p1-p2);//ȥС����
    if(n<dig.size()) dig.erase(dig.begin()+n,dig.end());//��ȥ��
    else
        if(n>dig.size()) dig.insert(dig.size(),n-dig.size(),'0');//�ٲ���
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
�״�㣺//ע��ָ���ļ���
          ע�⴦��0�����
�ջ�
*/
//δ��ɣ�B1048
