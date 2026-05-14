#include <iostream>
#include <string>

using namespace std;

class Pay {
public:
    virtual void pay(double money) = 0;
    virtual ~Pay() {}
};

class WeChatPay : public Pay {
public:
    void pay(double money) override {
        cout << "微信支付，实际支付：" << money << " 元" << endl;
    }
};

class AliPay : public Pay {
public:
    void pay(double money) override {
        if (money >= 1000) {
            money -= 20;
        }
        cout << "支付宝支付，满减后实际支付：" << money << " 元" << endl;
    }
};

class BankPay : public Pay {
public:
    void pay(double money) override {
        money *= 1.01;
        cout << "银行卡支付，含手续费实际支付：" << money << " 元" << endl;
    }
};

int main()
{
    WeChatPay wechat;
    AliPay alipay;
    BankPay bank;

    Pay* p1 = &wechat;
    Pay* p2 = &alipay;
    Pay* p3 = &bank;

    p1->pay(1200);
    p2->pay(1200);
    p3->pay(1200);

    return 0;
}