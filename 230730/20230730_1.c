#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	char arr1[20] = "abcd";
	char arr2[20] = "abcd";
	char arr3[] = "cd";
	strcat(arr1, "fg");//把fg加到arr1后
	strncat(arr2, arr2, 4);//把自己加到自己后面，加4个字节的内容
	char* p = strstr(arr2, arr3);//判断arr3是否为arr2的子链，如果不是，返回空指针
	//char *strstr( const char *string, const char *strCharSet );
	//Each of these functions returns a pointer to the first occurrence of strCharSet in string, 
	//or NULL if strCharSet does not appear in string. 
	//If strCharSet points to a string of zero length, the function returns string.


	return 0;
}