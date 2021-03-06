
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;
/* add_by_szx:  
exception5.cpp的方式太麻烦
直接把基类中的要实现的多态函数声明为虚函数
这时只要捕获基类的引用就可以实现多态调用
*/

class MyException {
public:
	virtual void what(void) { cout<<"This is MyException"<<endl; }
};

class MySubException : public MyException{
public:
	void what(void) { cout<<"This is MySubException"<<endl; }
};


void C(int i)
{
	int a = 1;
	double b= 1.2;
	float c = 1.3;

	if (i == 0)
	{
		cout<<"In C, it is OK"<<endl;
	}
	else if (i == 1)
		throw a;
	else if (i == 2)
		throw b;
	else if (i == 3)
		throw c;
	else if (i == 4)
		throw MyException();
	else if (i == 5)
		throw MySubException();
}

void B(int i)
{
	cout<<"call C ..."<<endl;
	C(i);
	cout<<"After call C"<<endl;
}

void A(int i)
{
	try {
		B(i);
	} catch (int j)
	{
		cout<<"catch int exception "<<j<<endl;
	} catch (double d)
	{
		cout<<"catch double exception "<<d<<endl;
	} catch (MyException &e)
	{
		e.what();
	} catch (...){
		cout<<"catch other exception "<<endl;
	}
}


int main(int argc, char **argv)
{
	int i;
	if (argc != 2)
	{
		cout<<"Usage: "<<endl;
		cout<<argv[0]<<" <0|1|2|3>"<<endl;
		return -1;
	}

	i = strtoul(argv[1], NULL, 0);

	A(i);
	
	return 0;
}


