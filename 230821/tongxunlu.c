#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct people
{
	char name[20];
	char sex[10];
	int age;
	char tele[20];
}people;
typedef struct aaaa
{
	people* data;
	int num;
	int capa;
}aaaa;

enum
{
	EXIT,
	ADD,
	DELE,
	MODIFY,
	FOUND,
	PRINT
};

void Menu()
{
	printf("*********************************\n");
	printf("*******1.ADD    2.DELE***********\n");
	printf("*******3.MODIFY 4.FOUND**********\n");
	printf("*******5.PRINT  0.EXIT***********\n");
	printf("*********************************\n");
}
void Init(aaaa* con)
{
	con->data = (people*)malloc(3*sizeof(people));
	con->num = 0;
	con->capa = 3;
}
void Add(aaaa* con)
{
	if (con->num == con->capa)
	{
		people* ptr = (people*)realloc(con->data, (con->capa + 2) * sizeof(people));
		if (ptr != NULL) 
		{
			con->data = ptr;
			con->capa += 2;

		}
		else
		{
			printf("����ʧ��\n");
			return;
		}
	}
	printf("������");
	scanf("%s", con->data[con->num].name);
	printf("�Ա�");
	scanf("%s", con->data[con->num].sex);
	printf("���䣺");
	scanf("%d", &con->data[con->num].age);
	printf("�绰��");
	scanf("%s", con->data[con->num].tele);
	con->num++;
	printf("��ӳɹ�\n");
}
int Find(aaaa* con)
{
	char find[20];
	printf("������������");
	scanf("%s", find);
	for (int i = 0; i < con->num; i++)
	{
		if (strcmp(find, con->data[i].name) == 0)
			return i;
	}
	return 0;
}
void Dele(aaaa* con)
{
	if (!con->num)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	else
	{
		int pos = Find(con);
		if (!pos)
		{
			printf("û���ҵ�����ϵ��\n");
			return;
		}
		else
		{
			for (int i = pos; i < con->num - 1; i++)
			{
				con->data[i] = con->data[i + 1];
			}
			con->num--;
			printf("ɾ���ɹ�\n");
			return;
		}
	}
}
void Modify(aaaa* con)
{
	if (!con->num)
	{
		printf("ͨѶ¼Ϊ�գ��޷��޸�\n");
		return;
	}
	else
	{
		int pos = Find(con);
		if (!pos)
		{
			printf("û���ҵ�����ϵ��\n");
			return;
		}
		else
		{
			printf("������");
			scanf("%s", con->data[pos].name);
			printf("�Ա�");
			scanf("%s", con->data[pos].sex);
			printf("���䣺");
			scanf("%d", &con->data[pos].age);
			printf("�绰��");
			scanf("%s", con->data[pos].tele);
			printf("�޸ĳɹ�\n");
			return;
		}
	}
}
void FindP(aaaa* con)
{
	if (!con->num)
	{
		printf("ͨѶ¼Ϊ�գ��޷�����\n");
		return;
	}
	else
	{
		int pos = Find(con);
		if (!pos)
		{
			printf("û���ҵ�����ϵ��\n");
			return;
		}
		else
		{
			printf("%-10s %-8s %-8s %s\n", "����", "�Ա�", "����", "�绰");
			printf("%-10s %-8s %-8d %s\n",
				con->data[pos].name,
				con->data[pos].sex,
				con->data[pos].age,
				con->data[pos].tele);
			return;
		}
	}
}
void Print(aaaa* con)
{
	printf("%-10s %-8s %-8s %s\n","����","�Ա�","����","�绰");
	for (int i = 0; i < con->num; i++)
	{
		printf("%-10s %-8s %-8d %s\n",
			con->data[i].name,
			con->data[i].sex,
			con->data[i].age,
			con->data[i].tele);
	}
}


int main()
{
	aaaa con;
	Init(&con);
	int input = 0;
	do 
	{
		Menu();
		printf("��ѡ��");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			Add(&con);
			break;
		case DELE:
			Dele(&con);
			break;
		case MODIFY:
			Modify(&con);
			break;
		case FOUND:
			FindP(&con);
			break;
		case PRINT:
			Print(&con);
			break;
		case EXIT:
			free(con.data);
			con.data = NULL;
			printf("�˳�����\n");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}