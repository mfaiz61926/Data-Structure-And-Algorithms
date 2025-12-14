#include <iostream>
using namespace std;
class customer{
    string name;
    int account_no,balance;
    public:
    customer(string name , int account_no, int balance){
        this->name = name;
        this->account_no = account_no;
        this->balance = balance;
    }

    void diposit(int amount){
        if(amount > 0){
            balance += amount;
            cout<<"Rs."<<amount<<" is credited successfully\n";
        }
        else{
            throw"amount should be greater than 0\n";
        }
    }
    void withdraw(int amount){
        if(amount > 0&&amount<=balance){
            balance -= amount;
            cout<<"Rs."<<amount<<" is debited successfully\n";
        }
        else if(amount < 0){
            throw"amount should be greater than 0\n";
        }
        else{
            throw"Your balance is low\n";
        }
    }

    void display(){
        cout<<name<<endl<<account_no<<endl<<balance<<endl;
    }
};
int main ()
{
    customer A1("arbaz",700400415,500000);
    try{
        A1.display();
        A1.withdraw(50000);
        A1.display();
        A1.diposit(25000);
        A1.display();
        A1.withdraw(500000);
    }
    catch(const char *e){
        cout<<"Exception Occured: "<<e<<endl;
    }
    
}