#include <iostream>
using namespace std;
class human{
    public:
    string name;
    void display(){
        cout<<"My name is "<<name<<endl;
    }
};

class Engineer:public virtual human {
    protected:
    string specialisation;
    public:
    void work(){
        cout<<"I have specialisation in "<<specialisation<<endl;
    }
};

class Youtuber: public virtual human{  //virtual is used to rsolve the pronlem of ambigous name,display fn in human class
    protected:                         //for better understanding, run code by removing virtual keyword
    int subscriber;
    public:
    void contentcreater(){
        cout<<"I have a subscriber base of "<<subscriber<<endl;
    }
};

class Teacher:public Engineer, public Youtuber{
    int salary;

    public:
    Teacher(string name,string specialisation,int subscriber,int salary){
        this->name = name;
        this->specialisation = specialisation;
        this->subscriber = subscriber;
        this->salary = salary;
    }

    void showcase(){
        cout<<"My name is "<<name<<endl;
        work();
        contentcreater();
    }
};
int main ()
{
    Teacher A1("Arbaz Ali","CSE",120000,200000);
    
    A1.showcase();
    
}