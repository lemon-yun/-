#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


void menu()
{
	printf("#######������########\n");
	printf("#######1.paly########\n");
	printf("#######0.exit########\n");
	printf("#####################\n");

}
void game()
{
	int num = rand() % 100 + 1;//������Χ1~99����1��������ķ�Χ����1~100
	//rand,����һ��0~32767֮���α�����
	//�ڵ���randǰ����ʹ��srand
	//srandֻ�����һ�Σ����Է���������
	printf("��������һ�����֣��²¿����Ƕ��٣�\n");
	int a = 0;
	scanf("%d", &a);
	do
	{
		if (a > num)
		{
			printf("�´���!������\n");
			scanf("%d", &a);
			system("cls");
		}
		else if (a < num)
		{
			printf("��С��!������\n");
			scanf("%d", &a);
			system("cls");
		}
	} while (a != num);
}

int main()
{
	int input;
	srand ((unsigned int)time(NULL));//��ȡʱ���
	do
	{
		menu();
		printf("�����룺");
		scanf("%d", &input);
		system("cls");
		if (input == 1)
		{
			game();
			printf("��ϲ�㣬�¶���!\n");
			printf("�����𣿣�1/0��");
			scanf("%d", &input);
			system("cls");
			while (input != 1 && input !=0)
			{
				printf("��������������\n");
				scanf("%d", &input);
				system("cls");
				if (input == 0)
					printf("�ټ�");
			}
		}
		else if (input == 0)
			printf("�ټ�");
		else
			printf("��������������\n");
	} while (input);
}