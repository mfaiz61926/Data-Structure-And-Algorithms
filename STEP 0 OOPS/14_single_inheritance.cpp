#include <iostream>
using namespace std;

class human {
    protected:
    string name;
    int age;
    public:
    void work(){
        cout<<"I am working here. ";
    }
};

class Student:public human{
    int roll_no;
    int fees;

    public:
    Student(string name,int age,int roll_no,int fees){
        this->name = name;
        this->age = age;
        this->roll_no = roll_no;
        this->fees = fees;
    }
};
int main ()
{
    Student A1("Arbaz",20,30,120000);
    A1.work();
    
}