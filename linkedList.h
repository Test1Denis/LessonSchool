#ifndef _linked_list_h_
#define _linked_list_h_

struct Data {
	int val;
	Data() : val(0) {}
	Data(int newVal) : val(newVal) {}
};

struct Node {
	Node* next;
	struct Data d;
	Node() {
		next = nullptr;
	}
	Node(const struct Data& temp) : Node() {
		d = temp;
	}
	~Node() {
		if (next != nullptr) {
			delete next;
			next = nullptr;
		}
	}
};

class LinkedList {
	private :
		Node* head;
	public :
		LinkedList();
		~LinkedList();
		void push_back(const struct Data&);
		Data pop_back();

};

#endif

