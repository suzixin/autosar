/* add_by_szx: 在这个例子里实现了类和应用编程分离，通过修改Makefile，将类编译成一个动态链接库 */
#include "Human.h"
#include "Englishman.h"
#include "Chinese.h"

void test_eating(Human *h)
{
	h->eating();
}


int main(int argc, char **argv)
{
	Englishman e;
	Chinese c;

	Human* h[2] = {&e, &c};
	int i;
	for (i = 0; i < 2; i++)
		test_eating(h[i]);

	
	
	return 0;
}

