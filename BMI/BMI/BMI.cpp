#include <iostream>
using namespace std;

class BMI
{
private:
	float weight;
	float height;
public:
	BMI() : weight(0), height(0) {}
	BMI(float w, float h) : weight(w), height(h) {}

	void SetData() {
		cout << "请输入体重(kg): ";
		cin >> weight;
		cout << "请输入身高(m): ";
		cin >> height;
	}

	float calculate() {
		return weight / (height * height);
	}
};

int main()
{
	BMI bmi;
	bmi.SetData();
	cout << "BMI为: " << bmi.calculate() << endl;
	return 0;
}




/*
	void SetData(float w, float h) {
		weight = w;
		height = h;
	}
*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件