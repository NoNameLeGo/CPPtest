#include <iostream>
#include <string>

using namespace std;

class PayMethod {
public:
	virtual void pay(double money) = 0;
	virtual ~PayMethod() {};

};

class CashPay : public PayMethod {
public:
	void pay(double money) override {
		cout << "cash pay: " << money << "yuan" << endl;
	}

};

class CardPay : public PayMethod {
public:
	void pay(double money) override {
		cout << "card pay: " << money << "yuan" << endl;
	}

};

void checkout(PayMethod& payMethod, double money) {
	payMethod.pay(money);
}


int main()
{
	CashPay cash;
	CardPay card;
	checkout(cash, 18.5);
	checkout(card, 32);

	return 0;
}