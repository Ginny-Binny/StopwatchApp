#include <bits/stdc++.h>
using namespace std;

int main(){
    // connecting our file with kout stream 
    // ofstream kout("fileIO1.txt");
    // cout<<"enter your name";
    // string name;
    // getline(cin,name);

    // // writng a string to the file
    // kout<<name;
    // kout.close();

    // ifstream kin;
    // kin.open("fileIO1.txt",ios::out);
    // string s;
    // // kin>>s;
    // getline(kin,s);
    // cout<<"The content of the file is \n"<<s;
    // kin.close();


    /*ofstream out;
    out.open("fileIO1.txt");
    out<<"This is me\n";
    out<<"This is me also\n";
    out<<"This is kshitij kumar\n";
    out.close();*/

    string st;
    ifstream in;
    in.open("fileIO1.txt");
    // in>>st;
    while (in.eof()==0){
        getline(in,st);
        cout<<st<<endl;
    }
    in.close();
return 0;
}