#include <stdio.h>
//不能用static要用const
const char* words[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
//或者string words[10]=.......
int main()
{
	char n[101];
	scanf("%s", n);
	int sum = 0, i = 0;
	while (n[i] != '\0')
	{
		sum += n[i] - '0';i++;
	}
	if (sum >= 100)//printf的妙用
		printf("%s %s %s", words[sum / 100], words[sum % 100 / 10], words[sum % 10]);
	else
		if (sum >= 10)
			printf("%s %s", words[sum / 10], words[sum % 10]);
		else
			printf("%s", words[sum]);
	return 0;
}

/*
1.字符串和字符在c和c++中的输入输出要好好研究
2.本例再次说明，数字过大溢出应用字符串表示；输入输出的情况往往有限，可考虑枚举或用if区分各种情况；
  如此例中sum最大值为900，因此可依次分为3位数，2位数，1位数等情况
*/