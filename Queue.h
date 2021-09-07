#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Point {
public:
	int x;
	int y;
	int z;
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
