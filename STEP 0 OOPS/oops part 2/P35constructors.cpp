#include <iostream>
using namespace std;
class customer 
{
    
    string name;
    int account_no;
    int balance;
    public:
    customer(){
        cout<<"default contructor: "<<endl;
        name = "Rohit";
        account_no = 3248;
        balance = 40101;
    }
    inline customer(string a,int b,int c):name(a),account_no(b),balance(c){}
    // customer(string name , int account_no, int balance){
    //     cout<<"parameterized constructor: "<<endl;
    //     this->name = name;
    //     this->account_no = account_no;
    //     this->balance = balance;
    // }
    //contructor overloading
    customer(string name , int account_no){
        this->name = name;
        this->account_no = account_no;
        balance = 350;
    }
    customer (customer &B)   //copy constructor no need to create it is by default 
    {
        name = B.name;
        account_no = B.account_no;
        balance = B.balance;
    }
    void display(){
        cout<<name<<" "<<account_no<<" "<<balance<<endl;
    }
    ~customer(){ //call at the last 
        cout<<"destructor is called: "<<name<<endl;  //A1 will be at last A5 will be first
    }

};
int main ()
{
    customer A1;   //default constructor
    A1.display();
    customer A2("arbaz", 4300, 1000); //parametrized constructor
    A2.display();
    customer A3("varis",424);   //constructor overloading same name different function with parameter
    A3.display();
    customer A4(A3); //copy constructor
    A4.display();
    //or
    customer A5;
    A5 = A3;
    A5.display();
}