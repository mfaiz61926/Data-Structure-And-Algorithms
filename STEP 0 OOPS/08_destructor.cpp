#include <bits/stdc++.h>
using namespace std;

class Customer
{
    string name;
    int *data;

    public:

    // Customer()    01
    // {                             THIS IS FOR WORKING OF CONSTRUCTOR AND DESTRUCTOR
    //     name="Faiz";
    //     data=new int;
    //     *data = 10;
    //     cout<<"constructor is called"<<endl;
    // }

    // //Destructor
    // ~Customer(){
    //     delete data;
    //     cout<<"Destructor is called"<<endl;
    // }

    //default constructor
    Customer(){
        name="4";
        cout<<"Constructor called is:"<<name<<endl;
    }
    //THIS FOR IN WHAT ORDER CONSTRUCTOR AND DESTRUCTORS IS CALLED.
    Customer(string name){
        this->name=name;
        cout<<"Constructor called is:"<<name<<endl;
    }
    ~Customer(){
        cout<<"Destructor called is:"<<name<<endl;
    }

};

int main() {
    // Customer c;    01
    Customer a1("1"),a2("2"),a3("3");

    Customer *a4 = new Customer; //it will not be deleted by destructor in code ,for deleting dynmaic one we write delete as below
    delete a4;

    

}