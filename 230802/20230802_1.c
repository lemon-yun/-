
//http://t.csdn.cn/kERJ6

#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <string.h>
#include <assert.h>


char* my_strtok(char* str1, const char* str2)
{
	assert(str2);
	if (!*str2)//如果想被切割的元素未输入，则直接打印原字符串，不进行下列步骤
		return str1;
	char* s1 = str1;
	char* s2 = (char*)str2;
	static char* a = NULL;//a作为记录点
	if (!str1)//当输入NULL时，读取记录点
		s1 = a;
	while (*s1 && *s2)//1.如果字符串第一个字符便是想要切割的元素，直接删去第一个字符
		//2.删去几个连续的想切割的元素
	{
		if (*s1 == *s2++)
		{
			s1++;
			s2 = (char*)str2;
		}
	}
	if (!*s1)//判断此时是s1是否为空
		return NULL;
	a = s1;
	while (*a)
	{
		s2 = (char*)str2;
		while (*s2)
		{
			if (*a == *s2++)
			{
				*a++ = '\0';
				return s1;
			}
		}
		a++;
	}
	return s1;
}

int main()
{
	char arr1[] = "nihao@woshi.zhangsan";
	char arr2[] = "@.";
	//char* p = NULL;
	//char* ret = my_strtok(p, arr2);
	//printf("%s\n", ret);
	for (char* ret = my_strtok(arr1, arr2); ret != NULL; ret = my_strtok(NULL, arr2))
	{
		printf("%s\n",ret);
	}
	return 0;
}