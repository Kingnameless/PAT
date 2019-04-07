#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
    int data,next;
};
node Link[100000];
int REV(int& LastS,int& nowS,int k){
    int now=nowS,pre=-1,next=-1;
    while(k--){
        next=Link[now].next;
        Link[now].next=pre;
        pre=now;
        now=next;
    }
    Link[nowS].next=now;
    if(LastS!=-1) Link[LastS].next=pre;
    LastS=nowS;
    nowS=now;
    return pre;
}
int main() {
#ifdef ONLINE_JUDGE
#else
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r",stdin);
#endif
	int s,n,k;
	scanf("%d%d%d",&s,&n,&k);
	while(n--){
        int addr;
        scanf("%d",&addr);
        scanf("%d%d",&Link[addr].data,&Link[addr].next);
	}
	int p=s,len=0;
	while(p!=-1){
        len++;
        p=Link[p].next;
	}
	int nowStart=s,newStart,LastStart=-1;
	for(int i=0;i<len/k;i++){
        if(i==0){
            newStart=REV(LastStart,nowStart,k);
            continue;
        }
        REV(LastStart,nowStart,k);
	}
	while(newStart!=-1){
        printf("%05d %d ",newStart,Link[newStart].data);
        if(Link[newStart].next!=-1) printf("%05d\n",Link[newStart].next);
        else printf("-1\n");
        newStart=Link[newStart].next;
	}
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048
