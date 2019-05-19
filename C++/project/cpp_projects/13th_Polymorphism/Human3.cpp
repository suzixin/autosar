#include <iostream>
#include <string.h>
#include <unistd.h>
/* add_by_szx:  
test_func(Human* h):
test_func(Human& h)：使用指针或引用来使用对象时，才有多态
test_func(Human h)：传值时，无多态
*/
using namespace std;

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

void test_eating(Human h)
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

	cout<<"sizeof(Human) = "<<sizeof(h)<<endl;
	cout<<"sizeof(Englishman) = "<<sizeof(e)<<endl;
	cout<<"sizeof(Chinese) = "<<sizeof(c)<<endl;

	return 0;
}


