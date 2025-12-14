#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main (){
    ofstream fout;
    fout.open("Z1.txt");
    fout<<"Hello India\n";
    fout<<"Hello Rohit\n";
    fout<<"Hello Bhai\n";
    fout.close();

    ifstream f;
    f.open("Z1.txt");

    string line;

    while(getline(f,line)){
        cout<<line<<endl;
    }
    f.close();

}