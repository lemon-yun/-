#include "game.h"


void game()
{
	char arr[ROW][COL];
	//��ʼ������
	InitBoard(arr, ROW, COL);
	//��ӡ����
	Board(arr, ROW, COL);
	char w = 0;
	while (1)
	{
		//��Ҳ���
		PlayerMove(arr, ROW, COL);
		Board(arr, ROW, COL);
		//�ж�״̬
		w = IsWin(arr, ROW, COL);
		if (w != 'C')
			break;

		

		//���Բ���
		ComputerMove(arr, ROW, COL);
		Board(arr, ROW, COL);
		//�ж�״̬
		w = IsWin(arr, ROW, COL);
		if (w != 'C')
			break;
	}
	if (w == '*')
	{
		printf("��ϲ����ȡ��ʤ����\n");
	}
	else if (w == '#')
	{
		printf("���ź������Ի�ʤ��\n");
	}
	else if (w == 'D')
	{
		printf("ƽ�֣�\n");
	}


}

int main()
{
	int a;
	srand((unsigned int)time(NULL));
	do
	{
		system("cls");
		meun();
		printf("�����룺");
		scanf("%d", &a);
		system("cls");
		switch (a)
		{
		case 1:
			game();
			getchar();
			getchar();

			break;
		case 0:
			printf("�ټ���\n");
			break;
		default:
			printf("�������������룡\n");
			break;
		}
	} while (a);

	return 0;
}