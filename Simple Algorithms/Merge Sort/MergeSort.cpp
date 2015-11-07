/**
 * Merge Sort Algorithm by C++ Template
 * Time cost: O(nlogn)
 * Author: Zheng Chen / Arclabs001
 * Copyright 2015 Xi'an University of Posts & Telecommunications
 */
#include <iostream>
using namespace std;

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
        }
    }

    while(i<= mid) array[k++] = tmp[i++];  //Only one line of this two will be used.
    while(j<=high) array[k++] = tmp[j++];  //

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

int main()
{
    int A[50] = { 37, 7, 2, 14, 35, 47, 10, 24, 44, 17, 34, 11, 16, 48, 1, 39, 6, 33, 43, 26, 40, 4, 28, 5, 38, 41, 42, 12, 13, 21, 29, 18, 3, 19, 0, 32, 46, 27, 31, 25, 15, 36, 20, 8, 9, 49, 22, 23, 30, 45 };
    merge_sort(A,0,50);
    for(int i=0; i<50; i++)
        cout<<A[i]<<" ";
    return 0;
}
