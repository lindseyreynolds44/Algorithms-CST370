/*
 * Title: hw0_1.cpp
 * Abstract: This program calculates the sum and difference of two numbers.
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 10/26/2020
 */

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int getSum(int num1, int num2){
    int sum = num1 + num2;
    return sum;
}

int getDifference(int num1, int num2){
    int diff = abs(num1 - num2);
    return diff;
}

int main()
{
    while(true){
        // Get user input
        string userInput;
        getline(cin, userInput);
        
        // Make sure the user entered something
        if(userInput.empty()){
            return 0;
        }
        
        // Turn userInput into a stream
        stringstream userStream(userInput);
        vector<int> values; // To hold the int values from user
        
        // Split the stream by spaces
        string token;
        while (getline(userStream, token, ' ')) {
            stringstream tokenStream(token);
            int num = 0;
            tokenStream >> num;
            values.push_back(num);
        }
        
        // Check if the program should get the sum or difference
        if(values[0] == 1){
            cout << getSum(values[1], values[2]) << endl;
        } else if(values[0] == 2){
            cout << getDifference(values[1], values[2]) << endl;
        } else {
            return 0;
        }
    }
    
    return 0;
}