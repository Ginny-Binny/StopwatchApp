#include <iostream>
using namespace std;
struct node {
 int data;
 struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;
void Insert() {
 int val;
 cout<<"Enter the element which you want to insert in the queue : "<<endl;
 cin>>val;
 if (rear == NULL) {
 rear = (struct node *)malloc(sizeof(struct node));
 rear->next = NULL;
 rear->data = val;
 front = rear;
 } else {
 temp=(struct node *)malloc(sizeof(struct node));
 rear->next = temp;
 temp->data = val;
 temp->next = NULL;
 rear = temp;
 }
}
void Delete() {
 temp = front;
 if (front == NULL) {
 cout<<"Queue is empty"<<endl;
 return;
 }
 else
 if (temp->next != NULL) {
 temp = temp->next;
 cout<<"Deleted element is : "<<front->data<<endl;
 free(front);
 front = temp;
 } else {
 cout<<"Deleted element is : "<<front->data<<endl;
 free(front);
 front = NULL;
 rear = NULL;
 }
}
void Display() {
 temp = front;
 if ((front == NULL) && (rear == NULL)) {
 cout<<"Queue is empty "<<endl;
 return;
 }
 cout<<"Elements of the queue are : ";
 while (temp != NULL) {
 cout<<temp->data<<" ";
 temp = temp->next;
 }
 cout<<endl;
}
int main() {
 int ch;
 cout<<"1) Insertion"<<endl;
 cout<<"2) Deletion"<<endl;
 cout<<"3) Peeking"<<endl;
 cout<<"4) Exit"<<endl;
 do {
 cout<<"\nEnter your choice: "<<endl;
 cin>>ch;
 switch (ch) {
 case 1: Insert();
 break;
 case 2: Delete();
 break;
 case 3: Display();
 break;
 case 4: cout<<"Tq"<<endl;
 break;
 default: cout<<"Choice invalid "<<endl;
 }
 } while(ch!=4);
 return 0;
}