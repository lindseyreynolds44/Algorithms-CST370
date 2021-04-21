/*
 * Title: hw1_3.cpp
 * Abstract: This program takes events as input and returns the maximum 
 * number of events occuring at the same time. 
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 11/03/2020
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<int, int> events;
    int numEvents;
    cin >> numEvents;
    
    
    for(int i = 0; i < numEvents; i++){
        int start, end;
        cin >> start >> end;
        for(int hour = start; hour <= end; hour++){
            events[hour] = events[hour] + 1;
        }
    }

    int max = 0;
    for(int hour = 1; hour <= 24; hour++){
        if(events[hour] > max){
            max = events[hour];
        }
    }
    
    cout << "Max events: " << max << endl;
    
    return 0;
}