#include <iostream>
#include <string.h>
#include <unistd.h>
/* add_by_szx:  
机制：
dynamic_cast函数去含有 virtual 的类中对应的虚函数表里找类相关信息，来确定当前调用的类是哪一个类。
从这里我们可看出类中对应的虚函数表里也有类相关的信息。
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

void test_eating(Human& h)
{
	Englishman *pe;
	Chinese    *pc;
	
	h.eating();

	/* 想分辨这个"人"是英国人还是中国人? */
	if (pe = dynamic_cast<Englishman *>(&h))
		cout<<"This human is Englishman"<<endl;

	if (pc = dynamic_cast<Chinese *>(&h))
		cout<<"This human is Chinese"<<endl;
	
	
}




int main(int argc, char **argv)
{
	Human h;
	Englishman e;
	Chinese c;

	test_eating(h);
	test_eating(e);
	test_eating(c);


	return 0;
}


