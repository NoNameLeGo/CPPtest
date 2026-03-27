#include"VRObject.h"

void VRObject::init(string n, double x0, double y0, double z0) {
	name = n;
	x = x0;
	y = y0;
	z = z0;
}

void VRObject::setPosition(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

double VRObject::distanceTo(VRObject& other) {
	double dx = x - other.x;
	double dy = y - other.y;
	double dz = z - other.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

void VRObject::displayPosition() {
	cout << endl;
	cout << "-----------------------------" << endl;
	cout << "物体名称: " << name << endl;
	cout << "坐标: (" << x << ", " << y << ", " << z << ")" << endl;
	cout << "-----------------------------" << endl;
	cout << endl;
}