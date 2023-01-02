#include <bits/stdc++.h>
using namespace std;

/*int main()
{
    int x = 1;
    cout << "Before try" << endl;
    try{
        cout << "Iside try" << endl;
        if (x < 0)
        {
            throw x;
            cout<<"After throw";
        }
    }
    catch (int x){
        cout<<"Exception caught"<<endl;
    }
    cout<<"After catch"<<endl;
return 0;
}*/

// catch all
/*int main()
{
    try
    {
        throw 10;
    }
    catch(char *exp)
    {
        cout<<"Caught";
    }
    catch(...){
        cout<<"Default caught";
    }
    return 0;
}*/

// nested try
/*int main()
{
    try{
        try{
            throw 10;
        }
        catch(int n){
            cout<<"Hande partially";
            throw; 
        }
        }
        catch(int n){
            cout<<"Handle remaining";
    }
return 0;
}*/

