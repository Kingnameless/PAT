/*#include<stdio.h>
#include <string.h>
using namespace std;
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif  
    int N;
	scanf("%d", &N);getchar();
	char sen[520],kuchigusi[520];
	for (int i = 0;i < N;i++) {
		fgets(sen, 257, stdin);
		int len1 = strlen(sen), len2 = strlen(kuchigusi);
		if (sen[len1 - 1] == '\n') {
			sen[len1 - 1] = '\0';len1 = strlen(sen);
		}
		if (i == 0) {
			strcpy(kuchigusi, sen);continue;
		}
		while (sen[--len1] == kuchigusi[--len2]) {}
		strcpy(kuchigusi, kuchigusi + len2 + 1);
	}
	if(kuchigusi[0]=='\0') printf("nai");
	else
		printf("%s", kuchigusi);
	return 0;
}*/
//c语言的gets()及get_s()函数在PAT无法使用
//可使用fgets()代替，但fgets()会读取缓存中的回车符 
//注意PAT输入文件的前几行输入的末位带有回车而最后一行无回车，用fgets()读入字符串时要除去回车
//综上，还是用c++吧


#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;


int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int N;
	scanf("%d", &N);
	cin.get();
	string sen, kuchigusi;
	for (int i = 0;i < N;i++) {
		getline(cin, sen);
		reverse(sen.begin(), sen.end());
		if (i == 0) {
			kuchigusi = sen;continue;
		}
		int j;
		for (j = 0;j < sen.length() && j < kuchigusi.length();j++)
			if (sen[j] != kuchigusi[j]) break;
		kuchigusi.assign(kuchigusi, 0, j);
	}
	reverse(kuchigusi.begin(),kuchigusi.end());
	if (kuchigusi.empty()) cout << "nai";
	else
		cout << kuchigusi;
	return 0;
}
//使用c++中的string
