/*
Homework 1 - EndSert Method
Rojitha Goonesekere
In this program we will create a list using fuctions that will
place an integer at the front of the list and at the back
1063 Data Structures
Spring 2017
2/9/2017
*/

#include <iostream>

struct Node {
	int Data;
	Node *Next;
};

using namespace std;

class List {
private:
	Node *Head;
	Node *Tail;
public:
	List() {
		Head = NULL;
		Tail = NULL;
	}
	
	/*
	Function name:FrontSert
	This will use a Tail pointer to link nodes to the end of a list
	Parameters:
	integer y - will determine the integer that goes into the node
	Returns: void
	*/
	void FrontSert(int y) {
		Node *Temp = new Node;
		Temp->Data = y;
		Temp->Next = NULL;

		if (Head) {
			Temp->Next = Head;
		}
		Head = Temp;
		if (!Tail) {
			Tail = Head;
		}
		
	}

	/*
	Function name:EndSert
	Uses a Tail pointer to link nodes to the end of the list
	Parameters:
	integer x - will determine the integer that goes into the node
	Returns: void
	*/

	void EndSert(int x) {
		Node *Temp = new Node;
		Temp->Data = x;
		Temp->Next = NULL;

		if (Tail != NULL){
			if (Temp->Next == NULL) {
				Tail->Next = Temp;
				Tail = Tail->Next;
			}
		}
		else {
			Head = Temp;
		}

	}
	

		

	void PrintList() {
		if (!Head) {
			cout << "Empty" << endl;
			return;
		}
		else {
			Node *Temp = Head;
			while (Temp != NULL) {
				cout << Temp->Data << "->";
				Temp = Temp->Next;
			}
		}
		
	}

};


int main() {
	List Lst;
	Lst.EndSert(32);
	Lst.PrintList();
	cout << endl;

	Lst.FrontSert(12);
	Lst.PrintList();
	cout << endl;

	Lst.FrontSert(43);
	Lst.PrintList();
	cout << endl;

	Lst.FrontSert(15);
	Lst.PrintList();
	cout << endl;

	Lst.FrontSert(32);
	Lst.PrintList();
	cout << endl;

	Lst.EndSert(52);
	Lst.PrintList();
	cout << endl;

	Lst.EndSert(89);
	Lst.PrintList();
	cout << endl;

	Lst.FrontSert(90);
	Lst.PrintList();
	cout << endl;
	return 0;
}
