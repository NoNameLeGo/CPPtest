#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
private:
	string id;
	string name;
	double price;

public:
	Product(const string& id = "001", const string& name = "No Name", double price = 0.0)
		: id(id), name(name), price(price) {
	}
	string getId() const { return id; }
	string getName() const { return name; }
	double getPrice() const { return price; }
};

class DiscountProduct : public Product {
private:
	double discount;
public:
	DiscountProduct(const string& id = "001", const string& name = "No Name", double price = 0.0, double discount = 0.0)
		: Product(id, name, price), discount(discount) {
	}
	double getDiscount() const { return discount; }
	double finalPrice() const { return getPrice() * discount; }

	void display() const {
		cout << "Product ID: " << getId() << endl;
		cout << "Product Name: " << getName() << endl;
		cout << "Original Price: $" << getPrice() << endl;
		cout << "Discount Rate: " << getDiscount() * 100 << "%" << endl;
		cout << "Discounted Price: $" << finalPrice() << endl;
	}

};


int main()
{
	vector<DiscountProduct> books;
	books.push_back(DiscountProduct("001", "C++ Programming", 59.99, 0.1));
	books.push_back(DiscountProduct("002", "Data Structures", 49.99, 0.15));
	books.push_back(DiscountProduct("003", "Algorithms", 39.99, 0.2));
	books.push_back(DiscountProduct("004", "Operating Systems", 69.99, 0.12));
	books.push_back(DiscountProduct("005", "Computer Networks", 54.99, 0.18));

	double total = 0;

	for (const auto& book : books) {
		book.display();
		cout << endl;
		total += book.finalPrice();
	}
	cout << "Total Revenue: $" << total << endl;
}