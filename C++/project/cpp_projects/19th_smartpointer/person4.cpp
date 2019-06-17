
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
		cout<<"sp(const Person *other)"<<endl;
		p = other;
	}

/* add_by_szx: 拷贝构造函数 主要用于赋值操作
会因为格式问题出错
*/
	sp(sp &other)
	{
		cout<<"sp(const Person *other)"<<endl;
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

	/* 相当于:
	 * 1. Person *p = new Person();
	 * 2. sp tmp(p);  ==> sp(Person *other)
	 * 3.
	 * 3.1 sp other(tmp);  ==> sp(sp &other2)
	       问题在于: sp &other2 = tmp; 
	       			 // 错误语法，因为一个引用没办法指向一个临时变量，一个临时的sp对象没办法转换成一个sp引用
	                 const sp& other2 = tmp; //ok
	 * 或
	 * 3.2 sp other(tmp ==> Person*);  ==>sp(Person *other)
	 * // 没办法把一个sp对象隐式转换为一个Person*指针
	 */
	
	sp other = new Person();

	for (i = 0; i < 2; i++)
		test_func(other);
	return 0;
}

