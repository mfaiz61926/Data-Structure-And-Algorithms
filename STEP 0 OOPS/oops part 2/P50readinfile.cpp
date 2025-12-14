#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
    ifstream fin;
    fin.open("zoom.txt");

    //read karna
    char c;
    c=fin.get();
    while(!fin.eof()){
        cout<<c;
        //fin>>c;  //to inclue space use fin.get()
        c=fin.get();
    };
    fin.close(); 
}