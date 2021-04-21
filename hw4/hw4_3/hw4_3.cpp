/*
 * Title: hw4_3.cpp
 * Abstract: This program uses Kahn's algorithm to conduct
 * a topological sort.
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 12/01/2020
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Method to find the topological ordering of a graph
 */
void getKahnPath(vector<vector<int> > graph, vector<int> &path, vector<int> degree){

    // Put all vertices with 0 in-degree in a queue
    queue<int> q;
    for(int i = 0; i < degree.size(); i++){
        if(degree[i] == 0) q.push(i);  
    }

    while(!q.empty()){
        // Pop an element off the queue
        int curVertex = q.front();
        q.pop();

        // Add this vertex to the path
        path.push_back(curVertex);

        // Reduce the in-degree of all neighbors of curVertex
        for(int i = 0; i < graph[curVertex].size(); i++){
            int neighbor = graph[curVertex][i];
            degree[neighbor] = degree[neighbor] - 1;

            if(degree[neighbor] == 0) q.push(neighbor);
        }
    }
}

int main()
{
    int numVertices , numEdges;
    cin >> numVertices >> numEdges;

    vector<vector<int> > graph(numVertices);
    vector<int> degree(numVertices);
    vector<int> path;
    
    // Add all the edges to the graph
    for(int i = 0; i < numEdges; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        degree[end] = degree[end] + 1; //add in-degree
    }

    // Print in-degrees
    for(int i = 0; i < numVertices; i++){
        cout << "In-degree[" << i << "]:" << degree[i] << endl;
    }

    getKahnPath(graph, path, degree);

    // Print the path
    if(path.size() < numVertices){
        cout << "No Order:" << endl;
    } else {
        cout << "Order:" << path[0];

        for(int i = 1; i < path.size(); i++){
            cout << "->" << path[i];
        }
        cout << endl;
    }
    
    return 0;
}