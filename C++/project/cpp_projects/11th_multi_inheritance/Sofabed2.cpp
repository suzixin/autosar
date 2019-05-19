#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Sofa {
private:
	int weight;
public:
	void watchTV(void) { cout<<"watch TV"<<endl; }

	void setWeight(int weight) { this->weight = weight; }
	int getWeight(void) const { return weight; }
};

class Bed {
	private:
		int weight;
public:
	void sleep(void) { cout<<"sleep"<<endl; }
	void setWeight(int weight) { this->weight = weight; }
	int getWeight(void) const { return weight; }
};

class Sofabed : public Sofa, public Bed {
};

int main(int argc, char **argv)
{
	Sofabed s;
	s.watchTV();
	s.sleep();

	//s.setWeight(100); /* error, 有二义性 */
/* add_by_szx: 	可以用以下的方法来显式指示具体用的是哪个父类中的方法，但太麻烦 */
	s.Sofa::setWeight(100);
	
	return 0;
}


