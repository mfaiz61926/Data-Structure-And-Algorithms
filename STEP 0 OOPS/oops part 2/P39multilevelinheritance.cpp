#include <iostream>
using namespace std;

class person {
    protected:
    string name;
    public:
    void Name(){
        cout<<"My name is "<<name<<endl;
    }
};

class Employee:public person{
    protected:
    int salary;
    public:
    void Salary(){
        cout<<"My monthly salary is "<<salary<<endl;
    }
};

class Manager:public Employee{
    string department;

    public:
    Manager(string name,int salary,string department){
        this->name = name;
        this->salary = salary;
        this->department = department;
    }

    void work(){
        cout<<"I am leading the department of "<<department<<endl;
    }
};
int main ()
{
    Manager A1("Arbaz",120000,"CSE");
    A1.Name();
    A1.Salary();
    A1.work();
    
}