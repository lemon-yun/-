#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��windows������ʾ����ػ�ָ��
//shutdown -s -t 60(-s �ػ���-t ���õ���ʱ�� 60 60s��ػ�)
//shutdown -a��-a ȡ���ػ���


int main_2()
{
	system("shutdown -s -t 60");//system("")����ִ��ϵͳ���������stdlib.h
again://goto��䣬ע��  ��
	printf("��ĵ��Խ���60s�ڹػ������롰���ء�ȡ���ػ�\n");
	char arr[100000] = { 0 };
	scanf("%s", arr);
	if ((strcmp(arr, "����")) == 0)
	{
		system("shutdown -a");
		printf("��ȡ��");
	}
	else
	{
		goto again;
	}
	return 0;
}