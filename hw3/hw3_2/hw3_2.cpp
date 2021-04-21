/*
 * Title: hw3_2.cpp
 * Abstract: This program reads in a graph and a starting vertex. It then
 * outputs the optimal route, starting from the start vertex and visits 
 * every other vertex exactly once before returning to the start vertex. 
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 11/17/2020
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <limits>
using namespace std;

struct Path{
    vector<int> path;
    int cost;
};

/*
* Method that takes in an array representing a potential path through
* the vertices of the graph from the specified startVertex
* @return - the cost of this path (-1 for no path)
*/
int getCost(int arr[], int size, vector<map<int, int>> graph, int startVertex){
    int from, to;
    int cost = 0;
    
    // Loop through arr, adding the startVertex to the beginning and to the end
    for(int i = -1; i < size; i++){
        if(i == -1){
            from = startVertex;
            to = arr[0];
        } else if(i == size - 1){
            from = arr[size - 1];
            to = startVertex;
        } else {
            from = arr[i];
            to = arr[i + 1];
        }
        
        // Check if "from" has an edge to "to"
        if(graph[from].find(to) != graph[from].end()){
            cost += graph[from][to]; // Add this edge's cost to the total cost
        } else {
            return -1;
        }
    }
    return cost;
}

/*
* Function to check all possible paths through the vertices in the graph
* and return the best cost path 
*/
Path getBestCostPath(int arr[], int size, vector<map<int, int>> graph, int startVertex){
    sort(arr, arr + size);
    bool found = false;
    int minCost = numeric_limits<int>::max();
    vector<int> minPath(size);

    do{
        // Get the cost of this path
        int curCost = getCost(arr, size, graph, startVertex);
        
        // Check if this is the best cost path found so far
        if(curCost != -1 && curCost < minCost){
            found = true;
            minCost = curCost;
            copy(arr, arr + size, minPath.begin());
        }
    // Get the next possible path 
    } while (next_permutation(arr, arr + size));
    
    // Create a new Path struct to hold the return value
    Path result;
    result.path = minPath;
    if(found){
        result.cost = minCost;
    } else {
        result.cost = -1; 
    }
    return result;
}

int main()
{
    int numVertices , numEdges, startVertex;
    cin >> numVertices >> numEdges;
    
    vector<map<int, int>> graph(numVertices);
    
    // Add all the edges and their costs to the graph
    for(int i = 0; i < numEdges; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start].insert({end, cost});
    }
    
    cin >> startVertex;

    // Create an array to find all possible paths through all the vertices
    int vertices[numVertices - 1]; //exclude the start vertex
    int index = 0, value = 0;
    while(index < numVertices - 1){
        if(value != startVertex){
            vertices[index++] = value++;
        } else {
            value++;
        }
    }
    
    int arrLength = numVertices - 1; //because we leave out the start vertex
    Path bestPath = getBestCostPath(vertices, arrLength, graph, startVertex);
    
    // Check if there was no path found
    if(bestPath.cost == -1){
        cout << "Path:" << endl << "Cost:-1" << endl; 
    } else {
        cout << "Path:" << startVertex << "->";
        for(int i = 0; i < arrLength; i++){
            cout << bestPath.path[i] << "->";
        }
        cout << startVertex << endl;
        cout << "Cost:" << bestPath.cost << endl;
    }
    return 0;
}