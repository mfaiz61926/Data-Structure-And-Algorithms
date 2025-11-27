#include <iostream>
using namespace std;
class human 
{
    string religion,color;
    protected:
    string name;
    int age;
};

class student: protected human
{
    int roll_no,fees;
    public:
    void fun(string a,int b, int c){
        name = a;
        age = b;
        roll_no = c;
    }

    void display(){
        cout<<name<<" "<<age<<" "<<roll_no<<endl;
    }
};
int main ()
{
    student A1;
    A1.fun("arbaz",20,30);
    A1.display();
}