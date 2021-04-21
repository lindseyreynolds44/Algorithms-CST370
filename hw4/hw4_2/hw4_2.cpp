/*
 * Title: hw4_2.cpp
 * Abstract: This program uses a divide and conquer technique
 * to solve for the maximum number in a set of numbers
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 12/01/2020
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Method to recursively find the max number in an input array
 */
int findMax(vector<int> input, int start, int end){
    if(start == end) return input[start]; //base case

    int max1 = findMax(input, start, start + (end-start)/2); //left
    int max2 = findMax(input, start + (end-start)/2 + 1, end); //right

    if(max1 > max2) return max1;
    return max2;
}

int main()
{
    int numElements, element;
    cin >> numElements;
    
    if(numElements <= 0) return 0;

    vector<int> input;

    // Add in all the input numbers to the input array
    for(int i = 0; i < numElements; i++){
        cin >> element;
        input.push_back(element);
    }

    int max = findMax(input, 0, numElements - 1);

    cout << max << endl;

    return 0;
}