#include <bits/stdc++.h>
using namespace std;

int main(){
    string st1,st2;
    ifstream mainfile;
    ofstream copyfile;
    string mainfilename, copyfilename;
    cout<<"Enter the name of the file from which you want to copy: "<<endl;
    cin>>mainfilename;
    cout<<"Enter the name of the fie in which you want to copy the s1: "<<endl;
    cin>>copyfilename;
    mainfile.open(mainfilename, ios::out);
    copyfile.open(copyfilename, ios::in);

    while (mainfile.eof()==0)
    {
        getline(mainfile,st1);
        copyfile<<st1<<"\n";
    }
    cout<<"End program";
return 0;
}
