#include <iostream>
#include<string>
using namespace std;

class BankAccount {
private:
	string accountHolderName;
	string accountNumber;
	double balance;
public:
	BankAccount(string name, string number, double initialBalance) {
		accountHolderName = name;
		accountNumber = number;
		balance = initialBalance;
	}
	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "已存入: " << amount << endl;
		} else {
			cout << "存款金额无效" << endl;
		}
	}
	void withdraw(double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			cout << "已取款: " << amount << endl;
		} else {
			cout << "提款金额无效或账户余额不足." << endl;
		}
	}
	void displayAccountInfo() {
		cout << "-----------------------------" << endl;
		cout << "户主: " << accountHolderName << endl;
		cout << "账号: " << accountNumber << endl;
		cout << "余额: " << balance << endl;
		cout << "-----------------------------" << endl;
	}
};

int main()
{
	BankAccount account("John Doe", "123456789", 1000.1);
	account.displayAccountInfo();
	account.deposit(500);
	account.withdraw(200);
	account.displayAccountInfo();
	return 0;
}
