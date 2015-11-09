/**
 * The Stack Data Structure in C++
 * Author: Zheng Chen / Arclabs001
 * Copyright 2015 Xi'an University of Posts & Telecommunications
 */
#include <iostream>

using namespace std;

template <class T>
class myStack
{
private:
    int top;
    T *data;
    int size;   //The size of the data array

public:
    myStack() : top(-1){ data = new T[100]; size = 100; }  //Constructor
    myStack(int tp, int _size, T* _data) : top(tp)
    {
        data = new T[_size];
        size = _size;
        for(int i=tp; i>=0; i--)
        {
            data[i] = _data[i];
        }
    }
    myStack(myStack & _stack)   //The copy constructor
    {
        size = _stack.size;
        this->top = _stack.top;

        for(int i=_stack.top; i>=0; i--)
        {
            data[i] = _stack.pop();
        }
    }
    ~myStack()      //The destructor
    {
        delete [] data;
    }

    /**
     * Get the top element in the stack
     * @return The value of the top element
     */
    T & getTop() const
    {
        return data[top];
    }
    /**
     * Pop the top element
     * @return The value of the pop element
     */
    T & pop()
    {
        if(!isEmpty())
        {
            T * tmp = new T;
            *tmp = data[top--];
            return *tmp;
        }
        else
        {
            cout<<"Stack is empty!"<<endl;
            T *i;
            *i = -1;
            return *i;
        }
    }
    /**
     * Push an element into the stack
     * If the stack is full, double the size of array
     * @param  _data The element to be pushed
     * @return       A integer : top
     */
    int push(T _data)
    {
        if(++top > size)
        {
            T * tmp = new T[2*size];
            for(int i=top-1; i>=0; i--)
            {
                tmp[i] = data[i];
            }

            data = tmp;

            size *= 2;
        }

        data[top] = _data;
        return top;
    }
    /**
     * Evaluate whether the stack is empty
     * @return A boolean : True for the stack is empty, and false for not
     */
    bool isEmpty() const
    {
        return top==-1;
    }
    /**
     * Display the stack on the screen. Usually for test.
     */
    void display()
    {
        for(int i=0; i<=top; i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl<<"Stack Top : "<<data[top]<<endl;
        cout<<"Top : "<<top<<endl;
        cout<<"Size: "<<size<<endl;
    }
};

int main()  //To test the stack
{
    myStack<int> Stack;
    for(int i=0; i<102; i++)
    {
        Stack.push(i+1);
    }
    Stack.display();

    Stack.pop();
    Stack.display();

    Stack.pop();
    Stack.display();

    return 0;
}
