
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

class sp {
private:
	Person *p;

public:
	sp() : p(0) {}
	
	sp(Person *other)
	{
		cout<<"sp(Person *other)"<<endl;
		p = other;
	}

	sp(const sp &other)
	{
		cout<<"sp(const sp &other)"<<endl;
		p = other.p;
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

void test_func(sp &other)
{
	sp s = other;

	s->printInfo();

	//Person *p = new Person();
	//p->printInfo();
	//delete p;

	
}

int main(int argc, char **argv)
{	
	int i;

	sp other = new Person();

	for (i = 0; i < 2; i++)
		test_func(other);
/* add_by_szx: 	在这里引入了引用计数的概念 
在第一次调用test_func时，other.p指向上面new创建出来的地址
这时test_func中的s.p和main中的other.p指向同一块地址
在test_func调用结束时，销毁s，释放s.p。
然而这时mian中的other还需要这个p，释放之后在下一次调用test_func时传入的other里的p就是未知值
导致了错误的发生。

为此，引入了智能指针中引入计数的概念。
*/
	return 0;
}

