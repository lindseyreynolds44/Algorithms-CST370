/*
 * Title: hw2_3.cpp
 * Abstract: This program takes a number of boxes and the number
 * of apples in each box. It then provides the max number of apples
 * that you can take out. However, you cannot take apples from boxes that
 * are next to each other. 
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 11/10/2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h> 
using namespace std;

struct BinarySum{
    vector<int> indices;
    int sumValue;
};

/*
* Helper method to get the sum of this binary combination along
* with the list of indices 
*/
BinarySum getBinarySum(int number, vector<int> elements){
    struct BinarySum result;
    vector<int> indexValues;
    int sum = 0;
    
    // Add up the value at each index if it is a 1 
    for(int i = elements.size() - 1; i >= 0; i--){
        int index = pow(2, i); // get the value of this index
        int value = number / index; // check if it should be set to 1 or 0
    
        // if the value was 1, add this index to the sum
        if(value == 1){
            // if this is not the first element and the previous neighbor has been used
            if(i < elements.size() - 1 && find(indexValues.begin(), 
                    indexValues.end(), i + 1) != indexValues.end()){
                result.sumValue = -1; // Return -1 to show this number wasn't valid
                return result;
            }
            number -= index;
            sum += elements[i];
            indexValues.push_back(i);
        }
    }
    result.indices = indexValues;
    result.sumValue = sum;
    return result;
}

int main()
{
    vector<int> boxes, boxNumbers;
    int maxApples = 0, numBoxes;
    cin >> numBoxes;
    
    for(int i = 0; i < numBoxes; i++){
        int numApples;
        cin >> numApples;
        boxes.push_back(numApples);
    }
    
    // Get all the possible binary values 
    int maxValue = pow(2, numBoxes); 
  
    // Loop through every binary value
    for(int i = 0; i < maxValue; i++) 
    { 
        // Get the sum and the box indices for this value
        struct BinarySum sum = getBinarySum(i, boxes);
        
        // Check if this gives the max number of apples
        if(sum.sumValue > maxApples){
            maxApples = sum.sumValue;
            boxNumbers = sum.indices;
        }
    } 
    sort(boxNumbers.begin(), boxNumbers.end());
    
    cout << "Boxes:";
    for(int i = 0; i < boxNumbers.size(); i++){
        cout << boxNumbers[i] << " ";
    }
    cout << endl;
    cout << "Max Apples:" << maxApples << endl;
    
    return 0;
}