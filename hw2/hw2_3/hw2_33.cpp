


/*
 * Title: hw2_3.cpp
 * Abstract: This program takes a number of boxes and the number
 * of apples in each box. It then provides the max number of apples
 * that you can take out, if you do not take apples from boxes that
 * are next to each other. 
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 11/10/2020
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h> 
using namespace std;

int main()
{
    vector<int> elements, finalIndices;
    set<int> invalidIndices;
    
    int numElements;
    cin >> numElements;
    
    for(int i = 0; i < numElements; i++){
        int input;
        cin >> input;
        elements.push_back(input);
    }
    
    int maxEven = 0, maxOdd = 0;
    
    // Loop through the elements array, adding up all even elements
    for(int index = 0; index < numElements; index+=2 ){
        maxEven += elements[index];
    }
    
    // Loop through the elements array, adding up all odd elements
    for(int index = 1; index < numElements; index+=2 ){
        maxOdd += elements[index];
    }
    
    cout << "Even " << maxEven << endl;
    cout << "Odd " << maxOdd << endl;
    
    int startIndex = 0, maxApples = 0;
    if(maxEven < maxOdd){
        startIndex = 1;
        maxApples = maxOdd;
    } else {
         maxApples = maxEven;
    }
    
    for(int index = startIndex; index < numElements; index+=2 ){
        finalIndices.push_back(index);
    }
    
    cout << "Boxes:";
    for(int i = 0; i < finalIndices.size(); i++){
        cout << finalIndices[i] << " ";
    }
    cout << endl << "Max Apples:" << maxApples << endl;
    

    return 0;
}