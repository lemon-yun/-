

#include <stdio.h>
//转义字符

int main_1()
{
	printf("%c\n", '\'');//“\'”使'能够输出出来
	printf("%s\n", "\"");
	printf("a\tbc\n");//“\t”作用相当于TAB
	printf("a\\tbc\n");//“\\”使\能够输出出来
	printf("\a");//电脑响一下
	printf("%c\n", '\130');//八进制130 = 十进制88，88对应的ASCII为X
	printf("%c\n", '\002');
	printf("%d\n", '\x30');//十六进制30 = 十进制48，48对应的ASCII为0
	

	return 0;
}


// \n 换行。
// \t 横向跳格（跳到下一制表位置）。
// \v 竖向跳格。
// \b 退格。
// \r 回车。
// \f 走纸换页。
// \\ 反斜杠字符’\’。
// \’ 单引号字符。
// \a 鸣玲。
// \ddd 1到3位八进制数所代表的字符。
// \xhh 1到2位十六进制数所代表的字符。