
#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main_9()
{
	int a;
	scanf("%d", &a);
	if (a <= 10)
		printf("1");
	else if (a > 10 && a <= 18)//ע�⣬10<a<=��д���ǲ��������
		printf("2");
	else
		printf("3");
	return 0;
}


int main_10()
{
	int a, b;
	for (a = 1; a <= 100; a++)//�ֺŸ���

	{
		if (a % 2 == 1)
			printf("%d ", a);
	}
	return 0;
}


int main()
{
	int day;
	scanf("%d", &day);
	switch (day)//��������Ҫ������
	{
	case 1://case���������ͳ������ʽ��ע��  ��
		printf("����һ");
		break;//break����
	case 2:
		printf("���ڶ�");
		break;
	case 3:
		printf("������");
		break;
	case 4:
		printf("������");
		break;
	case 5:
		printf("������");
		break;
	case 6:
		printf("������");
		break;
	case 7:
		printf("������");
		break;
	default://Ĭ�ϣ��������
		printf("����");
		break;
	}
	return 0;
}