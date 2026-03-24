#include<string>
#include <iostream>
using namespace std;

class Counter {
private:
	int count;
public:
	Counter() {
		count = 0;
	}
	void increment() {
		count++;
	}
	void decrement() {
		count--;
	}
	int getCount() {
		cin >> count;
		return count;
	}
};

int main()
{
	Counter counter;
	counter.getCount();
	counter.increment();
	counter.decrement();


	return 0;
}
