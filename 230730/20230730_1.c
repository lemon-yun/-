#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	char arr1[20] = "abcd";
	char arr2[20] = "abcd";
	char arr3[] = "cd";
	strcat(arr1, "fg");//��fg�ӵ�arr1��
	strncat(arr2, arr2, 4);//���Լ��ӵ��Լ����棬��4���ֽڵ�����
	char* p = strstr(arr2, arr3);//�ж�arr3�Ƿ�Ϊarr2��������������ǣ����ؿ�ָ��
	//char *strstr( const char *string, const char *strCharSet );
	//Each of these functions returns a pointer to the first occurrence of strCharSet in string, 
	//or NULL if strCharSet does not appear in string. 
	//If strCharSet points to a string of zero length, the function returns string.


	return 0;
}