#include <bits/stdc++.h>
using namespace std;
//encapsulation
class Customer {
    string name;
    int account_number , balance;
    static int total_customer; // static are common for all 
    int age;

    public:

    Customer(string name, int account_number, int balance, int age){
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
        this->age = age;
        total_customer++;
    }
    void updateAge(int x){
        if(x > 0 && x < 100){
            this->age = x;
        }else{
            cout << "Invalid Age" << endl;
        }
    }
    void static accessStatic(){ // static member function, it access only static one
        cout << total_customer << endl;
    }
    void display(){
        cout << name << " " << account_number << " " << balance << " " << total_customer << " " << age <<endl;

    }
};

int Customer:: total_customer = 0;

int main(){
    Customer A1("faiz", 1, 1000, 24);
    Customer A2("umair", 2, 1200, 24);


    A1.updateAge(23);
    A1.display();
    A2.display();

    
}