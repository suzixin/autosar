#include <iostream>
#include <string.h>
#include <unistd.h>
/* add_by_szx:  
静态类型转换
*/
using namespace std;

class Human {
private:
	int a;
public:
	virtual void eating(void) { cout<<"use hand to eat"<<endl; }
	virtual ~Human() { cout<<"~Human()"<<endl; }
	virtual Human* test(void) {cout<<"Human's test"<<endl; return this; }
};

class Englishman : public Human {
public:
	void eating(void) { cout<<"use knife to eat"<<endl; }
	virtual ~Englishman() { cout<<"~Englishman()"<<endl; }
	virtual Englishman* test(void) {cout<<"Englishman's test"<<endl; return this; }
};


class Chinese : public Human {
public:
	void eating(void) { cout<<"use chopsticks to eat"<<endl; }
	virtual ~Chinese() { cout<<"~Chinese()"<<endl; }
	virtual Chinese* test(void) {cout<<"Chinese's test"<<endl; return this; }
};

class Guangximan : public Chinese {
public:
	void eating(void) { cout<<"use chopsticks to eat, I come from guangxi"<<endl; }
};

void test_eating(Human& h)
{
#if 1
	Englishman& pe = dynamic_cast<Englishman&>(h);
/* add_by_szx: 
如果这里的动态转换出问题了
程序会在运行时崩溃，而不是编译错误。
提示如下：
terminate called after throwing an instance of 'std::bad_cast'
  what():  std::bad_cast
Aborted (core dumped)

*/
	Chinese&    pc = dynamic_cast<Chinese&>(h);
	Guangximan& pg = dynamic_cast<Guangximan&>(h);
#else
	Englishman& pe = reinterpret_cast<Englishman&>(h);
	Chinese&	pc = reinterpret_cast<Chinese&>(h);
	Guangximan& pg = reinterpret_cast<Guangximan&>(h);
#endif

	h.eating();
	
}




int main(int argc, char **argv)
{
	Human h;
	//Englishman e;
	//Chinese c;
	Guangximan g;

	Englishman *pe;

	pe = static_cast<Englishman *>(&h);

	//Englishman *pe2 = static_cast<Englishman *>(&g);
/* add_by_szx: static_cast编译器可以帮我们检查一些错误，如果转换失败会直接报编译错误 */
	Chinese *pc = static_cast<Chinese *>(&g);
	test_eating(g);

	return 0;
}


