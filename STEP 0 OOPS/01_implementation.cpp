#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
        string name;
        int age,roll_number;
        string grade;
};

int main(){
    Student s1;
    s1.name="prateek";
    s1.age=23;
    s1.roll_number=34;
    s1.grade="A+";


    cout<<s1.age<<endl;
    cout<<s1.grade<<" "<<s1.roll_number<<endl;
}