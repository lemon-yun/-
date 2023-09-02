#define _CRT_SECURE_NO_WARNINGS 11

#include <stdio.h>

int main_1()
{
	int n; scanf("%d", &n);
	int arr[51] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int m; scanf("%d", &m);
	arr[n] = m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int a = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = a;
			}
		}
	}

	for (int i = 0; i <= n; i++)
	{
		printf("%d", arr[i]);
		if (i < n)
		{
			printf(" ");
		}
	}

	return 0;
}

//�ļ�

int main_2()
{
	FILE* pf = fopen("cache.txt", "w");//("�ļ����/����·��","�򿪷�ʽ")
	if (!pf)
	{
		perror("fopen");
		return 1;
	}

	fputc('a', pf);
	fputc('b', pf);
	fputc('c\n', pf);//�ڴ򿪵��ļ���д��һ���ַ�

	fputc('a', stdout);//stdout ��׼����� - ��Ļ���������Դ�ӡ����Ļ��
	fputc('b', stdout);
	fputc('c\n', stdout);

	fputs("afafsgagasgasfasf",pf);//д��һ���ַ���
	fputs("asf", stdout);

	fclose(pf);
	pf = NULL;
	return 0;
}



int main_3()
{
	FILE* pf = fopen("cache.txt", "r");
	if (!pf)
	{
		perror("fopen");
		return 1;
	}
	int ret = fgetc(pf);//��ȡһ���ַ�������ascii��ֵ��EOF(-1)
	printf("%c", ret);
	ret = fgetc(pf);
	printf("%c", ret);
	ret = fgetc(pf);
	printf("%c", ret);


	printf("\n");


	ret = fgetc(stdin);//stdin ��׼������ - ���̣��������Զ�ȡ����������ַ�
	printf("%c", ret);
	ret = fgetc(stdin);
	printf("%c", ret);


	char arr[30] = "*******";

	fgets(arr,7,pf);//��pf�ж�ȡ3���ַ���1��\0��д�뵽arr��
	//�������з���ֹͣ�����Դ˴���������ab�����з�Ҳ�ᱻ�����ȥ
	printf("%s", arr);
	fgets(arr, 30, pf);//����ϴζϵĵط����Ŷ�
	printf("%s\n", arr);
	fgets(arr, 5, pf);//�����˾Ͳ�����д����
	printf("%s\n", arr);

	fclose(pf);
	pf = NULL;
	
	return 0;
}




struct S
{
	char arr[10];
	int n;
};
struct B
{
	char arr[10];
	int n;
};
int main_4()
{
	struct S s = { "hi", 20 };

	FILE* pf = fopen("cache2.txt", "w");
	if (!pf)
	{
		perror("fopen");
		return 1;
	}
	//�Ը�ʽ��������������ļ� - fprintf

	fprintf(pf,"%s %d",s.arr,s.n);

	fclose(pf);
	pf = NULL;

	///////////////
	printf("\n");

	struct B b = {0};

	FILE* p = fopen("cache2.txt", "r");
	if (!p)
	{
		perror("fopen");
		return 1;
	}
	//��ȡ��ʽ������ - fscanf

	fscanf(p,"%s %d", b.arr,&b.n);
	printf("%s %d", b.arr, b.n);


	fclose(p);
	p = NULL;

	return 0;
}

struct X
{
	char arr[10];
	int n;
};
struct Y
{
	char arr[10];
	int n;
};
int main()
{
	//�����ƵĶ�д

	struct X x = { "hi", 20 };

	FILE* pf = fopen("cache3.txt", "w");
	if (!pf)
	{
		perror("fopen");
		return 1;
	}

	fwrite(&x, sizeof(struct X), 1, pf);
	//�� &x �е� 1 �� sizeof(struct X) �ֽڵ������Զ�����д�� pf �� 
	

	fclose(pf);
	pf = NULL;

	///////////////
	printf("\n");

	struct Y y = { 0 };

	FILE* p = fopen("cache3.txt", "r");
	if (!p)
	{
		perror("fopen");
		return 1;
	}

	fread(&y, sizeof(struct Y), 1, p);
	printf("%s %d", y.arr, y.n);

	fclose(p);
	p = NULL;

	return 0;
}