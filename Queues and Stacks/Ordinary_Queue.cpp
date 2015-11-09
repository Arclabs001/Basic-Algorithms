#include <iostream>
using namespace std;
/**
 * The queue data structure's implementation in C++
 * Time Cost : isEmpty / enQueue / deQueue / getHead : O(1)
 * 			   display :  O(n)
 * Thanks to Introduction to Algorithms (CLRS) Chapter 10
 * Author: Zheng Chen / Arclabs001
 * Email : chenzheng17@yahoo.com
 * Copyright 2015 Xi'an University of Posts & Telecommunications. All rights reserved.
 */
template<class T>
class myQueue
{
private:
    int head, tail;
    int size;
    T * data;

public:
    myQueue() : head(0), tail(0), size(100) {data = new T[100];}
    myQueue(int _head, int _tail, int _size, T* _data) :
        head(_head), tail(_tail), size(_size)
    {
        data = new T[size];
        for(int i = _head; i<_tail; i++)
        {
            data[i] = _data[i];
        }
    }
    myQueue(myQueue & _queue)
    {
        head = _queue.head;
        tail = _queue.tail;
        size = _queue.size;
        data = new T[size];
        for(int i=head; i<tail; i++)
        {
            data[i] = _queue.data[i];
        }
    }

    bool isEmpty()	//To evaluate if the queue is empty
    {
        return tail == head;
    }
    bool isFull()	//To evaluate if the queue is full
    {
        return head==0 && tail==size;
    }

    void enQueue(T _data)	//Enter the queue as the tail element
    {
        if(tail==size && head < size/2)		// if the queue is full, open up a new space
        {
            T* tmp = new T[2*size];
            size *= 2;
            int n = tail - head;
            for(int i=0; i<n; i++)
            {
                tmp[i] = data[head + i];
            }
            data = tmp;
            head = 0; tail = n;
        }
        else if(tail==size && head >= size/2)
        {
            int n = tail-head;
            for(int i=0; i<n; i++)
            {
                data[i] = data[head + i];
            }
            head = 0; tail = n;
        }

        data[tail++] = _data;
    }
    T& deQueue()	//Delete the head element, and return that value.
    {
        if(!isEmpty())
        {
            T * tmp = new T;
            *tmp = data[head++];
            return *tmp;
        }
        else{		//If the queue is empty, return -1
            cout<<"The Queue is empty!"<<endl;
            T *i;
            *i = -1;
            return *i;
        }
    }
    T& getHead()
    {
        return data[head];
    }

    void display()	//Show all the elements from head to tail in the queue
    {
        for(int i=head; i<tail; i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl<<"Head : "<<head<<endl;
        cout<<"Tail : "<<tail<<endl;
        cout<<"Size : "<<size<<endl;
    }
};

int main()	//To test the queue
{
    myQueue<int> Queue;
    for(int i=0; i<100; i++)
    {
        Queue.enQueue(i+1);
    }
    Queue.display();

    Queue.enQueue(101);
    Queue.display();

    Queue.deQueue();
    Queue.display();

    Queue.deQueue();
    Queue.display();
    return 0;
}
