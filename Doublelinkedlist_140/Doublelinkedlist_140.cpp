#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
		void addNote();
		bool search(int rollNo, Node * *previous, Node * *current);
		bool deleteNode(int rollNo);
		bool listEmpty();
		void traverse();
		void revtraverse();
		void hapus();
		void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
		START = NULL;
}

void DoubleLinkedList::addNote() {
	int nim;
	string nm;
	cout << "\Enter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();
	newNode->noMhs = nim;
	newNode->name = nm;

	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START;
		if (START != NULL)
			START->prev = newNode;
		newNode->prev = NULL;
		START = newNode;
		return;
	}
	Node* current = START;
	Node* previous = NULL;
	