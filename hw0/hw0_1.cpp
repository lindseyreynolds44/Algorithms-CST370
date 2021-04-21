/*
 * Title: hw0_1.cpp
 * Abstract: This program calculates the sum and difference of two numbers.
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 10/26/2020
 */

#include <iostream>
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
    // Continue to allow user to give input
    while(true){
        int a, b, c;
        
        // Get the first number
        cin >> a;
        if(a == 9) return 0;
        
        // Get the two input numbers
        cin >> b >> c;
        
        if(a == 1){
            cout << getSum(b, c) << endl;
        } else if(a == 2){
            cout << getDifference(b, c) << endl;
        }
    }
    
    return 0;
}