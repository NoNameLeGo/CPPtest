#pragma once
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class VRObject {
private:
	string name;
	double x;
	double y;
	double z;

public:
	void init(string n, double x0, double y0, double z0);
	void setPosition(double x, double y, double z);
	double distanceTo(VRObject& other);
	void displayPosition();

};