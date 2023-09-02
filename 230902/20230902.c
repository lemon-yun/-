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

//文件

int main_2()
{
	FILE* pf = fopen("cache.txt", "w");//("文件相对/绝对路径","打开方式")
	if (!pf)
	{
		perror("fopen");
		return 1;
	}

	fputc('a', pf);
	fputc('b', pf);
	fputc('c\n', pf);//在打开的文件里写入一个字符

	fputc('a', stdout);//stdout 标准输出流 - 屏幕，这样可以打印在屏幕上
	fputc('b', stdout);
	fputc('c\n', stdout);

	fputs("afafsgagasgasfasf",pf);//写入一个字符串
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
	int ret = fgetc(pf);//读取一个字符，返回ascii码值或EOF(-1)
	printf("%c", ret);
	ret = fgetc(pf);
	printf("%c", ret);
	ret = fgetc(pf);
	printf("%c", ret);


	printf("\n");


	ret = fgetc(stdin);//stdin 标准输入流 - 键盘，这样可以读取键盘输入的字符
	printf("%c", ret);
	ret = fgetc(stdin);
	printf("%c", ret);


	char arr[30] = "*******";

	fgets(arr,7,pf);//从pf中读取3个字符和1个\0，写入到arr中
	//读到换行符会停止，所以此处输出结果是ab，换行符也会被输入进去
	printf("%s", arr);
	fgets(arr, 30, pf);//会从上次断的地方接着读
	printf("%s\n", arr);
	fgets(arr, 5, pf);//读完了就不会再写入了
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
	//对格式化的数据输入进文件 - fprintf

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
	//读取格式化数据 - fscanf

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
	//二进制的读写

	struct X x = { "hi", 20 };

	FILE* pf = fopen("cache3.txt", "w");
	if (!pf)
	{
		perror("fopen");
		return 1;
	}

	fwrite(&x, sizeof(struct X), 1, pf);
	//将 &x 中的 1 个 sizeof(struct X) 字节的内容以二进制写在 pf 中 
	

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