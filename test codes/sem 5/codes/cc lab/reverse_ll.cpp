#include <bits/stdc++.h>
using namespace std;
struct LinkedList
{
	struct Node
	{
		int data;
		Node *next, *prev;
		Node(int d)
		{
			data = d;
			next = prev = NULL;
		}
	};
	Node* head = NULL;
	void reverse()
	{
		stack<int> st;
		Node* temp = head;
		while (temp != NULL)
		{
			st.push(temp->data);
			temp = temp->next;
		}
		temp = head;
		while (temp != NULL)
		{
			temp->data = st.top();
			st.pop();
			temp = temp->next;
		}
	}
	void Push(int new_data)
	{
		Node* new_node =
			new Node(new_data);

		new_node->prev = NULL;
		new_node->next = head;
		if (head != NULL)
		{
			head->prev = new_node;
		}
		head = new_node;
	}
	void printList(Node* node)
	{
		while (node)
		{
			cout << node->data << " ";
			node = node->next;
		}
	}
};

int main()
{
	LinkedList list;
	list.Push(2);
	list.Push(4);
	list.Push(8);
	list.Push(10);
	cout <<
	"Original linked list " << endl;
	list.printList(list.head);
	list.reverse();
	cout << endl;
	cout <<
	"The reversed Linked List is " << endl;
	list.printList(list.head);
}
