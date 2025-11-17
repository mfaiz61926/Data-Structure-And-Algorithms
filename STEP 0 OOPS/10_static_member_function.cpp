#include <bits/stdc++.h>
using namespace std;
// they are attribute of classes or class member "static keyword"
//static public main ho to bina object ke bhi access kr sakte hai scope resolution operator ka use krke
class Customer {
    string name;
    int account_number , balance;
    static int total_customer; // static are common for all 

    public:

    Customer(string name, int account_number, int balance){
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
        total_customer++;
    }

    void static accessStatic(){ // static member function, it access only static one
        cout << total_customer << endl;
    }
    void display(){
        cout << name << " " << account_number << " " << balance << " " << total_customer<<endl;

    }
};

int Customer:: total_customer = 0;

int main(){
    Customer A1("faiz", 1, 1000);
    Customer A2("umair", 2, 1200);

    A1.display();
    A2.display();
    Customer::accessStatic();

    
}