

#include <stdio.h>

int main_1()
{
	int arr[10] = { 1,22,34,35,2,56,2,5,2,5 };
	printf("%d", &arr[9] - &arr[0]);//���Ϊ9������ָ����������Ϊ����ָ��֮���Ԫ�ظ���
	//����ָ�������ǰ�ᣬ����ָ��ָ��ͬһ��ռ�
	return 0;
}

int my_strlen(char* str)
{
	char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}

int main()
{
	int len = my_strlen("abc");
	printf("%d", len);

	return 0;
}