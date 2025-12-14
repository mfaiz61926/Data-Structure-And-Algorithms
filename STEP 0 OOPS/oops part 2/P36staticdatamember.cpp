#include <iostream>
using namespace std;
class customer
{
    string name;
    int acc_num, balance;
    static int  total_account;
    static int total_balance;
 
    public:
    //static int  total_account;
    customer(string name, int acc_num, int balance)
    {
        this->name = name;
        this->acc_num = acc_num;
        this->balance = balance;
        total_account++;
        total_balance += balance;

    }

    void diposit(int amount){
        if (amount>0){
            balance += amount;
            total_balance += amount;
        }
    }
    void withdraw(int amount){
        if (amount<=balance&&amount>0){
            balance -= amount;
            total_balance -= amount;
        }
    }

    void display(){
        cout<<name<<" "<<acc_num<<" "<<balance<<" "<<total_account<<endl;
    }
    void total(){
        cout<<total_account<<endl;
    }
    static void accesStatic(){
        cout<<"total number of customers = "<<total_account<<endl;
        cout<<"total balance = "<<total_balance<<endl;
    }
};

int customer::total_account = 0;
int customer::total_balance = 0;

int main ()
{
    customer A1("rohit", 15, 500);
    customer A2("mohit", 53, 100);
    customer A3("mohit", 100, 1000);
    
    // A1.display();
    // A2.display();
    // A3.display();
    // //customer::total_account = 10; //error if total_account is private
    // customer::accesStatic(); //can acces in private static member
    // A1.total();

    customer::accesStatic();
    A1.diposit(200);
    customer::accesStatic();
    A3.withdraw(500);
    customer::accesStatic();
    
}