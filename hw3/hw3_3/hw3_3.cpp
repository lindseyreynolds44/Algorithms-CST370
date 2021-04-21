/*
 * Title: hw3_3.cpp
 * Abstract: This program implements a depth first search through an array
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 11/17/2020
 */

#include <iostream>
#include <vector>
using namespace std;
int counter = 1;

/*
* The depth first search recursive method
*/
void dfs(int vertex, vector<int> &mark, vector<vector<int>> graph){
    mark[vertex] = counter++;
    
    // Get all this vertex's neighboring vertices
    for(int i = 0; i < graph[vertex].size(); i++){
        // Check if this neighbor has already been visited
        if(mark[graph[vertex][i]] == 0){
            dfs(graph[vertex][i], mark, graph);
        }
    }
}

int main()
{
    int numVertices , numEdges;
    cin >> numVertices >> numEdges;
    vector<vector<int>> graph(numVertices);
    
    // Add all the edges and their costs to the graph
    for(int i = 0; i < numEdges; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }
    vector<int> mark(numVertices, 0);
    
    // Perform depth first search on the graph
    dfs(0, mark, graph);
    
    for(int i = 0; i < numVertices; i++){
        cout << "Mark[" << i << "]:" << mark[i] << endl;
    }

    return 0;
}