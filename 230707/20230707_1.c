#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main_1()
{
	int a = 1;
	while (a <= 10)
	{
		if (a == 5)
			continue;//���Ϊ 1234��ѭ��
		//continue����������ѭ���ĺ������룬ֱ�ӻص�ѭ���жϣ���8��)
		if (a == 6)
			break;
		//break������ѭ��
		printf("%d", a);
		a++;
	}
	return 0;
}


int mian_2()
{
	int b = getchar();//��ȡһ���ַ�
	putchar(b);//���һ���ַ�
	return 0;
}


int main_3()
{
	int b;
	while ((b = getchar()) != EOF)//EOF���ļ������ı�־��-1
	//����ctrl + z����������
	{
		printf("%c", b);
		//����n���ַ���ѭ��n��
	}
}

#include <string.h>
int main_4()
{
	printf("���루������20����");
	char pw[10000] = { 0 };
	//����������һ�����⣬����ֻ����20�򲻷��䣬������������������
	//�������룬Ҳ�ᱨ�������ҷ�����10000
	scanf("%s", pw);//���鲻�� &
	int a;
	while ((a = getchar()) != '\n')
	{
		;
	}//���������ֱ�����\n(�س�)
	int b = strlen(pw);
	while (b >= 20)
	{
		printf("���������루������20����");
		scanf("%s", pw);
		int a;
		while ((a = getchar()) != '\n')
		{
			;
		}
		int b = strlen(pw);
		if (b < 20)
			break;
		else
			continue;
	}
	printf("��ȷ�ϣ�Y/N����");
	char c;
	scanf("%c", &c);
	if (c == 'Y')
		printf("���");
	else
		printf("����");
	return 0;
}