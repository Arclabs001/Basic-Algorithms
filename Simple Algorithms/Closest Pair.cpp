/**
 * Find closest distance in N points.
 * Time cost: O(nlogn)
 * Author: Zheng Chen / Arclabs001
 * Copyright 2015 Xi'an University of Posts & Telecommunications
 */

/**
 * Algorithm:
 * First of all, sort the points in ascending order by x.
 * Divide the array into 2 parts, and find the smallest distance within two parts.
 * Let min as the smaller one, and find the smallest split distance.
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 0x6FFFFFFF
using namespace std;

struct Node{
	double x, y;

	friend bool operator < (const Node &a, const Node &b){
		if(a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}
};

Node* Point = NULL;
/**
 * Calculate the distance between two points.
 * @return   [double, the distance between a and b]
 */
double _distance(const Node a, const Node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double smaller(double p, double q)
{
	return (p > q) ? q : p;
}
/**
 * [Find the closest distance, divide & conquer]
 * @param  left  [search from where]
 * @param  right [to where]
 * @return       [double, the smallest distance in the whole set of points]
 */
double Closest_distance(int left, int right)
{
	double d = INF;
	double distance_tmp;

	if(left == right)
		return 0;
	if(right == left+1)
		return _distance( Point[left], Point[right] );
	int mid = (left + right) / 2;

	d = smaller( Closest_distance(left,mid) , Closest_distance(mid,right) );

	for(int i=mid-1; i>=left && Point[mid].x - Point[i].x < d; i--){
		for(int j = mid+1; j<=right && Point[j].x - Point[mid].x < d && fabs( Point[i].y - Point[j].y) < d; j++){
			distance_tmp = _distance( Point[i], Point[j] );
			if(distance_tmp < d)
				d = distance_tmp;
		}
	}

	return d;
}

int main()
{
    int n;
    cin>>n;
    Point = new Node[n];
    for(int i=0; i<n ; i++){
    	cin>>Point[i].x>>Point[i].y;
    }
    sort(Point,Point+n);
    cout<<Closest_distance(0,n-1)<<endl;
    return 0;
}
