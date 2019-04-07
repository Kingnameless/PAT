#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool Equa(int a[], int b[], int n) {
	for (int i = 0;i < n;i++)
		if (a[i] != b[i]) return false;
	return true;
}
bool InsertSort(int a[],int b[],int n) {
	bool flag = false;
	for (int i = 1;i < n;i++) {
		int j = i, temp = a[i];
		while (j > 0 && temp < a[j - 1]) {
			a[j] = a[j - 1];j--;
		}
		a[j] = temp;
		if (flag) return true;
		if (Equa(a, b, n)) {
			flag = true;continue;
		}
	}
	return false;
}
bool mergeSort(int a[], int b[], int n) {
	bool flag = false;
	for (int i = 2;i / 2 < n;i *= 2) {
		for (int j = 0;j < n;j += i)
			sort(a + j, a + min(n, j + i ));
		if (flag) return true;
		if (Equa(a, b, n)) {
			flag = true;continue;
		}
	}
	return false;
}
int main() {
#ifdef ONLINE_JUDGE    
#else    
	freopen("C://Users/Administrator.WIN-20160308UMZ/Desktop/PG/c/PAT/input.txt", "r", stdin);
#endif    
	int seq1[100], seq2[100], part[100], n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &seq1[i]);
		seq2[i] = seq1[i];
	}
	for (int i = 0;i < n;i++) 
		scanf("%d", &part[i]);
	if (InsertSort(seq1, part, n)) {
		printf("Insertion Sort\n");
		for (int i = 0;i < n;i++) {
			if (i != 0) printf(" ");
			printf("%d", seq1[i]);
		}
	}
	else
		if (mergeSort(seq2, part, n)) {
			printf("Merge Sort\n");
			for (int i = 0;i < n;i++) {
				if (i != 0) printf(" ");
				printf("%d", seq2[i]);
			}
		}
	return 0;
}

/*
易错点：
收获：
*/
//未完成：B1048 