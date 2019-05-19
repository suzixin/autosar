#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;
/* add_by_szx: 引入了虚函数的概念 */
/*
机制：
	静态联编：非虚函数，在编译时确定好调用的函数。
	动态联编：虚函数
		对象里有指针，指向虚函数表
		调用时，通过指针，找到表，调用对应的虚函数。
*/
class Human {
private:
	int a;
public:
	virtual void eating(void) { cout<<"use hand to eat"<<endl; }
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
/* add_by_szx: 验证虚函数实现机制，看是否确实添加了一个虚拟的指针 
   经过验证确实添加了12字节的指针。
*/
	cout<<"sizeof(Human) = "<<sizeof(h)<<endl;
	cout<<"sizeof(Englishman) = "<<sizeof(e)<<endl;
	cout<<"sizeof(Chinese) = "<<sizeof(c)<<endl;

	return 0;
}


