/*
 * Title: hw1_1.cpp
 * Abstract: This program finds the minimum distance between two numbers in
 * a set of numbers
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 11/03/2020
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* Helper method to get the difference between two ints
* and return that number 
*/
int getDistance(int num1, int num2){
    int diff = abs(num1 - num2);
    return diff;
}

int main()
{
    //Read in the length of the set 
    int num_length;
    cin >> num_length;
    vector<int> nums;
    
    //Make sure there are enough numbers to compare 
    if(num_length < 2){
        return 0;
    }
    
    //Read in the first two numbers 
    int num, num2;
    cin >> num >> num2;
    nums.push_back(num);
    nums.push_back(num2);
    
    //Get their distance
    int min_dist = getDistance(num, num2);
    vector<int> min_nums = {num, num2};
    
    //Read in the rest of the numbers to find the min distance
    int index = 2;
    while(index < num_length){
        cin >> num;
        for(auto curNum: nums){
            int distance = getDistance(num, curNum);
            if(min_dist > distance){
                min_dist = distance;
                min_nums = {num, curNum};
            }
        }
        nums.push_back(num);
        index++;
    }
    
    //Sort the numbers with the min distance
    sort(min_nums.begin(), min_nums.begin()+2);
    
    cout << "Min distance: " << min_dist << endl;
    cout << "Two numbers for min distance: " << min_nums[0] << " and " << min_nums[1] << endl;

    
    return 0;
}