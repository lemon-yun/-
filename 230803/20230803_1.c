#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <errno.h>

int main_1()
{

	FILE* pf = fopen("text.txt", "r");
	if (pf == NULL)
	{
		perror("");//ͬ���Ǵ�ӡ������Ϣ������strerror����
		return errno;
	}
	fclose(pf);
	pf = NULL;
	return 0;
}

#include <ctype.h>
int main()
{
	char ch = '4';
	int ret = isdigit(ch);//�ж�һ���ַ��ǲ��������ַ���ע�����ַ��������Ƿ���0���Ƿ��ط�������
	//������ctype.h
	printf("%d", ret);
	return 0;
}