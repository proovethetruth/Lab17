
#include "Queue.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Queue<int> myQueue(2);
    std::cout << myQueue;
    
    for (int i = 0; i < 1000; i++)
        myQueue.enqueue(i);

    myQueue.dequeue();
    std::cout << myQueue;
}