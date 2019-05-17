
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Father {
private:
	int money;

protected:
	int room_key;
	
public:
	void it_skill(void)
	{
		cout<<"father's it skill"<<endl;
	}

	int getMoney(void)
	{
		return money;
	}

	void setMoney(int money)
	{
		this->money = money;
	}
};

class Son : public Father {
private:
	int toy;
	// 将从父亲那继承的技能（成员函数）公开。
	//using Father::it_skill;
public:
	/* 使用using调整从父类继承来的成员变量/函数的权限 */
	// 将父亲的房间钥匙公开
	using Father::room_key;
	// 将父亲的私房钱公开——失败，因为该成员的权限是private，儿子自己都没办法get到这个成员
	//using Father::money;
	
	void play_game(void)
	{
		int m;
		
		cout<<"son paly game"<<endl;

		/* money -= 1; 
		 * 错: 不能直接拿父亲的私房钱
		 */

		/*
		 * 但是可以问他要
		 */
		m = getMoney();
		m--;
		setMoney(m);

		room_key = 1; 
	}
};


int main(int argc, char **argv)
{
	Son s;

	s.setMoney(10);
	cout << s.getMoney()<<endl;

	s.it_skill();
	s.play_game();

	s.room_key = 1;
	
	return 0;
}


