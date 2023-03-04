#include "linkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	if (head != nullptr) {
		delete head;
	}
}

void LinkedList::push_back(const struct Data& newData) {
	if (head == nullptr) {
		head = new Node(newData);	//create first node
		return;
	}

	Node* temp = head;
	while(temp->next != nullptr) {
		temp = temp->next;
	}

	temp->next = new Node(newData);
}

Data LinkedList::pop_back() {
	Node* temp = head;

	if (head == nullptr) {
		return Data(-1);
	}
	
	if (temp->next == nullptr) {
		Data d = temp->d;
		delete head;
		head = nullptr;
		return d;
	}

	while(temp->next->next != nullptr) {
		temp = temp->next;
	}

	Data d = temp->next->d;
	delete temp->next;
	temp->next = nullptr;
	return d;

}
