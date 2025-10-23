#include "MyQueue.h"
#include <stdexcept>
using namespace std;

template <typename T>
Queue<T>::Queue(int capacity)
{
    this->capacity = capacity;
    size = 0;
    front = 0;
    rear = -1;
    this->data = new T[capacity];
}

template <typename T>
Queue<T>::~Queue()
{
}
template <typename T>
bool Queue<T>::isFull()
{
    return size == capacity;
}
template<typename T>
bool Queue<T>::isEmpty()
{
    return size == 0;
}
template <typename T>
void Queue<T>::enqueue(const T &value)
{
    if(isFull()){
        cout<<"Queue Full"<<endl;
        return;
    }
    this->rear = (rear + 1) % capacity;
    this->data[rear] = value;
    this->size++;
}
template <typename T>
void Queue<T>::dequeue()
{
    if(isEmpty()){
        cout<<"Queue Empty"<<endl;
        return;
    }
    this->front = (front + 1) % capacity;
    this->size--;
}
template <typename T>
T& Queue<T>::getFront()
{
    if(isEmpty()){
        throw runtime_error("Queue is empty!");
    }
    return this->data[front];
}
template <typename T>
int Queue<T>::getSize() 
{
    return size;
}