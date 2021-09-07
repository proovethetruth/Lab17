#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <class T>
class node {
public:
	T data;
	node<T>* next;
	node(T x)
	{
		data = x;
		next = NULL;
	}
};

template <class T>
class Queue {
	node<T>* start;
	node<T>* end;
	int size;

public:
	Queue() {
		size = 0;
		start = end = NULL;
	}

	//Queue(const Queue<T>& q) {
	//	node<T>* tmp = 
	//	while (tmp != NULL) {
	//		end->next = temp;
	//		end = temp;
	//		size++;
	//	}
	//	end = new node<T>(q.end);
	//}

	int get_size() {
		return size;
	}

	void clear() {
		if (size == 0)
			std::cout << "\n Queue is empty. ";
		else {
			while (start != end) {
				node<T>* temp = start;
				start = start->next;
				delete temp;
			}
			delete start;
			start = end = NULL;
			size = 0;
		}
	}

	void enque(T newElem) {
		node<T>* tmp = new node<T>(newElem);
		if (size == 0) {
			start = end = tmp;
			size++;
		}
		else {
			end->next = tmp;
			end = tmp;
			size++;
		}
	}

	T front() {
		if (size == 0)
			return NULL;
		else
			return start->data;
	}

	void deque() {
		if (size == 0)
			std::cout << "Queue is Empty" << std::endl;
		else if (start == end)
		{
			delete start;
			start = end = NULL;
			size = 0;
		}
		else
		{
			node<T>* tmp = start;
			start = start->next;
			delete tmp;
			size--;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, Queue<T>& q) {
		node<T>* tmp = q.start;
		if (q.size == 0)
			out << "\n Queue is empty. ";
		else {
			out << "\n ";
			while (tmp != NULL) {
				out << tmp->data << " ";
				tmp = tmp->next;
			}
		}
		return out;
	}
};

#endif
