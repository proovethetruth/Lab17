
#include "Queue.h"

int main()
{
	Queue<std::string> q;
	q.enque("I");
	q.enque("don't");
	q.enque("enjoy");
	q.enque("killing.");
	q.enque("But");
	q.enque("when");
	q.enque("done");
	q.enque("rightously,");
	q.enque("its");
	q.enque("just");
	q.enque("a");
	q.enque("chore,");
	q.enque("like");
	q.enque("everything");
	q.enque("else.");

	std::cout << q;
	std::cout << q.get_size();

	q.deque();
	q.deque();
	std::cout << q;

	std::cout << q.get_size();

	q.clear();
	std::cout << q;
}