#pragma once
#include<iostream>
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
		cin << "Count: " << count << endl;
		return count;
	}
};