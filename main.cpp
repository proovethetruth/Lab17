
#include "Queue.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Queue<char> myQueue();
    myQueue.printQueue();

    int ct = 1;
    char ch;

    for(int i = 0; i < myQueue.size; i++)
    {
        std::cin >> ch;
        myQueue.enqueue(ch);
    }
    myQueue.printQueue();
}