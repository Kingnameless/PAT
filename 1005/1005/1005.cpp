#include <stdio.h>
//������staticҪ��const
const char* words[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
//����string words[10]=.......
int main()
{
	char n[101];
	scanf("%s", n);
	int sum = 0, i = 0;
	while (n[i] != '\0')
	{
		sum += n[i] - '0';i++;
	}
	if (sum >= 100)//printf������
		printf("%s %s %s", words[sum / 100], words[sum % 100 / 10], words[sum % 10]);
	else
		if (sum >= 10)
			printf("%s %s", words[sum / 10], words[sum % 10]);
		else
			printf("%s", words[sum]);
	return 0;
}

/*
1.�ַ������ַ���c��c++�е��������Ҫ�ú��о�
2.�����ٴ�˵�������ֹ������Ӧ���ַ�����ʾ���������������������ޣ��ɿ���ö�ٻ���if���ָ��������
  �������sum���ֵΪ900����˿����η�Ϊ3λ����2λ����1λ�������
*/