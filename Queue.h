#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template<class T>
class Queue
{
private:
    T* queuePtr;
    int begin, end;
    int size;
    int capacity;
public:
    Queue();
    Queue(const Queue<T>&);
    ~Queue();
    void enqueue(const T&);
    T dequeue();
    void printQueue();
};

template<class T>
Queue<T>::Queue() {
    size = 0;
    capacity = 2;
    begin = 0, end = 0;
    queuePtr = new T[capacity];
}

template<class T>
Queue<T>::Queue(const Queue& other) {
    for (int i = 0; i < size; i++)
        queuePtr[i] = other.queuePtr[i];
}

template<class T>
Queue<T>::~Queue()
{
    delete[] queuePtr;
}

template<class T>
void Queue<T>::enqueue(const T& newElem)
{
    T *tmp;
    if (size == capacity) {
        capacity *= 2;
        tmp = (T*)calloc(capacity, capacity * sizeof(T));
        if (!tmp)
        {
            printf("\n\a ERROR: Can't allocate enough memory");
            return;
        }
        for (int i = 0; i < size; i++)
        {
            tmp[i] = queuePtr[i];
        }
        delete[] queuePtr;
        queuePtr = tmp;
    }
    queuePtr[end++] = newElem;
    size++;

    // проверка кругового заполнения очереди
    if (end > size)
        end -= size + 1; // возвращаем end на начало очереди
}

template<class T>
T Queue<T>::dequeue()
{
    if (size == 0)
        return;

    T returnValue = queuePtr[begin++];
    size--;

    // проверка кругового заполнения очереди
    if (begin > size)
        begin -= size + 1; // возвращаем begin на начало очереди

    return returnValue;
}

template<class T>
void Queue<T>::printQueue()
{
    std::cout << "\n Очередь";

    if (end == 0 && begin == 0)
        std::cout << " пустая.";
    else
    {
        std::cout << ":\n\t";
        for (int ix = end; ix >= begin; ix--)
            std::cout << queuePtr[ix] << " ";
        std::cout << std::endl;
    }
}

#endif
