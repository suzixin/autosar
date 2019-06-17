
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person {

public:

	Person() {
		cout <<"Pserson()"<<endl;
	}


	~Person()
	{
		cout << "~Person()"<<endl;
	}
	void printInfo(void)
	{
		cout<<"just a test function"<<endl;
	}
};

void test_func(void)
{
	Person *p = new Person();
	p->printInfo();
}

int main(int argc, char **argv)
{	
	int i;

/* add_by_szx: 	在这里的子函数中没有释放内存，会造成内存泄露 */
	for (i = 0; i < 2; i++)
		test_func();
	return 0;
}

