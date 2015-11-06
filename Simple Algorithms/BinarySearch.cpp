#include <iostream>
using namespace std;

//The first version
template <class T>
static int binSearch(T* A, T & key, int lo, int hi)
{
    while(lo<hi)
    {
        int mid = (hi-lo)/2 + lo;
        (key < A[mid]) ? hi = mid : lo = mid + 1;
    }
    return --lo;
}

//The second version
template <class T>
int compare(T num, T key)
{
    if(key == num) return 0;
    else if(key < num) return 1;
    else return -1;
}
template <class T>
int binSearch(T arr[], int n, T key)
{
    int lo=0, hi=n-1, mid;
    while(lo<=hi){
        mid = (hi-lo)/2 + lo;
        switch(compare(arr[mid],key)){
            case -1: lo = mid+1;break;
            case 0: cout<<mid<<endl; return 0;
            case 1: hi = mid-1; break;
        }
        cout<<mid<<endl;
    }
    return -1;
}

//Test the functions
int main()
{
       int n, m;
       int key1;
       double key2;
       cin >> n >> m >> key1 >> key2;
       int* arr_int = new int[n];
       double* arr_double = new double[m];
       for (int i = 0; i < n; ++i)
              cin >> arr_int[i];
       for (int i = 0; i < m; ++i)
              cin >> arr_double[i];
       binSearch(arr_int, n, key1);
       binSearch(arr_double, m, key2);
       cout<<binSearch(arr_int,key1,0,n-1);
       return 0;
}
