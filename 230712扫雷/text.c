#include "game.h"


//�˵�
void meun()
{
	printf("\n");
	printf("*************************\n");
	printf("**********ɨ��***********\n");
	printf("*********1.play**********\n");
	printf("*********0.exit**********\n");
	printf("*************************\n");
}

void game()
{
	printf("\n");
	printf("��Ϸ��ʼ��һ����%d���ף�\n", Mine_count);
	char mine[ROWS][COLS] = { 0 };//�洢������
	char show[ROWS][COLS] = { 0 };//չʾ�Ų���
	//��ʼ��
	InitBoard(mine, ROW, COL, '0');
	InitBoard(show, ROW, COL, '*');
	//������
	Mine(mine, ROW, COL);
	Board(mine, ROW, COL);

	//��ӡ����
	Board(show, ROW, COL);
	//�Ų���
	Find(mine, show, ROW, COL);
}

int main()
{
	int a;
	srand((unsigned int)time(NULL));
	do
	{
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
			system("cls");

			break;
		case 0:
			printf("�ټ���\n");
			Sleep(1000);
			break;
		default:
			printf("�������������룡\n");
			break;
		}
	} while (a);

	return 0;
}