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
		while (*s1++ == *s2++ || !*str2)//(��(*s1++ - *s2++) || !*str2)
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
		printf("û�ҵ�");
	}
	else
	{
		printf("�ҵ��ˣ�%s", my_strstr(arr1, arr2));
	}
	return 0;
}





int main_2()
{
	char arr[] = "qwe.qwe@qwe";
	char* p = ".@";
	char tem[20] = { 0 };
	char tem2[20] = { 0 };
	strcpy(tem,arr);//strtok�и�ʱ�Ὣ���и��Ԫ�ظ�Ϊ��\0�����ñ���ȥ�и��ֹԭ�ַ������ı�
	strcpy(tem2, arr);

	char* ret = NULL;

	ret = strtok(tem,p);//strtok �и��ַ���
	//   (���и���ַ��������и��Ԫ��)
	//ret = strtok(tem, "@."); ��д��Ҳ��
	printf("%s\n", ret);
	ret = strtok(NULL, p);//��һ���и��strtok���ס���и��Ԫ�ص����꣬����NULL����
	printf("%s\n", ret);
	ret = strtok(NULL, p);
	printf("%s\n", ret);

	for (ret = strtok(tem2, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}//�
	return 0;
}



int main()
{
	FILE* pf = fopen("text.txt","r");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));//strerror ���ش�����Ϣ�ĵ�ַ
		//errno ȫ�ִ����룬������errno.h
		return errno;
	}
	fclose(pf);
	pf = NULL;

	return 0;
}