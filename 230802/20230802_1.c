
//http://t.csdn.cn/kERJ6

#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <string.h>
#include <assert.h>


char* my_strtok(char* str1, const char* str2)
{
	assert(str2);
	if (!*str2)//����뱻�и��Ԫ��δ���룬��ֱ�Ӵ�ӡԭ�ַ��������������в���
		return str1;
	char* s1 = str1;
	char* s2 = (char*)str2;
	static char* a = NULL;//a��Ϊ��¼��
	if (!str1)//������NULLʱ����ȡ��¼��
		s1 = a;
	while (*s1 && *s2)//1.����ַ�����һ���ַ�������Ҫ�и��Ԫ�أ�ֱ��ɾȥ��һ���ַ�
		//2.ɾȥ�������������и��Ԫ��
	{
		if (*s1 == *s2++)
		{
			s1++;
			s2 = (char*)str2;
		}
	}
	if (!*s1)//�жϴ�ʱ��s1�Ƿ�Ϊ��
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