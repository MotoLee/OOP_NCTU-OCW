// ex3-1.cpp
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

void InsertNode(int data);
bool DeleteNode(int data);
void Display();

//global variable root is used to record the head of link list
Node* root = NULL;

int main() {
	size_t i = 0;
	while (1) {
		cout << "Please select an option:" << endl
		     << "1.Insert a node" << endl
		     << "2.Delete a node" << endl
		     << "3.Display the list" << endl
		     << "4.End" << endl;
		cin >> i;
		int data;
		switch(i) {
			case 1:
				cout << "Please enter the number:" << endl;
				cin >> data;
				InsertNode(data);
				break;
			case 2:
				cout << "Please enter the number:" << endl;
				cin >> data;
				if ( !DeleteNode(data) )
					cout << "Failed to delete node " << data << endl;
				break;
			case 3:
				Display();
				break;
			case 4:
				return 0;
			default:
				break;
		}
	}
}

void InsertNode(int data) {
	if(root==NULL) {
		root = new Node();
		root->data = data;
		root->next = NULL;
	} else {
		Node* now=root;
		while(now->next!=NULL) {
			now = now->next;
		}
		now->next = new Node();
		now = now->next;
		now->data = data;
		now->next = NULL;
	}
}

bool DeleteNode(int data) {

	// count the length of linked list
	Node* now = root;
	int length=0;
	while(now!=NULL) {
		length++;
		now = now->next;
	}
//	cout<<"length = "<<length<<endl;

	// if length = 0 (root is NULL)
	if(length==0) {
		cout<<"ERROR: root is null."<<endl;
		return 0;
	}
	// if length = 1 (only one element)
	else if(length==1) {
		if(data==1) {
			delete root;
			root = NULL;
		} else {
			cout<<"ERROR: out of range..."<<endl;
			return 0;
		}
	} else {
		// delete # is 1 (delete root)
		if(data==1) {
			now = root;
			root = root->next;
			delete now;
		}
		// delete # should not exceed length
		else if((data<=length) && (data>=2)) {
			// find the element before the delete element
			now = root;
			for(int i=2; i<data; i++) {
				now = now->next;
			}
			// find the delete element
			Node* del = now->next;
			// re-link
			now->next = del->next;
			delete del;
		}
		// delete # exceed length
		else {
			cout<<"ERROR: out of range..."<<endl;
			return 0;
		}
	}

	return 1;
}

void Display() {

	if(root==NULL) {
		cout<<"root is NULL!"<<endl;
	} else {
		Node* now = root;
		cout<<now->data;
		while(now->next!=NULL) {
			cout<<" -> ";
			now = now->next;
			cout<<now->data;

		}
		cout<<endl;
	}
}
