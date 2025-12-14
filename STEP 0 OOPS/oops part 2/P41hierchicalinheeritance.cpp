#include <iostream>
using namespace std;

class human {
    protected:
    string name;
    int age;
    public:
    human(){

    }
    human(string name,int age){
        this->name = name;
        this->age = age;
    }
    void introduce(){
        cout<<name<<endl<<age<<endl;
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
    void display(){
        cout<<name<<endl<<age<<endl<<roll_no<<endl<<fees<<endl;
    }
};
class Teacher:public human{
    int salary;

    public:
    Teacher(string name,int age,int salary){
        this->name = name;
        this->age = age;
        this->salary = salary;
    }
    void display(){
        cout<<name<<endl<<age<<endl<<salary<<endl;
    }
};
int main ()
{
    human C1("arbaaz",21);
    Student A1("Arbaz",20,30,120000);
    A1.introduce();
    A1.display();
    Teacher B1("Arbaz Ali", 30, 100000);
    B1.introduce();
    B1.display();
    
    C1.introduce();
    
}