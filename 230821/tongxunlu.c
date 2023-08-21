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
			printf("扩容失败\n");
			return;
		}
	}
	printf("姓名：");
	scanf("%s", con->data[con->num].name);
	printf("性别：");
	scanf("%s", con->data[con->num].sex);
	printf("年龄：");
	scanf("%d", &con->data[con->num].age);
	printf("电话：");
	scanf("%s", con->data[con->num].tele);
	con->num++;
	printf("添加成功\n");
}
int Find(aaaa* con)
{
	char find[20];
	printf("请输入姓名：");
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
		printf("通讯录为空，无法删除\n");
		return;
	}
	else
	{
		int pos = Find(con);
		if (!pos)
		{
			printf("没有找到该联系人\n");
			return;
		}
		else
		{
			for (int i = pos; i < con->num - 1; i++)
			{
				con->data[i] = con->data[i + 1];
			}
			con->num--;
			printf("删除成功\n");
			return;
		}
	}
}
void Modify(aaaa* con)
{
	if (!con->num)
	{
		printf("通讯录为空，无法修改\n");
		return;
	}
	else
	{
		int pos = Find(con);
		if (!pos)
		{
			printf("没有找到该联系人\n");
			return;
		}
		else
		{
			printf("姓名：");
			scanf("%s", con->data[pos].name);
			printf("性别：");
			scanf("%s", con->data[pos].sex);
			printf("年龄：");
			scanf("%d", &con->data[pos].age);
			printf("电话：");
			scanf("%s", con->data[pos].tele);
			printf("修改成功\n");
			return;
		}
	}
}
void FindP(aaaa* con)
{
	if (!con->num)
	{
		printf("通讯录为空，无法查找\n");
		return;
	}
	else
	{
		int pos = Find(con);
		if (!pos)
		{
			printf("没有找到该联系人\n");
			return;
		}
		else
		{
			printf("%-10s %-8s %-8s %s\n", "姓名", "性别", "年龄", "电话");
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
	printf("%-10s %-8s %-8s %s\n","姓名","性别","年龄","电话");
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
		printf("请选择：");
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
			printf("退出程序\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}