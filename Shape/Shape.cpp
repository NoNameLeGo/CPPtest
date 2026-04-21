#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
	string color;

public:
    Shape() {
        color = "white";
	}

    void draw() {
        cout << "Drawing a shape" << endl;
	}

};

class Circle : public Shape {
private:
    double radius;

public:
    void setRadius(double r) {
        radius = r;
    }

    double getArea() {
        return 3.14159 * radius * radius;
    }

    void draw() {
        cout << "Drawing a circle with color: " << color << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    void setSize(double w, double h) {
        width = w;
        height = h;
    }

    double getArea() {
        return width * height;
    }

    void draw() {
        cout << "Drawing a rectangle with color: " << color << endl;
    }
};


int main()
{
    Circle c;
    c.setRadius(5);
    c.draw();
    cout << "Area: " << c.getArea() << endl;
    cout << endl;

    Rectangle r;
    r.setSize(4, 6);
    r.draw();
    cout << "Area: " << r.getArea() << endl;

    return 0;
}