#include<iostream>
using namespace std;
class PhoneCard{
public:
	virtual void performConnect();
	virtual double getBalance(){return 0.00;};
	virtual void performDail(){};
	virtual void list(){};
    double additoryFee;
	long connectNumber;
private:
    long cardNumber;
	int password;
	double balance;
	bool connected;
	int sum_count;
};
void PhoneCard::performConnect(){

}

class Card_201:public PhoneCard{
public:
	Card_201(long cn ,int pw,double b){
		this->cardNumber=cn;
		this->password=pw;
		this->balance=b;
		sum_count=0;
		additoryFee=0.03;
		connectNumber=201;
	}
	virtual void performConnect(){
	long cn;
	int pw;
	while(1){
	cout<<"请输入卡号："<<endl;
	cin>>cn;
	cout<<"请输入密码："<<endl;
	cin>>pw;
	if(cn==cardNumber&&pw==password){
		cout<<"连接成功!"<<endl;
		connected=1;
		break;
	}
	else{
		cout<<"卡号或密码输入错误，连接失败!"<<endl;
		connected=0;
	}
	}
	}
	virtual double getBalance(){
		if(connected==1){
			return balance;
		}
		else
			return 0.00;
	}
	virtual void performDail(){
		int count=0;
		while(connected==1){
			cout<<"拨号成功!"<<endl;
			count++;
			int isgoing;
			cout<<"是否继续拨号，是请输入1，否输入0"<<endl;
			cin>>isgoing;
			if(isgoing==0){
				balance=balance-count*0.3-count*additoryFee;
				break;
			}
			if(balance<0.5){
				cout<<"您的余额已不足0.5元，请及时充值！"<<endl;
			}
			if(balance<0){
				cout<<"您的卡已欠费"<<-balance<<"元，该号已停机，请及时充值!"<<endl;
				break;
			}
		}
		sum_count+=count;
	}
	virtual void list(Card_201 card){
		if(connected==1){
		cout<<"----------------个人信息----------------"<<endl;
		cout<<"卡号:   "<<card.cardNumber<<endl;
		cout<<"拨打电话次数：   "<<card.sum_count<<endl;
		cout<<"当前余额为：     "<<card.getBalance()<<endl;
		cout<<"----------------个人信息----------------"<<endl;
		}
	}
private:
    long cardNumber;
	int password;
	double balance;
	bool connected;
	int sum_count;
};
int main(){
	Card_201 mycard=Card_201(123456,111,50.00);
	mycard.performConnect();
	mycard.performDail();
	mycard.list(mycard);
	return 0;
}









