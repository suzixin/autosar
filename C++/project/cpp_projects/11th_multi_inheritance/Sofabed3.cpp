#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Furniture {
private:
	int weight;
public:
	Furniture(){ cout <<"Furniture()"<<endl; }
	void setWeight(int weight) { this->weight = weight; }
	int getWeight(void) const { return weight; }
};

class Sofa : virtual public Furniture {
private:
	int a;
public:
	void watchTV(void) { cout<<"watch TV"<<endl; }
	Sofa(void) { cout<<"Sofa"<<endl; }
};

class Bed : virtual public Furniture {
private:
	int b;
public:
	Bed() { cout <<"Bed()"<<endl; }
	void sleep(void) { cout<<"sleep"<<endl; }
};

class Sofabed : public Sofa, public Bed {
public:
	Sofabed() { cout <<"Sofabed()"<<endl; }
private:
	int c;
};

int main(int argc, char **argv)
{
	Sofabed s;
	/* add_by_szx: ¹¹ÔìË³Ðò·ÖÎö */
	/* 
	Sofabed
		Sofa
			Furniture
		Bed
			Furniture
	*/

	s.watchTV();
	s.sleep();

	s.setWeight(100);

	cout << "--------------\n" << endl;
	Bed x;
	x.sleep();
	cout << "getWeight from x:"<< x.getWeight() << endl;
	x.setWeight(60);
	cout << "getWeight from x:"<< x.getWeight() << endl;

	Sofa y;
	y.watchTV();
	cout << "getWeight from y:"<< y.getWeight() << endl;
	y.setWeight(60);
	cout << "getWeight from y:"<< y.getWeight() << endl;
	return 0;
}


