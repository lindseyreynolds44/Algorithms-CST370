/*
 * Title: hw3_1.cpp
 * Abstract: This program takes in an integer number and then outputs
 * that number in reverse, dropping any trailing zeros.
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 11/17/2020
 */

#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int inputNum, output;
    cin >> inputNum;
    
    // Convert the input integer to a string
    string input = to_string(inputNum);
    int len = input.length();
    
    // Get rid of all trailing zeros
    int start = len - 1;
    while(input[start] == '0'){
        start--;
    }
    
    // Reverse the input number
    string reverse;
    for(int i=start ; i>= 0; i--){
        reverse += input[i];
    }
    
    // Output the reversed integer
    stringstream stream(reverse); 
    stream >> output; 
    cout << output << endl;
    
    return 0;
}