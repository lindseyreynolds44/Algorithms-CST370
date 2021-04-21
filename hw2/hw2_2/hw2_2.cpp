/*
 * Title: hw2_2.cpp
 * Abstract: This program takes a list of elements and then prints 
 * them based on the power set algorithm
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 11/10/2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h> 
using namespace std;

/*
* Helper method to convert a decimal number into binary form 
* using a specified number of digits
*/
string toBinary(int number, int numDigits){
    if(numDigits == 0){
        return "0";
    }
    
    string output = "";
    // Set every digit of output to 0 or 1
    for(int i = numDigits - 1; i >= 0; i--){
        // get the value of this index
        int index = pow(2, i);
        // check if number should have a 1 or 0 at this index
        int value = number / index;
        // set this index in the output string to 1 or 0
        output += to_string(value);
        
        // if the value was 1, subtract the index value from number
        if(value == 1){
            number -= index;
        }
    }
    return output;
}

int main()
{
    vector<string> elements;
    int numElements;
    cin >> numElements;
    
    // Read in all the elements
    for(int i = 0; i < numElements; i++){
        string input;
        cin >> input;
        elements.push_back(input);
    }
    reverse(elements.begin(), elements.end());
    
    // Get all the possible binary values 
    int max_pow = pow(2, numElements); 
  
    // Loop through every binary value
    for(int i = 0; i < max_pow; i++) 
    { 
        // Get the binary version of the value i
        string binary = toBinary(i, numElements);
        cout << binary << ":";
        
        if(i == 0){
            cout << "EMPTY" << endl;
        } 
        else {
            // Loop through, checking if each index should be displayed
            for(int j = numElements - 1; j >= 0; j--){ 
                if(i & (1 << j)) 
                    cout << elements[j] << " "; 
            } 
            cout << endl; 
        }
    } 
    return 0;
}