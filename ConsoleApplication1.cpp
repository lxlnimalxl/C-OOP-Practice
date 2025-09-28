#include <iostream>
using namespace std;


class Node {
public:
	int data;
	Node* next;

	Node(int);

};


Node::Node(int ele) {
	data = ele;
	next = nullptr;
}

class List {
private:
	Node* head = nullptr;
public:
	void append(int);
	int length();
	void InsertSorted(int ele);
	void print();
};

void List::append(int ele) {
	if (!head) {
		head = new Node(ele);
	}
	else {
		Node* ptr = head;
		while (ptr->next) {
			ptr = ptr->next;
		}
		ptr->next = new Node(ele);
	}
}

int List::length() {
	int count = 0;
	Node* ptr = head;
	while (ptr) {
		count++;
		ptr = ptr->next;
	}
	return count;
}


void List::InsertSorted(int ele) {
	// اگر لیست خالی باشد
	if (!head)
	{
		head = new Node(ele);
		return;
	}

	// اگر بخواهیم در ابتدا وارد کنیم
	if (ele <= head->data)
	{
		Node* newNode = new Node(ele);
		newNode->next = head;
		head = newNode;
		return;
	}
	Node* ptr = head;
	Node* pre = nullptr;
	while (ptr && ptr->data < ele) {
		pre = ptr;
		ptr = ptr->next;
	}
	Node* newNode = new Node(ele);
	newNode -> next = ptr;
	pre->next = newNode;
}


void List::print() {
	if (!head) {
		cout << "List is empty." << endl;
		return;
	}

	Node* ptr = head;
	cout << "List: ";
	while (ptr) {
		cout << ptr->data;
		if (ptr->next) {
			cout << " -> ";
		}
		ptr = ptr->next;
	}
	cout << endl;
}



int main()
{
	List myList;

	myList.InsertSorted(30);
	myList.InsertSorted(10);
	myList.InsertSorted(20);
	myList.InsertSorted(5);
	myList.InsertSorted(25);

	myList.print();         // خروجی: List: 5 -> 10 -> 20 -> 25 -> 30
	cout << "Length: " << myList.length() << endl; // خروجی: Length: 5
	return 0;
}
