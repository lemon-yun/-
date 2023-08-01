#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

char* my_strstr(const char* str1,const char* str2)
{
	assert(*str1);
	char* cp = (char*)str1;
	while (*str1)
	{
		char* s1 = (char*)str1;
		char* s2 = (char*)str2;
		while (*s1++ == *s2++ || !*str2)//(！(*s1++ - *s2++) || !*str2)
		{
			if (!*s2)
				return cp;
		}
		cp++;
	}
	return NULL;
}

int main_1()
{
	char arr1[10] = "abbbcdd";
	char arr2[10] = "d";
	if (my_strstr(arr1, arr2) == NULL)
	{
		printf("没找到");
	}
	else
	{
		printf("找到了：%s", my_strstr(arr1, arr2));
	}
	return 0;
}





int main_2()
{
	char arr[] = "qwe.qwe@qwe";
	char* p = ".@";
	char tem[20] = { 0 };
	char tem2[20] = { 0 };
	strcpy(tem,arr);//strtok切割时会将被切割的元素改为“\0”，用备份去切割防止原字符串被改变
	strcpy(tem2, arr);

	char* ret = NULL;

	ret = strtok(tem,p);//strtok 切割字符串
	//   (想切割的字符串，被切割的元素)
	//ret = strtok(tem, "@."); 此写法也行
	printf("%s\n", ret);
	ret = strtok(NULL, p);//第一次切割后，strtok会记住被切割的元素的坐标，输入NULL即可
	printf("%s\n", ret);
	ret = strtok(NULL, p);
	printf("%s\n", ret);

	for (ret = strtok(tem2, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}//妙啊
	return 0;
}



int main()
{
	FILE* pf = fopen("text.txt","r");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));//strerror 返回错误信息的地址
		//errno 全局错误码，需引用errno.h
		return errno;
	}
	fclose(pf);
	pf = NULL;

	return 0;
}