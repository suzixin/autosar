#include <iostream>
#include <string.h>
#include <unistd.h>
/* add_by_szx: 多态的定义：我们使用不同的对象调用同一个方法，会根据对象去调用它里面不同的函数。 
   这是通过虚函数机制实现的，在这里这样的调用是失败的，见下一个文件。
*/
using namespace std;

class Human {
public:
	void eating(void) { cout<<"use hand to eat"<<endl; }
};

class Englishman : public Human {
public:
	void eating(void) { cout<<"use knife to eat"<<endl; }
};


class Chinese : public Human {
public:
	void eating(void) { cout<<"use chopsticks to eat"<<endl; }
};

void test_eating(Human& h)
{
	h.eating();
}

int main(int argc, char **argv)
{
	Human h;
	Englishman e;
	Chinese c;

	test_eating(h);
	test_eating(e);
	test_eating(c);

	return 0;
}


