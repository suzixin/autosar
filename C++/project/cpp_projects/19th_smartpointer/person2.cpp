
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
	//Person *p = new Person();
	Person per;
	per.printInfo();
}

int main(int argc, char **argv)
{	
	int i;
/* add_by_szx: 	用局部变量来改善这个问题，生命周期结束，调用析构函数 */
	for (i = 0; i < 2; i++)
		test_func();
	return 0;
}

