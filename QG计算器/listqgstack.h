#pragma once
template<typename T>
class QGSTACK
{
private:
	struct Node
	{
		Node() :data(0), next(nullptr) {}
		Node(T data, Node* n = nullptr) :data(data), next(n) {}
		Node* next;
		T data;
	};
	Node* head;
	Node* end;
public:
	QGSTACK() {
		head = end = nullptr;
	}
	~QGSTACK() {
		clear();
	}
	void push(T data) {
		if (end != nullptr)
		{
			end->next = new Node(data);
			end = end->next;
		}
		else  //链表为空
			head = end = new Node(data);
	}
	void pop() {
		if (head == end) //只有一个节点或为空
		{
			delete head;
			head = end = nullptr;
			return;
		}
		Node* temp = head;
		for (; temp->next != end; temp = temp->next);
		temp->next = nullptr;
		delete end;
		end = temp;
	}
	T top() {
		if (head != nullptr)
			return end->data;
	}
	bool empty() {
		if (head == nullptr)
			return true;
		else
			return false;
	}
	void clear() {
		Node* p = nullptr;
		while (head)
		{
			p = head;
			head = head->next;
			delete p;
		}
		p = end = head = nullptr;
	}
	int size()
	{
		int size = 0;
		Node* temp = head;
		for (; temp != nullptr; temp = temp->next)
			size++;
		return size;
	}
};