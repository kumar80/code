// C++ implementation of Bogo Sort 
#include<bits/stdc++.h> 
using namespace std; 

// To check if array is sorted or not 
int cnt=0;
bool isSorted(int a[], int n) 
{ 
	while ( --n > 1 ) 
		if (a[n] < a[n-1]) 
			return false; 
	return true; 
} 

// To generate permuatation of the array 
void shuffle(int a[], int n) 
{ 
	for (int i=0; i < n; i++) 
		swap(a[i], a[rand()%n]); 
} 

// Sorts array a[0..n-1] using Bogo sort 
void bogosort(int a[], int n) 
{ 
	// if array is not sorted then shuffle 
	// the array again 
	while ( !isSorted(a, n) ) 
		shuffle(a, n),cnt++; 
} 

// prints the array 
void printArray(int a[], int n) 
{  for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<cnt;
} 

// Driver code 
int main() 
{ 	int n; cin>>n; 
	int a[n]; 
    for(int i=0;i<n;i++) cin>>a[i]; 
	bogosort(a, n); 
	printf("Sorted array :\n"); 
	printArray(a,n); 
	return 0; 
} 
