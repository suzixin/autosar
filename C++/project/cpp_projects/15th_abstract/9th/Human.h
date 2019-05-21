

#ifndef _HUMAN_H
#define _HUMAN_H

#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Human {
private:
	char *name;

public:
	void setName(char *name);
	char *getName(void);
	virtual void eating(void) = 0;
	virtual void wearing(void) = 0;
	virtual void driving(void) = 0;
/* add_by_szx: 	这里要实现析构函数的多态，所以要定义为一个虚函数。 */
/* add_by_szx: 	一般来说，析构函数不会定义为纯虚函数，如果这样做的话需要在子类中实现一个父类的析构函数，不合逻辑 */
	virtual ~Human() {cout<<"~Human"<<endl;}
	
};

Human& CreateEnglishman(char *name, int age, char *address);
Human& CreateChinese(char *name, int age, char *address);

#endif

