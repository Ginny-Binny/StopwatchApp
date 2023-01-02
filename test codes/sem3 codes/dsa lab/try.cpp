#include<iostream>
using namespace std;

#define endl "\n"
int positon_not_found;// global variable to store the position of the element so that to insert the element in the array no matter same element exists or not
void printA(int*arr,int size){
cout<<"printing the array"<<endl;
for(int i=0;i<size;i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;
}
int B_S(int*arr,int size,int element){
    int m,l,h;
    l=0;
    h=size-1;

    while(l<=h){
        m=(l+h)/2;
        if(arr[m]==element){
            positon_not_found=m;
            return m;
        }
            else if(arr[m]<element){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        positon_not_found=m+1;
        return -1;
    }

void delete_element(int*arr,int size,int element){
       int in=B_S(arr,size,element);
       if (in==-1)
       {
           cout<<"Element not found";
           return;
       }
       
}

void insert(int*arr,int size,int element){
    B_S(arr,size,element);
    int in = positon_not_found;
    for(int i=size-1;i>=in;i--){
        arr[i+1]=arr[i];
    }
   arr[in]=element;
}

int main()
{
int arr[15];
int size=10,E_D,E_in;
cout<<"Enter 5 elments in the array"<<endl;
for (int i=0;i<5;i++){
    cin>>arr[i];
}
printA(arr,size);
cout<<"Enter the element you want to delete ";
cin>>E_D;
delete_element(arr,size,E_D);
size-=1;
printA(arr,size);
cout<<"Enter the element you want to insert ";
cin>>insert;
insert(arr,size,insert);
size+=1;

printA(arr,size);
return 0;

}