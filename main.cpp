
#include "Queue.h"

int main()
{
	Queue<std::string> q;
	q.deque();

	q.enque("We");
	q.enque("can't");
	q.enque("expect");
	q.enque("God");
	q.enque("to");
	q.enque("do");
	q.enque("all");
	q.enque("the");
	q.enque("work");
	std::cout << q;
	std::cout << "\n Size: " << q.get_size();


	std::cout << "\n\n Deque() function: ";
	q.deque();
	q.deque();
	std::cout << q;
	std::cout << "\n Size: " << q.get_size();


	std::cout << "\n\n Copy constructor: ";
	Queue<std::string>z(q);
	std::cout << z;
	std::cout << "\n Size: " << q.get_size();

	std::cout << "\n\n Operator '=': ";


	q = z;
	std::cout << q;

	std::cout << "\n\n Clear() function: ";
	q.clear();
	std::cout << q;
	std::cout << "\n Size: " << q.get_size();

	std::cout << "\n\n Queue of points: ";
	Queue<Point>Maths;
	Point first(1, 2, 2);
	Point second(2, 1, 2);
	Maths.enque(first);
	Maths.enque(second);
	std::cout << Maths;
	std::cout << "\n Size: " << Maths.get_size();

	std::cout << "\n\n Deque() function: ";
	Maths.deque();
	std::cout << Maths;
	std::cout << "\n Size: " << Maths.get_size();

	std::cout << "\n\n Clear() function: ";
	Maths.clear();
	std::cout << Maths;
	std::cout << "\n Size: " << Maths.get_size();

	std::cout << "\n\n Z: ";
	std::cout << z;
	Queue<std::string> a;
	a = z.split();
	std::cout << z;
	std::cout << a;
}