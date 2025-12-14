#include <iostream>
using namespace std;

class Engineer {
    protected:
    string specialisation;
    public:
    void work(){
        cout<<"I have specialisation in "<<specialisation<<endl;
    }
};

class Youtuber{
    protected:
    int subscriber;
    public:
    void contentcreater(){
        cout<<"I have a subscriber base of "<<subscriber<<endl;
    }
};

class Teacher:public Engineer, public Youtuber{
    string name;

    public:
    Teacher(string specialisation,int subscriber,string name){
        this->name = name;
        this->subscriber = subscriber;
        this->specialisation = specialisation;
    }

    void showcase(){
        cout<<"My name is "<<name<<endl;
        work();
        contentcreater();
    }
};
int main ()
{
    Teacher A1("CSE",120000,"Arbaz Ali");
    
    A1.showcase();
    
}