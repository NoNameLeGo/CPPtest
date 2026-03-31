#include <iostream>
#include<string>

using namespace std;

class Time {
private:
	int hours;
	int minutes;
	int seconds;

public:
	void setTime();
	void showTime();
	Time(){
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	Time(int h, int m, int s) {
		hours = h;
		minutes = m;
		seconds = s;
	}

};

void Time::setTime(){
	cout << "请输入北京时间的小时、分钟和秒数（以空格分隔）: ";
	cin >> hours >> minutes >> seconds;
}

void Time::showTime() {
	cout << "北京时间为:" << hours << ":" << minutes << ":" << seconds << endl;
}

int main()
{
	Time t;
	t.setTime();
	t.showTime();

	Time t2;
	t2.showTime();

	Time t3(12, 30, 45);
	t3.showTime();

	return 0;
}
