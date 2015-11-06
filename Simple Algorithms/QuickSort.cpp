/**
 * The Quick Sort Algorithm by C++
 * Average Time Cost: nlogn
 * Author: Zheng Chen / Arc001
 * Copyright 2015 Xi'an University of Posts & Telecommunications
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
long long ans = 0;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

int partition(int A[],int l,int r)
{
    int t = rand()%(r-l);
	int x = A[l+t];
	int i = l;
	int j = l+1;

	swap(A[l+t],A[l]);

	for(;j<=r;j++){
		if(A[j]<=x){
			++i;
			swap(A[i],A[j]);
		}
	}

	swap(A[i],A[l]);
	return i;
}


void Quick_Sort(int A[],int l,int r)
{
    if(l<r){
        int q = partition(A,l,r);
        ans += q-l;
        Quick_Sort(A,l,q-1);
        Quick_Sort(A,q+1,r);
    }
}

int main()  //Test the codes above
{
    /*int A[] = {7,6,5,4,3,2,1};
    Quick_Sort(A,0,6);
    for(int i=0;i<7;i++)
    	cout<<A[i]<<' ';
    */
    fstream in;
    in.open("QuickSort_Test.txt");
    int *A = new int[10000];
    int i = 0;
    for(i=0;i<10000;i++)
        in>>A[i];
    Quick_Sort(A,0,9999);
    for(i=0;i<10;i++)
        cout<<A[i]<<' ';
    cout<<endl<<ans;
    return 0;
}
