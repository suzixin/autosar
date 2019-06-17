
#include <iostream>
#include <string.h>
#include <unistd.h>
#include "RefBase.h"

using namespace std;
using namespace android::RSC;
/* add_by_szx: 
之前的19th中的指针是非线程安全 的
让引用计数的修改变成原子操作，不可被打断，这里保证了引用计数的修改是线程安全的
但是并不代表这个指针的使用是线程安全的
*/

class Person : public LightRefBase<Person>{

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


template<typename T>
void test_func(sp<T> &other)
{
	sp<T> s = other;

	cout<<"In test_func: "<<s->getStrongCount()<<endl;

	s->printInfo();

	//Person *p = new Person();
	//p->printInfo();
	//delete p;

	
}

int main(int argc, char **argv)
{	
	int i;

	/* 少用"Person *"; 用"sp<Person>"来代替"Person *"
	 * Person *per; 
	 * 有2种操作: per->XXXx, (*per).XXX
	 * sp也应该有这2中操作:
	 *            sp->XXX, (*sp).XXX
	 *
	 */
	sp<Person> other = new Person();

	(*other).printInfo();
	cout<<"Before call test_func: "<<other->getStrongCount()<<endl;

	for (i = 0; i < 2; i++)
	{
		test_func(other);
		cout<<"After call test_func: "<<other->getStrongCount()<<endl;
	}
	return 0;
}

