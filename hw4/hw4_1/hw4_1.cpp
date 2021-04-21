/*
 * Title: hw4_1.cpp
 * Abstract: This program takes in a set of numbers and then
 * splits them into negative numbers on the left and positive
 * numbers of the right. 
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 12/01/2020
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Helper function to swap two values in a vector
 */
void swap(vector<int> &input, int i, int j){
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

/**
 * First approach solution to the problem
 */
void solution1(vector<int> input){
    int i = 0;
    int j = input.size()-1;

    while(i < j){
        while(i < input.size() && input[i] < 0){
            i++;
        }
        while(j >= 0 && input[j] >= 0){
            j--;
        }
        swap(input, i, j);
    }
    swap(input, i, j);

    for(int i = 0; i < input.size(); i++){
        cout << input[i] << " ";
    }
    cout << endl;
}

/**
 * Second approach solution to the problem
 */
void solution2(vector<int> input){
    int i = 0;
    int j = 0;

    while(i < input.size()){
        if(input[i] < 0){
            swap(input, i, j);
            j++;
        }
        i++;
    }

    for(int i = 0; i < input.size(); i++){
        cout << input[i] << " ";
    }
    cout << endl;
}

int main()
{
    int numElements, element;
    cin >> numElements;

    vector<int> input;

    for(int i = 0; i < numElements; i++){
        cin >> element;
        input.push_back(element);
    }

    solution1(input);
    solution2(input);

    return 0;
}