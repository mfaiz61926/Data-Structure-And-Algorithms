#include <bits/stdc++.h>
using namespace std;

class Student{
    
        string name;
        int acc_no;
        int balance;
        public:
         Student(){ //default constructor
            name="faiz";
            acc_no=1234;
            balance=3123;
         }
        // Student(string a,int b,int c){//parameterised constructor
        //     name=a;
        //     acc_no=b;
        //     balance=c;
        // }

        Student(string name,int acc_no){//constructor overloading
            this->name=name;
            this->acc_no=acc_no;
            balance=5050;
        }

        //inline constructor
        inline Student(string a,int b,int c):name(a),acc_no(b),balance(c){}

        //copy constructor
        Student(Student & B){
            name=B.name;
            acc_no=B.acc_no;
            balance=B.balance;
        }

        void display(){
            cout<<"name: "<<name<<endl<<"acc_no: "<<acc_no<<endl<<"balance: "<<balance<<endl;
        }


};

int main(){
    Student a;
    Student b("uamir",234,1111);
    Student c("arham",1010);
    // a.display();
    // b.display();
    // c.display();
    Student a3(b);
    a3.display();

    Student a5;
    a5=a3;
    a5.display();

}