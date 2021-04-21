/*
 * Title: hw5_2.cpp
 * Abstract: This program compares the running times of three sorting 
 * algorithms, quick sort, merge sort and heap sort. 
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 12/08/2020
 */

#include <iostream>
#include <chrono>
using namespace std;

// Methods to time each sorting algorithm
double timeHeapSort(int arr[], int size);
double timeQuickSort(int arr[], int size);
double timeMergeSort(int arr[], int size);

// Methods for heap sort
void heapSort(int heap[], int arr[], int n);
void bubbleDown(int heap[], int n, int index);
int removeMax(int heap[], int size);

// Methods for quick sort
void quicksort(int arr[], int start, int end);
void swap(int arr[], int x, int y);

// Methods for merge sort 
void mergeSort(int arr[],int l,int r);
void merge(int arr[], int l, int m, int r);

int main()
{
    int inputSize;
    cin >> inputSize;
    
    // Dynamically allocate memory for each array
    int* heapArr = new int[inputSize];
    int* mergeArr = new int[inputSize];
    int* quickArr = new int[inputSize];
    
    srand(time(0)); // seed the random number generator
    
    // Fill each array with random numbers
    for(int i = 0; i < inputSize; i++){
        // Get numbers between 0 and the size of the array
        int randNum = rand() % inputSize; 
        heapArr[i] = randNum;
        mergeArr[i] = randNum;
        quickArr[i] = randNum;
    }
    
    // Get the running time for each sorting algorithm
    double heapSortTime = timeHeapSort(heapArr, inputSize);
    double mergeSortTime = timeMergeSort(mergeArr, inputSize);
    double quickSortTime = timeQuickSort(quickArr, inputSize);
    
    cout << "===================== Execution Time ====================" << endl;
    cout << "Heap sort: \t"<< heapSortTime << " milliseconds" << endl;
    cout << "Merge Sort: \t"<< mergeSortTime << " milliseconds" << endl;
    cout << "Quick sort: \t"<< quickSortTime << " milliseconds" << endl;
    cout << "=========================================================" << endl;
    
    // Free all the memory used
    delete[] heapArr;
    delete[] mergeArr;
    delete[] quickArr;
    
    return 0;
    
}

/**
 * Method to time heap sort and return the number of milliseconds it took
 */
double timeHeapSort(int arr[], int size){
    int* heap = new int[size + 1];
    for(int i = 1; i < size +1; i++){
        heap[i] = arr[i-1];
    }
    
    auto start = chrono::high_resolution_clock::now();
    heapSort(heap, arr, size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_time = end - start;
    
    delete[] heap;
    return elapsed_time.count();
}

/**
 * Method to time merge sort and return the number of milliseconds it took
 */
double timeMergeSort(int arr[], int size){
    
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, size-1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_time = end - start;
    return elapsed_time.count();
}

/**
 * Method to time quick sort and return the number of milliseconds it took
 */
double timeQuickSort(int arr[], int size){
    
    auto start = chrono::high_resolution_clock::now();
    quicksort(arr, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_time = end - start;
    return elapsed_time.count();
}


/**
 * Heap sort algorithm that takes in a heap and a return array.
 * This method puts the sorted data into arr. 
 */
void heapSort(int heap[], int arr[], int n){
    int startIndex = n/2;
    
    //Loop through the non-leaf nodes to heapify the heap
    for(int i = startIndex; i >= 1; i--){
        bubbleDown(heap, n, i);
    }

    // Create the new sorted array
    for(int i = n-1, heapSize = n; i >= 0; i--, heapSize--){
        arr[i] = removeMax(heap, heapSize);
    }

}

/**
 *  Remove and return the max value of the heap
 */
int removeMax(int heap[], int size){
    int max = heap[1];
    // Swap last index with max 
    swap(heap, 1, size);

    // Bubble the value swapped with max down to its appropriate place
    bubbleDown(heap, size-1, 1);
    return max;
}

/**
 * Helper function to bubble the value at index down to its
 * appropriate position in the heap
 */
void bubbleDown(int heap[], int n, int index){
        
        int parent = index;
        int val = heap[parent];
        bool heapify = true;
        
        while(parent*2 <= n && heapify){
            int child = parent * 2;
            if(parent*2 < n){ //Check value of second child
                if(heap[child + 1] > heap[child]) child++;
            }
            if(val < heap[child]){
                heap[parent] = heap[child];
                parent = child;
            } else {
                heapify = false;
            }
        }
        heap[parent] = val;
}

/**
 * Merge sort algorithm
 * Credit: https://www.geeksforgeeks.org/merge-sort/
 */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

/**
 * Helper function for mergeSort
 * Credit: https://www.geeksforgeeks.org/merge-sort/
 */
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * Quick sort algorithm that sorts the input array recursively
 */
void quicksort(int arr[], int start, int end){
    if(start >= end) return;
    
    //get the pivot = arr[start]
    int pivot = arr[start];
    //set index i to start+1 and j to end
    int i = start+1;
    int j = end;
    
    while (i <= j){
        while (i <= end && arr[i] < pivot){
            i++;
        }
        while (j > start && arr[j] >= pivot){
            j--;
        }
        swap(arr, i, j);
    }
    
    swap(arr, i, j); // swap j and i back
    swap(arr, start, j); // swap pivot and j
    
    quicksort(arr, start, j-1);
    quicksort(arr, j + 1, end);
}

/**
 * Helper method to swap two values in an array
 */
void swap(int arr[], int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}


