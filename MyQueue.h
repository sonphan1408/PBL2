#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Queue
{
private:
    int capacity;
    int size;
    int front;
    int rear;
    T* data;
public:
    Queue(){};
    Queue(int capacity);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(const T &value);
    void dequeue();
    T &getFront();
    int getSize();

};



