/**
 * Find the number of inversions in an array.
 * Coursera : Algorithms: Design and Analysis, Part 1 by Tim Roughgarden
 * Programming Question-1
 * Merge Sort & Count
 * Time cost: O(nlogn)
 * Author: Zheng Chen / Arclabs001
 * Copyright 2015 Xi'an University of Posts & Telecommunications
 */
#include <iostream>
using namespace std;

long count = 0;
template <class T>
/**
 * Now both [low,mid] and [mid+1,high] is ordered
 * So just merge them together
 * @param array [The array to be sorted]
 * @param low   [This merge will start from here]
 * @param mid   [The boundary]
 * @param high  [This merge will halt at here]
 */
void my_merge(T* array, long low, long mid, long high)
{
    T* tmp = new T[high + 1];
    for(int i=low; i<=high; i++)
        tmp[i] = array[i];         //Temporary save datas from the array.

    long i = low, j = mid+1, k = low;

    while(i<=mid && j<= high){
        if(tmp[i] <= tmp[j])
            array[k++] = tmp[i++];
        else{
            array[k++] = tmp[j++];
            count += mid - i + 1;
            /*
            Now that A[i]>A[j] and A[i,mid] is ordered
            So that A[i+1],A[i+2],...,A[mid] is larger than A[j]
            Therefore, now we have another mid - i + 1 inversions.
             */
        }
    }

    while(i<= mid) array[k++] = tmp[i++];   //Only one line of this two will be used.
    while(j<=high) array[k++] = tmp[j++];   //

    delete tmp;
}

template <class T>
void merge_sort(T* array, long low, long high)
{
    if(low < high){
        long mid = low + (high - low)/2;
        merge_sort(array, low, mid);
        merge_sort(array, mid+1,high);
        my_merge(array,low,mid,high);
    }
}

int main(void)
{
    int *a = new int[100000];
    fstream input;
    input.open("IntegerArray.txt");

    for(int i=0;i<100000;i++)
        input>>a[i];
    input.close();

    merge_sort(a,0,100000);
    cout<<"There is "<<num<<" inversions in the array."<<endl;
    return 0;
}
