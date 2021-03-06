
#include <stdio.h>
/* add_by_szx: const_cast可以把const去掉。 */

int main(int argc, char **argv)
{
	double d = 100.1;
	int i = d;  // double转为int
	const char *str = "100ask.taobao.com";
	char *str2 = const_cast<char *>(str);
	int *p = reinterpret_cast<int *>(str2); // char *转为int * 

	printf("i = %d, str = 0x%x, p = 0x%x\n", i, reinterpret_cast<unsigned int>(str), reinterpret_cast<unsigned int>(p));

	return 0;
}

