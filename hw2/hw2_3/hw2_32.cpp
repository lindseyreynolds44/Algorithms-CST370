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
    
    int maxApples = 0, index = 0, maxIndex = 0, curMax = 0;
    
    // Loop through the elements array, choosing all largest values
    while(invalidIndices.size() < numElements){
        // Check that this index is not in the invalidIndices array
        if(invalidIndices.find(index) == invalidIndices.end()){
            // check if this element is larger than max
            if(elements[index] > curMax){
                curMax = elements[index];
                maxIndex = index;
            }
        }
        index++;
        
        // Check if the index has reached the end of the elements array
        if(index == numElements){
            maxApples += curMax;
            finalIndices.push_back(maxIndex);
            
            // reset variables
            index = 0;
            curMax = 0;
            
            // add max's index and its neighbors to invalid array
            invalidIndices.insert(maxIndex);
            if(maxIndex < numElements - 1) invalidIndices.insert(maxIndex + 1);
            if(maxIndex > 0) invalidIndices.insert(maxIndex - 1);
        }
    }
    
    sort(finalIndices.begin(), finalIndices.end());
    
    cout << "Boxes:";
    for(int i = 0; i < finalIndices.size(); i++){
        cout << finalIndices[i] << " ";
    }
    cout << endl << "Max Apples:" << maxApples << endl;
    

    return 0;
}

