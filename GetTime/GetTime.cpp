#include <iostream>
#include <string>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    void get_time()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main()
{
	//定义Time类对象t1并初始化
	Time t1(14, 43, 45);
	//定义指向整形数据的指针变量p1，并使p1指向t1.hour
	int *p1 = &t1.hour;
	//输出p1所指的数据成员t1.hour
	cout << *p1 << end1;
	//调用对象t1的成员函数get_time
	t1.get_time();
	//定义指向Time类对象的指针变量p2，并使p2指向t1
	Time *p2 = &t1;
	//调用p2所指向对象（即t1）的get_time函数
	p2->get_time();
	//定义指向Time类公用成员函数的指针变量p3
	void (Time::*p3)();
	//使p3指向Time类公用成员函数get_time
	p3 = &Time::get_time;
	//调用对象t1中p3所指的成员函数（即t1.get_time())
	(t1.*p3)();





	return 0;
}