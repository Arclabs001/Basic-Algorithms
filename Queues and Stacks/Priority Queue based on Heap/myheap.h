#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

template <class T>
class Min_Heap
{
public:
    std::vector<T> A;
    int _size;

    int parent(int i) {return (i-1)/2;}    //Get the index of ith parent  
    int left(int i)   { return 2*i+1; }    //Get the index of ith left child
    int right(int i)  { return 2*i+2; }    //Get the index of ith right child

    //Here are three different constructor
    Min_Heap() {A.clear(); A.reserve(100); _size=0;}
    Min_Heap(std::vector<T> _array)
    {
        _size = 0;
        A.clear(); A.reserve(_array.size()*2);
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

    void show()
    {
        for(int i=0; i<_size; i++)
        {
            std::cout<<A[i]<<" ";
        }
        std::cout<<std::endl;
    }
};

