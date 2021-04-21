/*
 * Title: hw6_1.cpp
 * Abstract: This program takes in a set of numbers from the user and 
 * sorts them using radix sort (aka bucket sort). 
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 12/15/2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxElement(vector<int> input);
void radixSort(vector<int> input, int numDigits, int base);
int getNumDigits(int number);

int main()
{
    int numElements, element;
    int base = 10;
    cin >> numElements;
    
    if(numElements <= 0) return 0;

    vector<int> input;

    // Add all the numbers into the input array
    for(int i = 0; i < numElements; i++){
        cin >> element;
        input.push_back(element);
    }
    int maxElement = getMaxElement(input);
    int maxDigits = getNumDigits(maxElement);

    radixSort(input,maxDigits, base);

    return 0;
}

// Helper function to get the max value in a vector
int getMaxElement(vector<int> input){
    int max = input[0];
    for(int i = 1; i < input.size(); i++){
        if(max < input[i]) max = input[i];
    }
    return max;
}

// Helper function to get the number of digits in a number
int getNumDigits(int number){
    string str_num = to_string(number);
    return str_num.size();
}

// Perform radix sort on a set of numbers, using a specified base 
void radixSort(vector<int> input, int numDigits, int base){
    vector<vector<int> > buckets(base);
    int mod_value = base;
    int divider = 1;

    // Loop through each digit, starting at the LSD
    for(int digit = 0; digit < numDigits; digit++){
        // Loop through each number in input 
        for(int i = 0; i < input.size(); i++){
            int curNum = input[i];

            // Get the current digit or "bucket"
            int bucket = curNum % mod_value;
            bucket = bucket/divider;

            // Put the current number into its appropriate bucket
            buckets[bucket].push_back(curNum);
        }
        // Reset the input array
        input.clear();

        // Loop through each bucket in buckets array
        for(int i = 0; i < buckets.size(); i++){
            // Put each number from this bucket back into input array
            for (int j = 0; j < buckets[i].size(); j++){ 
                input.push_back(buckets[i][j]);
            }
            buckets[i].clear(); //reset this bucket
        }
        // Print the current state of input
        for(int i = 0; i < input.size(); i++){
            cout << input[i] << " ";
        }       
        cout << endl; 

        mod_value *= base;
        divider *= base;
    }

}
