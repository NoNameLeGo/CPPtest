#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	Student(int n, int a, float s):num(n),age(a),score(s){}
	void total();
	static float average();

private:
	int num;
	int age;
	float score;
	static float sum;
	static int count;

};

void Student::total() {
	sum += score;
	count++;
}
float Student::average() {
	return (sum / count);
}

float Student::sum = 0;
int Student::count = 0;

int main()
{
	Student stus[4] = { Student(1001,18,81),
	Student(1002,19,86),Student(1003,18,93),Student(1004,20,87) };
	for (int i = 0; i < 4; i++){
		stus[i].total();
	}

	cout << "平均成绩为：" << Student::average() << endl;
	
	return 0;
}