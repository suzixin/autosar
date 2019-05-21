/* add_by_szx: 在这里包含了Englishman.h，如果修改这个头文件的话需要全编，只编译动态库是不够的。 */
/* add_by_szx: 所以引入了界面编程。 */
#include "Human.h"
#include "Englishman.h"
#include "Chinese.h"

void test_eating(Human *h)
{
	h->eating();
}


int main(int argc, char **argv)
{
	Englishman e("Bill", 10, "sfwqerfsdfas");
	Chinese c;

	Human* h[2] = {&e, &c};
	int i;
	for (i = 0; i < 2; i++)
		test_eating(h[i]);

	
	
	return 0;
}

