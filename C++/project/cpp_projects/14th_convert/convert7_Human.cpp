#include <iostream>
#include <string.h>
#include <unistd.h>

/* add_by_szx: 
上行转换：派生类对象转换为基类对象
下行转换：基类对象转换为派生类对象
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
	//Englishman& pe = dynamic_cast<Englishman&>(h);
	/* add_by_szx: 
	转换引用的时候会有什么问题：
	广西人不能转换为英国人，如果使用引用的时候转换失败程序就会崩溃
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
	//Human h;
	//Englishman e;
	//Chinese c;
	Guangximan g;

	//test_eating(h);
	//test_eating(e);
	//test_eating(c);
	test_eating(g);


	return 0;
}


