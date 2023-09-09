

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main_1()
{
	//C++风格打印字符串
	string str = "Hello World!";//需引用 <string>
	cout << str << endl;

	return 0;
}

int main_2()
{
	//C++的随机数
	srand((unsigned int)time(NULL));//需引用 <ctime>
	int ret = rand();

	return 0;
}