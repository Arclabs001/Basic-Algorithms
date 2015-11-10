/**
 * The Priority Queue Class in C++
 * Thanks to Introduction to Algorithms (CLRS) Chapter 6
 * Author: Zheng Chen / Arclabs001
 * Email : chenzheng17@yahoo.com
 * Copyright 2015 Xi'an University of Posts & Telecommunications. All rights reserved.
 */
#include "myheap.h"
#define INF 0xFFFFFFF
using namespace std;

template <class T>
class Priority_Queue: public Min_Heap<T>
{
public:
    Priority_Queue(): Min_Heap<T>() {}
    Priority_Queue(vector<T> _array):Min_Heap<T>(_array) {}
    Priority_Queue(T *_array, int array_size): Min_Heap<T>(_array, array_size) {}

    T& minimum() {return this->A[0];}
    T& pop()
    {
        --this->_size;
        T *tmp = new T;
        *tmp = this->A[0];
        swap(this->A[0],this->A[this->_size]);
        this->Min_Heapify(0);
        return *tmp;
    }

    bool decrease_key(int i, const T &key)
    {
        if(key > this->A[i])
        {
            return false;
        }
        this->A[i] = key;
        while(i>0 && this->A[i]<this->A[this->parent(i)])
        {
            swap(this->A[i],this->A[this->parent(i)]);
            i = this->parent(i);
        }
        return true;
    }

    void push(const T &key)
    {
        this->A.insert(this->A.end(),INF);
        this->_size++;

        int i = this->_size-1;
        while(i>0 && key < this->A[this->parent(i)])
        {
            this->A[i] = this->A[this->parent(i)];
            i = this->parent(i);
        }
        this->A[i] = key;
    }
};

int main()
{
    vector<int> A;
    A.clear();
    A.reserve(20);

    srand((unsigned int)time(0));
    for(int i=0; i<10; i++)
        A.insert(A.end(),rand()%1000);

    Priority_Queue<int> pq(A);
    pq.show();
    pq.push(rand()%1000);
    pq.show();
    pq.pop();
    pq.show();
    pq.decrease_key(5,0);
    pq.show();
    return 0;
}
