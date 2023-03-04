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
		head = new Node(newData);;;;;;	//create first node
		return;
	}

	Node* temp = head;
	while(temp->next != nullptr) {
		temp = temp->next;
	}

	temp->next = new Node(newData);
}
