#include <iostream>
using namespace std;

const double PI = 3.14159;

int area(int a)
{
	while (a < 0) {
		if (a > 0) {
			break;
		}
		else {
			cout << "输入错误！请输入正整数" << endl;
		}
		cin >> a;
	}
    return a * a;
}

int area(int a, int b)
{
	while (a < 0 || b < 0) {
		if (a > 0 && b > 0) {
			break;
		}
		else {
			cout << "输入错误！请输入正整数" << endl;
		}
		cin >> a >> b;
	}
    return a * b;
}

float area(float r)
{
	while (r < 0) {
		if (r > 0) {
			break;
		}
		else {
			cout << "输入错误！请输入正整数" << endl;
		}
		cin >> r;
	}
    return PI * r * r;
}

int main()
{
	int a, b;
	float r;
	cout << "请输入正方形的边长(整数):";
	cin >> a;
	cout << "正方形的面积为:" << area(a) << endl;
	cout << "请输入长方形的长和宽(整数，用空格区分):";
	cin >> a >> b;
	cout << "长方形的面积为:" << area(a, b) << endl;
	cout << "请输入圆的半径(可有小数点):";
	cin >> r;
	cout << "圆的面积为:" << area(r) << endl;
	return 0;
}