#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r",stdin);
#endif
	map<string,vector<string> > lib;
	int n;scanf("%d",&n);
	while(n--){
        string id;cin>>id;getchar();
        for(int i=0;i<5;i++){
            string inf;getline(cin,inf);
            if(i==2){
                int j=0;
                while(j<inf.size()){
                    string key;
                    while(j<inf.size()&&inf[j]!=' ')
                        key+=inf[j++];
                    lib[key].push_back(id);
                    j++;
                }
                continue;
            }
            lib[inf].push_back(id);
        }
	}
	int m;scanf("%d",&m);
	while(m--){
        int Qnum;string query;
        scanf("%d:",&Qnum);
        getchar();
        getline(cin,query);
        printf("%d: %s\n",Qnum,query.c_str());
        if(lib[query].empty()) printf("Not Found\n");
        else{
            sort(lib[query].begin(),lib[query].end());
            for(int i=0;i<lib[query].size();i++)
                cout<<lib[query][i]<<endl;
        }
	}
	return 0;
}

/*
易错点：
收获：//意外的一次就通过了
*/
//未完成：B1048
