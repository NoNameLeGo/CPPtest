#include <iostream>
#include "Counter.h"
using namespace std;

int main()
{
	Counter counter;
	counter.increment();
	counter.increment();
	counter.decrement();
	cout << "当前计数: " << counter.getCount() << endl;

	return 0;
}
