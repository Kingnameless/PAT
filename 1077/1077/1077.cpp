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
//c���Ե�gets()��get_s()������PAT�޷�ʹ��
//��ʹ��fgets()���棬��fgets()���ȡ�����еĻس��� 
//ע��PAT�����ļ���ǰ���������ĩλ���лس������һ���޻س�����fgets()�����ַ���ʱҪ��ȥ�س�
//���ϣ�������c++��


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
//ʹ��c++�е�string
