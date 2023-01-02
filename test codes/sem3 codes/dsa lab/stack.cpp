#include <iostream>
using namespace std;

int top =-1, z[5];

void Push(int value) // push operation 
{
    if (top==4)
    {
        cout<<"\n Stack is overflow";

    }
    else{
        top++;
        z[top]=value;

    }
}

void Pop(){  // pop operation
    if(top ==-1)
    {
        cout<<"\n Stack is Empty or underflow";
    }
    else{
        top--;
    }
}
void Display()  // used to display the elements in the stack

{
    if (top== -1 ){
        cout<<" \n nothing to display";
    }
    else {
        cout<<"\n Array is :";
        for(int i=0; i<=top;i++)
        {
            cout<<"\t"<<z[i];
        }
    }
}

int main() // main function
{
    int value , choice;
    do{
        cout<<"\n 1. push \n 2. pop \n 3. Display \n 4. Exit \n Input choice"; // taking choices from the user 
        cin>> choice;
        system("cls");
        if(choice ==1){
            cout<<"\n Enter value";
            cin>>value;
            Push(value);
        }
        if(choice ==2){
            Pop();

        }
        if(choice ==3)
        {
            Display();
        }

    }
    while(choice != 4);
    cout<<" \n Exit";
    return 0;
}