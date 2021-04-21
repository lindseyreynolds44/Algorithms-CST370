/*
 * Title: hw5_1.cpp
 * Abstract: This program reads in a set of numbers, determines whether or
 * not they are ordered as a max heap, if they are not, it will order them. It
 * then allows the user to insert, remove and update elements in the heap, as well
 * as display the heap and its max value.
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 12/08/2020
 */

#include <iostream>
#include <vector>
using namespace std;

void displayHeap(vector<int> heap);
void displayMax(vector<int> heap);
void updateValue(vector<int> &heap, int index, int value);
void deleteMax(vector<int> &heap);
void deleteValue(vector<int> &heap, int value);
void insertValue(vector<int> &heap, int value);
bool isMaxHeap(vector<int> &heap);
void swap(vector<int> &heap, int ind1, int ind2);
bool bubbleDown(vector<int> &heap, int n, int index);
void bubbleUp(vector<int> &heap, int index);
int getIndex(vector<int> heap, int value);

int main()
{
    int numElements, element, index, numCommands;
    cin >> numElements;
    
    if(numElements <= 0) return 0;

    vector<int> input;
    input.push_back(0); // heap values start at index 1

    // Add all the numbers into the input array
    for(int i = 0; i < numElements; i++){
        cin >> element;
        input.push_back(element);
    }
    
    if(isMaxHeap(input)){
        cout << "This is a heap." << endl;
    } else {
        cout << "This is NOT a heap." << endl;
    }
    
    cin >> numCommands;
    string command;
    
    // Read in the user's commands
    for(int i = 0; i < numCommands; i++){
        cin >> command;
        
        if(command == "display") {
            displayHeap(input);
        } else if(command == "deleteMax"){
            deleteMax(input);
        } else if(command == "displayMax"){
            displayMax(input);
        } else if(command == "update"){
            cin >> index >> element;
            updateValue(input, index, element);
        } else if(command == "delete"){
            cin >> element;
            deleteValue(input, element);
        } else if(command == "insert"){
            cin >> element;
            insertValue(input, element);
        }
    }
    return 0;
}

/**
 * Check if this vector represents a max heap. If not, covert it into a
 * heap and return false. Otherwise, return true. 
 */
bool isMaxHeap(vector<int> &heap){
    bool isHeap = true;
    int n = heap.size()-1;
    int startIndex = n/2;
    
    //Loop through the non-leaf nodes
    for(int i = startIndex; i >= 1; i--){
        if(!bubbleDown(heap, n, i)) isHeap = false;
    }
    return isHeap;
}

/**
 * Display the contents of the heap
 */
void displayHeap(vector<int> heap){
    for(int i = 1; i < heap.size(); i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}

/**
 * Display the max value of the heap
 */
void displayMax(vector<int> heap){
    cout << heap[1] << endl;
}

/**
 * Delete the max value of the heap
 */
void deleteMax(vector<int> &heap){
    // Swap last index with max 
    swap(heap, 1, heap.size()-1);
    
    // Remove max from heap
    heap.pop_back(); 

    // Bubble the value swapped with max down to its appropriate place
    bubbleDown(heap, heap.size()-1, 1);
    
}

/**
 * Update the value at a specified index in the heap
 */
void updateValue(vector<int> &heap, int index, int value){
    // Replace the value at index with value
    heap[index] = value;
    
    // Check if this value should be bubbled up
    if(index > 1 && value > heap[index/2]){
        bubbleUp(heap, index);
    } else { // Otherwise, bubble down
        bubbleDown(heap, heap.size()-1, index);
    }
    
}

/**
 * Delete a specified value from the heap
 */
void deleteValue(vector<int> &heap, int value){
    // Get value's index
    int index = getIndex(heap, value);
    // Swap deleted value with the last index
    swap(heap, index, heap.size()-1);
    // Remove the deleted value from the heap
    heap.pop_back();
    
    // Check if the value that replaced the deleted value should be bubbled up
    if(index > 1 && heap[index] > heap[index/2]){
        bubbleUp(heap, index);
    } else { // Otherwise, bubble down
        bubbleDown(heap, heap.size()-1, index);
    }
}

/**
 * Insert a value into the heap
 */
void insertValue(vector<int> &heap, int value){
    // Add this value to the end of the heap
    heap.push_back(value);
    // Bubble this value up to the appropriate place
    bubbleUp(heap, heap.size()-1);
}

/**
 * Helper funtion to swap two values in the heap based on their indices
 */
void swap(vector<int> &heap, int ind1, int ind2){
    int temp = heap[ind1];
    heap[ind1] = heap[ind2];
    heap[ind2] = temp;
}

/**
 * Helper function to bubble the value at index down to its
 * appropriate position in the heap
 */
bool bubbleDown(vector<int> &heap, int n, int index){
        bool isHeap = true;
        
        int parent = index;
        int val = heap[parent];
        bool heapify = true;
        
        while(parent*2 <= n && heapify){
            int child = parent * 2;
            if(parent*2 < n){ //Check value of second child
                if(heap[child + 1] > heap[child]) child++;
            }
            if(val < heap[child]){
                isHeap = false;
                heap[parent] = heap[child];
                parent = child;
            } else {
                heapify = false;
            }
        }
        heap[parent] = val;
        return isHeap;
}

/**
 * Helper function to bubble the value at index up to its
 * appropriate position in the heap
 */
void bubbleUp(vector<int> &heap, int index){
    // Start at index and bubble the value at index up to its place
    while(index > 1 && heap[index] > heap[index/2]){
        swap(heap, index, index/2);
        index = index/2;
    }
    
}

/**
 * Helper function to return the index of a specified value
 */
int getIndex(vector<int> heap, int value){
    for(int i = 1; i < heap.size(); i++){
        if(value == heap[i]) return i;
    }
    return -1;
}