#include <iostream>
#include<vector>
using namespace std;
class animal{
    public:
    // virtual void speak(){ 
    //     cout<<"HU HU \n";
    // }

    virtual void speak()=0; //abstract class //can't create animal directly
};
class Dog:public animal{
    public:
    void speak(){
        cout<<"bark\n";
    }
    // void roti(){            //not access because it is not present in aniaml class we assign memory to animal calss
    //     cout<<"hello\n";
    // }
};

class cat:public animal{
    public:
    void speak(){
        cout<<"meow\n";
    }
};
int main ()
{
    // animal *p;
    // p = new Dog();
    // p->speak(); //without virtual - HU HU

    animal *p;
    vector<animal*>animals;
    animals.push_back(new Dog());
    animals.push_back(new cat());
    // animals.push_back(new animal());
    animals.push_back(new Dog());
    animals.push_back(new cat());

    for(int i=0;i<animals.size();i++){
        p = animals[i];
        p->speak();
    }
    
}