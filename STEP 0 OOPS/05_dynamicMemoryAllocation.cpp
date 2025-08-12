#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
        string name;
        int roll,age;
        string grade;
};

int main(){
    Student *s=new Student;  //DYNAMIC MEMORY ALLOCATION
    (*s).name="faiz";
    (*s).age=24;
    (*s).grade="A+";
    (*s).roll=67;

    cout<<s->age<<endl;
    cout<<s->name<<endl;
    cout<<s->roll<<endl;
    cout<<s->grade<<endl;
}