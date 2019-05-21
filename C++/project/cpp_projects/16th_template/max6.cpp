#include <iostream>
#include <string.h>
#include <unistd.h>
/* add_by_szx:  
template推导过程计算步骤;
- 列出满足条件的候选函数
- 比较这些候选的优先级，选中一个最优的函数来调用

1--2 优先选择不需要类型转换的
2--3 普通函数和模板函数，优先选择普通函数
*/
using namespace std;

/*
int& max(int& a, int& b)
{
	return (a < b)? b : a;
}

double& max(double& a, double& b)
{
	return (a < b)? b : a;
}

float& max(float& a, float& b)
{
	return (a < b)? b : a;
}
*/

template<typename T>
const T& mymax(const T& a, const T& b)
{
	cout<<"1: "<<__PRETTY_FUNCTION__<<endl;
	return (a < b)? b : a;
}

template<typename T>
const T& mymax(T& a, T& b)
{
	cout<<"2: "<<__PRETTY_FUNCTION__<<endl;
	return (a < b)? b : a;
}


const int& mymax(int& a, int& b)
{
	cout<<"3: "<<__PRETTY_FUNCTION__<<endl;
	return (a < b)? b : a;
}

int main(int argc, char **argv)
{
	int ia = 1;
	int ib = 2;

	cout<<mymax(ia, ib)<<endl;

	return 0;
}


