//write in file
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main ()
{
    // //file ko open krna
    // ofstream fout;
    // fout.open("zoom.txt");  //create file if not present
    // //write kar sakta hu
    // fout<<"Hello India";

    // fout.close(); //resources release kar paauon
    vector <int> arr(5);
    cout<<"enter the input: ";
    for(int i=0;i<arr.size();i++)
    cin>>arr[i];
    ofstream fout;
    fout.open("zero.txt");

    fout<<"Original data\n";
    for(int i=0;i<arr.size();i++){
        fout<<arr[i]<<" ";
    }
    fout<<"\nSorted data\n";
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        fout<<arr[i]<<" ";
    }
    fout.close();
    
}