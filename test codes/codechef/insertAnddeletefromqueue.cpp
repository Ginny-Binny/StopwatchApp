#include<iostream>
using namespace std;
int q[100], n=100 , front =-1, rear = -1;

void Insert()
{
    int val;
    if(rear==n-1)
    cout<<"Queue is in overflow condition"<<endl;
    else{
        if(front==-1)
        front=0;
        cout<<"Insert the element"<<endl;
        cin>>val;
        rear++;
        q[rear]=val;
    }
}
void Delete()
{
    if(front == -1 || front> rear)
    {
        cout<<"Queue is in underflow condition";
        return;
    }
    else{
        cout<<"Enter the element to delete from the queue"<<q[front]<<endl;
        front ++;
    }
}

void display()
{
    if(front ==-1)
    cout<<"Queue is empty "<<endl;
    else{
        cout<<"Queue elements are :";
        for(int i = front ; i<=rear; i++)
        cout<<q[i]<<" ";
        cout<<endl;
    }
}
int main()
{
    int ch;
    cout<<"1. Insertion"<<endl;
    cout<<"2. Deletion"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Exit"<<endl;
    do{
        cout<<"Enter your desired choice : "<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1: Insert();
            break;
            case 2: Delete();
            break;
            case 3: display();
            break;
            case 4: cout<<"Exit"<<endl;
            break;
            default: cout<<"Invalid choice"<<endl;
        }
    }
    while(ch!=4);
    return 0;
}