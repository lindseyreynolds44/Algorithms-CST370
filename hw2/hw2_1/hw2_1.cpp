/*
 * Title: hw2_1.cpp
 * Abstract: This program takes a number of vertices and the connected
 * edges between them and then prints out the corresponding graph.
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 11/10/2020
 */

#include <iostream>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<int, list<int>> graph;
    
    int numVertices;
    cin >> numVertices;
    
    int numEdges;
    cin >> numEdges;
    
    // Initialize the vertices 
    for(int i = 0; i < numVertices; i++){
        list<int> l;
        graph.insert({i, l});
    }
    
    // Add all the edges to the graph
    for(int i = 0; i < numEdges; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }
    
    // Print all the vertices and their corresponding edges
    for(int i = 0; i < numVertices; i++){
        cout << i;
        graph[i].sort();
        for(auto edge: graph[i]){
            cout << "->" << edge;
        }
        cout << endl;
    }
    return 0;
}