

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//函数

int A(int x, int y)
{
	int z = x + y;
	return z;
	
}//定义一个函数A，它的功能是将两个数相加

int main_4()
{
	int num1;
	int num2;
	scanf("%d %d", &num1, &num2);
	int he = A(num1, num2);
	printf("%d", he);
}



//算术操作符
int main_5()
{
	float a = 9 / 2;
	float b = 9.0 / 2;
	printf("%f\n", a);//结果为4.000000
	printf("%f\n", b);//结果为4.500000，即 / 两边需要至少一个为小数\
	                  才能得到小数结果
	printf("%.1f\n", b);//结果为4.5


	int c = 9 % 2;
	printf("%d", c);//结果为1，% 取模（余）

	return 0;
}



//移位操作符

int main_6()
{
	
	int d = 2 << 1;
	printf("%d\n", d);//结果为4，移位操作符是以二进制进行操作\
	                    int长度为4字节，32个比特位，则2的二进制序列\
	                    为00000000000000000000000000000010\
	                    然后向左移动一位，左边多出的0删去，右边的空位\
	                    用0补上，变为\
	                    00000000000000000000000000000100\
	                    即十进制4
	int e = 2 >> 2;
	printf("%d\n", e);

	return 0;
}



//赋值操作符

int main_7()
{
	int f = 1;
	f += 5;//等价于 f = f + 5
	printf("%d\n", f);

	return 0;
}


//单目操作符


int main_8()
{
	int g = 10;
	printf("%d\n", !g);
	int h = 0;
	printf("%d\n", !h);
	//!，逻辑反操作，0为假，非0为真
	//所以!g输出为0，!h输出为1


	return 0;
}

int main_9()
{
	int i = 0;
	printf("%d\n", ~i);//结果为-1
	//~按位取反，整型中0的二进制位为00000000000000000000000000000000
	//按位取反则把0变为1，1变为0，即11111111111111111111111111111111
	//为-1
	int j = 1;
	printf("%d\n", ~j);
	return 0;
}
//整型在内存中储存为补码
//对于-1
//10000000000000000000000000000001（原码），第一位为符号位
//11111111111111111111111111111110（反码），符号位不变，其他位取反
//11111111111111111111111111111111（补码），反码最后一位加1
//正整数的原码，反码，补码相同



int main_10()
{
	int k = 3;
	int l = ++k;//前置++，先让 k++ ，即k变为4，再将l赋值为k
	printf("%d\n", k);//结果为4
	printf("%d\n", l);//结果为4

	int m = 3;
	int n = m++;//后置++，先将n赋值为m，再让 m++

	printf("%d\n", m);//结果为4
	printf("%d\n", n);//结果为3

	//--原理相同

	return 0;
}



int main_11()
{
	int o = (int)3.14;//强制类型转换
	printf("%d\n", o);

	return 0;
}


//逻辑操作符

int main_12()
{
	int p = 1;
	int q = 1;
	int r = p && q;
	printf("%d\n", r);//结果为1
	int s = 0;
	int t = p && s;
	printf("%d\n", t);//结果为0
	int u = s && s;
	printf("%d\n", u);//结果为0

	// && ，逻辑与，并、和的意思，两个都为真，结果为真，其它都为假

	int v = p || q;
	printf("%d\n", v);//结果为1
	int w = p || s;
	printf("%d\n", w);//结果为1
	int x = s || s;
	printf("%d\n", x);//结果为0

	// || ，逻辑或，或的意思，两个都为假，结果为假，其它都为真



	return 0;
}


//条件操作符（三目操作符）

int main_13()
{
	int y = 1;
	int z = 0;
	int max = y > z ? y : z;
	printf("%d\n", max);

	//exp1 ? exp2 : exp3 (exp为一个表达式)
	//当exp1成立，exp2计算，整个结果为exp2的结果
	//当exp1不成立，exp3计算，整个结果为exp3的结果

	return 0;
}



//逗号表达式

int main_14()
{
	int aa = 1;
	int ab = 2;
	int ac = 3;
	int ad = (aa = ab + ac, ab = aa + 1, ac = ab + aa);
	//从左到右依次计算
	//表达式的结果是最后一个表达式的结果
	printf("%d\n", ad);

	return 0;
}