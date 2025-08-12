#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
        string name;
        int age,roll_number;
        string grade;
        //FUNCTIONS GETTERS AND SETTERS

        //setters
        void setName(string s){
            if(s==""){
                cout<<"invalid name"<<endl;
                return;
            }
            name=s;
        }
        void setAge(int a){
            
            age=a;
        }
        void setRollNumber(int r){
            roll_number=r;
        }
        void setGrade(string s){
            grade=s;
        }
         //getter
         void getName(){
            cout<<name<<endl;
         }
         int getGrade(int pin){
            if(pin==1234){
                cout<<grade<<endl;
            }
            else{
                cout<<"incorrect pin"<<endl;;
            }
         }
};

int main(){
    Student s1;
    s1.setName("umair");
    s1.setAge(24);
    s1.setGrade("A+");
    s1.setRollNumber(34);
    s1.getName();


    // cout<<s1.age<<endl;
    // cout<<s1.grade<<" "<<s1.roll_number<<endl;

    s1.getGrade(1234);
}