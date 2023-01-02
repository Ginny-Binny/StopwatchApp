#include <bits/stdc++.h>
using namespace std;

int main(){
    // file input output i c++
    // method to write in the file
    // string st = "hello world we are trying to learn c++ and this is file input output";
    // ofstream out("fileinputoutput.txt");
    // out<<st;

    // opening fie using constructor and reading it
    string st2;
    ifstream in("fileinputoutput.txt");
    getline(in,st2);
    // in>>st2;
    cout<<st2; 
return 0;
} 