#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class EmptyError {
public:
	EmptyError() {};
};

class Point {
private:
	int x;
	int y;
	int z;

public:
	Point() {
		x = 0;
		y = 0;
		z = 0;
	}
	Point(int a, int b, int c) {
		x = a;
		y = b;
		z = c;
	}
	friend std::ostream& operator<<(std::ostream& out, Point& p) {
		out << p.x << p.y << p.z;
		return out;
	}
};

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

	Queue(const Queue<T>& q) {
		size = 0;
		start = end = NULL;

		node<T>* tmp = q.start;
		node<T>* tmp2 = start;

		start = end = new node<T>(tmp->data);
		size++;

		while (tmp != q.end) {
			tmp = tmp->next;
			tmp2 = new node<T>(tmp->data);
			end->next = tmp2;
			end = tmp2;
			size++;
		}
		end->next = NULL;
	}

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
		if (size == 0) {
			try {
				EmptyError a;
				throw(a);
			}
			catch (EmptyError) {
				std::cout << "\n Queue is empty!";
			}
		}
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

	Queue<T>& operator=(const Queue<T> &q) {
		if (this == &q)
			return *this;

		(*this).clear();

		node<T>* tmp = q.start;
		node<T>* tmp2 = start;

		start = end = new node<T>(tmp->data);
		size++;

		while (tmp != q.end) {
			tmp = tmp->next;
			tmp2 = new node<T>(tmp->data);
			end->next = tmp2;
			end = tmp2;
			size++;
		}
		end->next = NULL;
		return *this;
	}

	Queue<T> split() {
		Queue<T> splitted;
		node<T>* tmp = start;
		int middle = size / 2;

		for (int i = 0; i < middle + 1; i++) {
			splitted.enque(tmp->data);
			(*this).deque();
			tmp = start;
		}
		return splitted;
	}
};

#endif
