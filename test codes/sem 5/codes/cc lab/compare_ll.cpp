#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	string s;
	Node* next;
	Node(string s)
	{
		this->s = s;
		next = NULL;
	}
};


bool compare(Node* list1, Node* list2)
{

	string s1, s2;

	while (list1 != NULL) {
		s1 += list1->s;
		list1 = list1->next;
	}
	while (list2 != NULL) {
		s2 += list2->s;
		list2 = list2->next;
	}
	return s1 == s2;
}

int main()
{
	Node* n1 = new Node("w");
	Node* head1 = n1;
	Node* n2 = new Node("");
	Node* n3 = new Node("orl");
	Node* n4 = new Node("d");
	Node* n5 = new Node("worl");
	Node* head2 = n5;
	Node* n6 = new Node("");
	Node* n7 = new Node("");
	Node* n8 = new Node("nd");
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;

	if (compare(head1, head2) == true)
		cout << "true";
	else
		cout << "false";
	return 0;
}
