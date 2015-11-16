/**
 * The Minimum Heap Class and Heap Sort in C++
 * Thanks to Introduction to Algorithms (CLRS) Chapter 6
 * Thanks to Tsinghua MOOC of "Data Structure and Algorithms"
 * Author: Zheng Chen / Arclabs001
 * Email : chenzheng17@yahoo.com
 * Copyright 2015 Xi'an University of Posts & Telecommunications. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define INF 0xFFFFFFF
using namespace std;

template<class T>
class Min_Heap
{
private:
    vector<T> A;
    int _size;   //The size of heap

    int parent(int i) { return (i-1)/2; }  //Get the index of ith parent
    int left(int i)   { return 2*i+1; }    //Get the index of ith left child
    int right(int i)  { return 2*i+2; }    //Get the index of ith right child

public:
    //Here are three different constructor
    Min_Heap() {A.clear(); A.reserve(100); _size=0;}
    Min_Heap(vector<T> _array)
    {
        _size = 0;
        A.clear(); A.reserve(_array.size());
        for(int i=0; i<_array.size(); i++)
        {
            A.insert(A.end(), _array[i]);
            _size++;
        }

        for(int i=(_size-1)/2; i>=0; i--)
        {
            Min_Heapify(i);
        }
    }
    Min_Heap(T* _array, int array_size)
    {
        _size = 0;
        A.clear(); A.reserve(array_size*2);
        for(int i=0; i<_size; i++)
        {
            A.insert(A.end(), _array[i]);
            _size++;
        }

        for(int i=(_size-1)/2; i>=0; i--)
        {
            Min_Heapify(i);
        }
    }

    void Min_Heapify(int i)
    {
        int smallest;
        int l = left(i);
        int r = right(i);

        if(l<_size && A[l]<A[i]) smallest = l;
        else smallest = i;
        if(r<_size && A[r]<A[smallest]) smallest = r;

        if(smallest != i)
        {
            swap(A[i],A[smallest]);
            Min_Heapify(smallest);
        }
    }

    //The Heap Sort function
    //Final status : The array A's element in desending order.
    void sort()
    {
        for(int i=_size-1; i>0; i--)
        {
            swap(A[0],A[i]);
            --_size;
            Min_Heapify(0);
        }
    }

    T& pop()
    {
        --_size;
        T *tmp = new T;
        *tmp = A[0];
        swap(A[0],A[_size]);
        Min_Heapify(0);
        return *tmp;
    }

    void push(const T &key)
    {
        A.insert(A.end(),INF);
        _size++;

        int i = _size-1;
        while(i>0 && key < A[parent(i)])
        {
            A[i] = A[parent(i)];
            i = parent(i);
        }
        A[i] = key;
    }

    void _delete(int i)  //delete the ith element
    {
        swap(A[i],A[_size-1]);
        --_size;
        A.erase(A.begin()+_size);
        Min_Heapify(i);
    }

    bool decrease_key(int i, const T &key)
    {
        if(key > A[i])
        {
            return false;
        }

        while(i>0 && key < A[parent(i)])
        {
            A[i] = A[parent(i)];
            i = parent(i);
        }
        A[i] = key;
        return true;
    }
/*
    int calc()
    {
        int ans = 0;
        for(int i=0;i<10000;i++)
        {
            ans += A[i/2];
        }
        return ans%10000;
    }
*/
    void showHeap()
    {
        for(int i=0; i<_size; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }

    void showAll()
    {
        for(int i=0; i<A.size(); i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
};



int main()
{
    ifstream in;
    in.open("Median.txt");
    //vector<int> A;
    //A.clear();
    //A.reserve(10001);
    int i=0;
    int A[10000];
    while(in>>A[i]) i++;
    /*
    srand((unsigned int)time(0));
    for(int i=0; i<10; i++)
        A.insert(A.end(),rand()%1000);
    */
    Min_Heap<int> heap(A,10000);
    //heap.showHeap();
    /*
    heap.decrease_key(5,0);
    heap.showHeap();
    heap.sort();
    heap.showAll();
    heap._delete(3);
    heap.showAll();
    */
    return 0;
}
