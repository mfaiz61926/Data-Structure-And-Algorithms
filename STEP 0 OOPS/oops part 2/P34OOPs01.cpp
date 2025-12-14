#include <iostream>
using namespace std;
class Student{  //default private
    // public: //can be used outside the class
    string name;
    int age,roll_no;
    string grade;

    //function getter and setter
    public:
    void setname(string s){
        name = s;
    }
    void setage(int n){
        age = n;
    }
    void setroll(int n){
        roll_no = n;
    }
    void setgrade(string s){
        grade = s;
    }
    void getname(){
        cout<<name<<endl;
    }
    void getage(){
        cout<<age<<endl;
    }
    void getroll(){
        cout<<roll_no<<endl;
    }
    void getgrade(){
        cout<<grade<<endl;
    }
    int getroll_no(){
        return roll_no;
    }
    string getgrade_(int pin){
        if(pin==1234)
        return grade;

        return " ";
    }
};
int main ()
{
    // Student S1;
    // S1.name = "Arbaz";
    // S1.age = 20;
    // S1.roll_no = 30;
    // S1.grade = "A+";
    //cout<<S1.name;

    Student s2;
    s2.setname("Arbaz");
    s2.setage(20);
    s2.setroll(30);
    s2.setgrade("A+");

    s2.getname();
    s2.getage();
    s2.getroll();
    s2.getgrade();
    cout<<s2.getroll_no()<<endl;
    cout<<s2.getgrade_(1234)<<endl;
    
}