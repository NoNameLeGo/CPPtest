#include <iostream>
#include<string>
using namespace std;

class BankAccount {
private:
	string accountHolderName;
	string accountNumber;
	double balance;
	string lastTransactionType;
	double lastTransactionAmount;
public:
	BankAccount(string name, string number, double initialBalance) {
		accountHolderName = name;
		accountNumber = number;
		balance = initialBalance;
		lastTransactionType = "无";
		lastTransactionAmount = 0;
	}
	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			lastTransactionType = "存款";
			lastTransactionAmount = amount;
			cout << "已存入: " << amount << endl;
		} else {
			cout << "存款金额无效" << endl;
		}
	}
	void withdraw(double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			lastTransactionType = "取款";
			lastTransactionAmount = amount;
			cout << "已取款: " << amount << endl;
		} else {
			lastTransactionType = "失败";
			lastTransactionAmount = amount;
			cout << "提款金额无效或账户余额不足." << endl;
		}
	}
	void displayAccountInfo() {
		cout << "-----------------------------" << endl;
		cout << "户主: " << accountHolderName << endl;
		cout << "账号: " << accountNumber << endl;
		cout << "余额: " << balance << endl;
		if (lastTransactionType != "无") {
			cout << "最近交易: " << lastTransactionType << " " << lastTransactionAmount << endl;
		}
		cout << "-----------------------------" << endl;
	}
	string getLastTransactionType() const {
		return lastTransactionType;
	}
	double getLastTransactionAmount() const {
		return lastTransactionAmount;
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
