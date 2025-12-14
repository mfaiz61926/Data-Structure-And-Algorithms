#include <iostream>
#include<exception>
using namespace std;
int main ()
{
    int a,b;
    cin>>a>>b;
    try {
        if(b==0)
        throw"divide by 0 is not possible\n";

        int c = a/b;
        cout<<c<<endl;
    }
    catch(const char *e){
        cout<<"Exception Occured: "<<e<<endl;
    }

    
}