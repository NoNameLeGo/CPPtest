
#include <string>
using namespace std;

class Student
{
public:
	void SetInfo(string n, int a);
	void DiplayInfo();
private:
	string name;
	int age;
};