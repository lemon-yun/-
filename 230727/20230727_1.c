#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main_1()
{
	(*(void(*)())0)();
	//����0��ַ���ĺ���
	//�ú����޲Σ�����������void
	//1. void(*)() - ����ָ������
	//2. (void(*)())0 - ��0����ǿ������ת����������Ϊһ��������ַ
	//3. *(void(*)())0 - ��0��ַ�����˽����ò���
	//4. (*(void(*)())0)() - ����0��ַ���ĺ���
	return 0;
}



void menu()
{
	printf("*************************\n");
	printf("*****1. add   2. sub*****\n");
	printf("*****3. mul   4. div*****\n");
	printf("*****    0. exit    *****\n");
	printf("*************************\n");
}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}int Mul(int x, int y)
{
	return x * y;
}int Div(int x, int y)
{
	return x / y;
}


int main_2()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		int (*parr[5])(int, int) = {NULL,Add,Sub,Mul,Div};//����ָ������
		if (input >= 1 && input <= 4)
		{
			int x, y;
			printf("������������������");
			scanf("%d %d", &x,&y);
			int ret = (parr[input])(x, y);//�Ӳ��� * ����
			printf("���Ϊ %d\n", ret);
		}
		else if (input == 0)
		{
			printf("�˳�����");
			break;
		}
		else
		{
			printf("�������\n");
		}
		int* p = &input;//����ָ��
		int *P[1] = { p };//����ָ������
		int*(*Pp)[1] = &P;//ָ������ָ�������ָ��
		int (*p1)(int, int) = Add;//����ָ��
		int (*pa1[1])(int, int) = {p1};//����ָ������
		int (*(*p2)[1])(int, int) = &pa1;//ָ����ָ�������ָ��
		int (*(*pa2[1])[1])(int, int) = {p2};//ָ����ָ�������ָ������
		int (*(*(*p3)[1])[1])(int, int) = &pa2;//ָ��ָ����ָ�������ָ�������ָ��
	} while (input);
	return 0;
}


void Cal(int (*p)(int, int))
{
	int x, y;
	printf("������������������");
	scanf("%d %d", &x, &y);
	int ret = p(x, y);//�ص�����
	printf("���Ϊ %d\n", ret);
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Cal(Add);
			break;
		case 2:
			Cal(Sub);
			break;
		case 3:
			Cal(Mul);
			break;
		case 4:
			Cal(Div);
			break;
		case 0:
			printf("�˳�");
			break;
		default:
			printf("��������\n");
			break;
		}
	}while(input);
}