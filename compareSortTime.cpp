//C++ code to compare performance of sorting algorithms
//Array sizes of about 10^7 may take 15-20 seconds for execution and lot of computing power
#include <iostream>
#include <time.h>		//For counting time
#include <algorithm>	//For inbuilt sort function
#define MaxElementInArray 1000000001
using namespace std;

int Compare (const void * a, const void * b) {		// Compare function used by qsort
    return ( *(int*)a - *(int*)b );
}

int* GenerateRandomArray(int n) {
	srand(time(NULL));
	int *a = new int[n];
	for(int i = 0; i < n;i++)
		a[i] = rand() % MaxElementInArray;
	return a;
}

int* CopyArray(int a[], int n) {
	int *arr = new int[n];
	for(int i = 0; i < n ;i++)
		arr[i] = a[i];
	return arr;
}

void InsertionSortAsc(int a[], int start, int end) {		//Code for Insertion Sort
	for(int i = start + 1; i <= end ; ++i) {
		int j = i - 1, key = a[i];
		while(j >= start && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void MergeArray(int a[], int start, int end, int mid) {			//Code for Merge Sort
	int i = start, j = mid + 1, k = 0;
	int *temp = new int[end - start + 1];
	while(i <= mid && j <= end) {
		if(a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while(i <= mid)
		temp[k++] = a[i++];
	while(j <= end)
		temp[k++] = a[j++];
	j = 0; 
	for(i = start;i <= end;++i) 
		a[i] = temp[j++]; 
	delete temp;
} 

void MergeSort(int a[],int start,int end) {
	if(start < end) {
		int mid = start + (end - start) / 2;
		MergeSort(a,start,mid);
		MergeSort(a,mid + 1,end);
		MergeArray(a,start,end,mid);
	} 
} 

void InsertionMergeSort(int a[], int start, int end, int k) {
	// Performs insertion sort if size of array is less than or equal to k 
	// Otherwise, uses mergesort 
	if(start < end) {
		int size = end - start + 1;
		
		if(size <= k) {
			return InsertionSortAsc(a,start,end); 
		}
		int mid = start + (end - start) / 2;
		InsertionMergeSort(a,start,mid,k);
		InsertionMergeSort(a,mid + 1,end,k);
		MergeArray(a,start,end,mid);
	} 
} 

void TestRuntime(int size,int num) {
	// Measuring the runtime of the sorting algorithms 
	int t = num;
	int n = size; 
	double InsertionSortTime = 0, MergeSortTime = 0, InsertionMergeTime = 0, InbuiltSortTime = 0, QuickSortTime = 0;
	while(t--) {
		clock_t start, end; 
		
		int *a = GenerateRandomArray(n);

		int *b = CopyArray(a,n);
		start = clock();
		InsertionSortAsc(b,0,n-1);
		end = clock();
		InsertionSortTime += ((double) (end - start)) / CLOCKS_PER_SEC;
		delete b;

		int *c = CopyArray(a,n);
		start = clock();
		MergeSort(c,0,n - 1);
		end = clock();
		MergeSortTime += ((double) (end - start)) / CLOCKS_PER_SEC;
		delete c;

		int *d = CopyArray(a,n);
		start = clock();
		InsertionMergeSort(d,0,n-1,40); 
		end = clock(); 
		InsertionMergeTime += ((double) (end - start))/CLOCKS_PER_SEC; 
		delete d;

		int *e = CopyArray(a,n);
		start = clock();
		sort(e, e + n);
		end = clock();
		InbuiltSortTime += ((double) (end - start))/CLOCKS_PER_SEC;
		delete e;

		start = clock();
		qsort(a,n,sizeof(int),Compare);
		end = clock(); 
		QuickSortTime += ((double) (end - start)) / CLOCKS_PER_SEC; 
		delete a;
	} 
	
	InsertionSortTime /= num;
	MergeSortTime /= num;
	InsertionMergeTime /= num;
	InbuiltSortTime /= num;
	QuickSortTime /= num;

	printf("\nTime taken to sort:\n"
			"%-35s %f\n"
			"%-35s %f\n"
			"%-35s %f\n"
			"%-35s %f\n"
			"%-35s %f\n\n",
			"(i)Insertion sort: ",
			InsertionSortTime,
			"(ii)Merge sort: ",
			MergeSortTime,
			"(iii)Insertion-mergesort-hybrid: ",
			InsertionMergeTime,
			"(iv)Inbuilt sort function: ",
			InbuiltSortTime,
			"(v)Qsort library function: ",
			QuickSortTime);
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int size, num;
		cin>>size>>num;
		TestRuntime(size,num);
	} 
	return 0; 
} 
