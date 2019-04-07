#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif
	int a;
	char b[10];
	scanf("%d",&a);
	//scanf("%s",b);             //13i  遇到空格、换行结束输出，且不读入换行、空格
	//cin>>b;                    //13i  遇到空格、换行结束输出，且不读入换行、空格
	//cin.getline(b,10);         //13   遇到换行结束输出，且不读入换行
	//fgets(b,10,stdin);         //13 空行  遇到换行结束输出，但读入换行
	cout<<a<<b;
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048
