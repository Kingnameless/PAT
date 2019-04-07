#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
string LowDig[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string HighDig[13]={" ","tam", "hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
map<string,int> Dig;
int s_to_d(string s){
    int sum=0;
    for(int i=0;i<s.size();i++){
        sum=sum*10+s[i]-'0';
    }
    return sum;
}
int main() {
#ifdef ONLINE_JUDGE
#else
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r",stdin);
#endif
    for(int i=0;i<13;i++){
        Dig[LowDig[i]]=i;
        Dig[HighDig[i]]=13*i;
    }
	int n;scanf("%d",&n);getchar();
	string s;
	while(n--){
        getline(cin,s);
        if(s[0]>='0'&&s[0]<='9'){
            int d=s_to_d(s);
            if(d/13>0){
                if(d%13==0) cout<<HighDig[d/13]<<endl;
                else cout<<HighDig[d/13]<<" "<<LowDig[d%13]<<endl;
            }
            else cout<<LowDig[d]<<endl;
        }
        else{
            if(s.size()<=4) cout<<Dig[s]<<endl;
            else{
                int i;
                for(i=0;i<s.size();i++)
                    if(s[i]==' ') break;
                cout<<Dig[s.substr(0,i)]+Dig[s.substr(i+1,s.size()-i-1)]<<endl;
            }
        }
	}
	return 0;
}

/*
易错点：//当数字为13的倍数时只需输出高位部分
收获：
*/
//未完成：B1048
