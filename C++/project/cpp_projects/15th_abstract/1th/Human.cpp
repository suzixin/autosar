#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;
/* add_by_szx:  
一个类里有纯虚函数，这个类就是抽象类，抽象类不能实例化对象。
*/
class Human {
private:
	int a;
public:
/* add_by_szx: 	纯虚函数 */
	virtual void eating(void) = 0;
	virtual void wearing(void) = 0;
	virtual void driving(void) = 0;
	virtual ~Human() { cout<<"~Human()"<<endl; }
	virtual Human* test(void) {cout<<"Human's test"<<endl; return this; }
};

class Englishman : public Human {
public:
	void eating(void) { cout<<"use knife to eat"<<endl; }
	void wearing(void) {cout<<"wear english style"<<endl; }
	void driving(void) {cout<<"drive english car"<<endl; }
	virtual ~Englishman() { cout<<"~Englishman()"<<endl; }
	virtual Englishman* test(void) {cout<<"Englishman's test"<<endl; return this; }
};


class Chinese : public Human {
public:
	void eating(void) { cout<<"use chopsticks to eat"<<endl; }
	void wearing(void) {cout<<"wear chinese style"<<endl; }
	void driving(void) {cout<<"drive chinese car"<<endl; }
	virtual ~Chinese() { cout<<"~Chinese()"<<endl; }
	virtual Chinese* test(void) {cout<<"Chinese's test"<<endl; return this; }
};



int main(int argc, char **argv)
{
	//Human h;
	Englishman e;
	Chinese c;

	return 0;
}


