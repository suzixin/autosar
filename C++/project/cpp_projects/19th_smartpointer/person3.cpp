
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

/* add_by_szx: 我们自己写的智能指针类 
通过这个智能指针，可以在这个类的实例析构的时候释放我们在构造的时候传入的申请的内存地址。
*/
class sp {
private:
	Person *p;

public:
	sp() : p(0) {}
	
	sp(Person *other)
	{
		cout<<"sp(const Person *other)"<<endl;
		p = other;
	}

	~sp()
	{
		cout<<"~sp()"<<endl;
		if (p)
			delete p;
	}

	Person *operator->()
	{
		return p;
	}
	
};

void test_func(void)
{
	sp s = new Person();
/* add_by_szx: 这里实现了->的重载，从而可以通过`sp`类来调用person类里面的方法 
在这个->的重载中的细节，详细可参考 https://blog.csdn.net/custa/article/details/5674434
这里等效于因为这个->的左操作数是一个类的实例，所以这里s->printInfo等价于s.operator->()->printInfo;
*/
	s->printInfo();

	//Person *p = new Person();
	//p->printInfo();
/* add_by_szx: 	如果忘记这个delete就会造成内存泄露 */
	//delete p;

	
}

int main(int argc, char **argv)
{	
	int i;

	for (i = 0; i < 2; i++)
		test_func();
	return 0;
}

