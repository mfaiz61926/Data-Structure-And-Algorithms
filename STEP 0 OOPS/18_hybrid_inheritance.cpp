#include <iostream>
using namespace std;
class student{
    public:
    void print(){
        cout<<"I am a student "<<endl;
    }
};
class male{
    public:
    void maleprint(){
        cout<<"I am male"<<endl;
    }
};
class female{
    public:
    void femaleprint(){
        cout<<"I am female"<<endl;
    }
};
class boy:public student,public male{
    public:
    void boyprint(){
        cout<<"I am a boy "<<endl;
    }
};
class girl:public student,public female{
    public:
    void girlprint(){
        cout<<"I am a Girl "<<endl;
    }
};

int main ()
{
    girl G1;
    G1.femaleprint();
    G1.girlprint();
    G1.print();
    boy B1;
    B1.maleprint();
    B1.boyprint();
    B1.print();

    
}