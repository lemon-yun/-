#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <string.h>

struct S
{
	char a[10];
	int b;
	float c;
};
int main_1()
{
	struct S s = { "abc", 1, 5.5 };
	char ip[20] = { 0 };
	sprintf(ip, "%s %d %f", s.a, s.b, s.c);//�ո�Ҫ�ӣ���Ȼ������ܻ��ȡ����
	//sprintf �Ѹ�ʽ��������дΪ�ַ���
	printf("%s\n", ip);
	printf("%d\n", strlen(ip));

	printf("\n");

	struct S b = { 0 };
	sscanf(ip, "%s %d %f", b.a, &b.b, &b.c);//�ɲ��ӿո�
	//sscanf ���ַ������ȡ��ʽ��������
	printf("%s %d %f", b.a, b.b, b.c);

	return 0;
}


int main_2()
{
	FILE* pf = fopen("text.txt", "r");
	if (!pf)
	{
		return 1;
	}
	//�����д
	char ch = fgetc(pf);
	printf("%c\n", ch);//a

	fseek(pf, -1, SEEK_CUR);//�ӵ�ǰָ��λ�õ� -1 λ�ö�д
	//������һ����������Ҳ��a
	ch = fgetc(pf);
	printf("%c\n", ch);

	fseek(pf, -2, SEEK_END);//���ļ�ĩβλ�õ� - λ�ö�д
	//������һ������������e
	ch = fgetc(pf);
	printf("%c\n", ch);

	fseek(pf, 3, SEEK_SET);//���ļ���ͷλ�õ� 3 λ�ö�д
	//������һ������������d
	ch = fgetc(pf);
	printf("%c\n", ch);

	ch = fgetc(pf);
	printf("%c\n", ch);//e

	int p = ftell(pf);//�����ļ�ָ���൱����ʼλ�õ�ƫ����
	printf("%d\n", p);

	rewind(pf);//���ļ�ָ��ص���ʼλ�ÿ�ʼ��д
	ch = fgetc(pf);
	printf("%c\n", ch);//a

	fclose(pf);
	pf = NULL;
	return 0;
}


int main()
{
	FILE* pr = fopen("text2.txt", "r");
	if (!pr)
	{
		return 1;
	}
	FILE* pw = fopen("tect3.txt", "w");
	if (!pw)
	{
		return 2;
	}

	char ch = 0;
	while ((ch = fgetc(pr)) != EOF)
	{
		fputc(ch,pw);
	}
	if (feof(pr))
		//��ȡ���ļ�ĩβ����feof����һ������ֵ����������ļ�ָ�벻�����ļ�ĩβ����0
		//There is no error return.(����˵���᷵�ش�������)
	{
		printf("������ȡ����");
	}
	else if (ferror(pr))//�д��󷵻ض�Ӧ��0������
	{
		printf("�ļ���ȡʧ�ܽ���");
	}

	fclose(pr);
	pr = NULL;
	fclose(pw);
	pw = NULL;
	return 0;
}

