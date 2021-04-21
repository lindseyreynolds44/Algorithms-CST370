/*
 * Title: hw6_3.cpp
 * Abstract: This program implements Floyd’s algorithm to display all-pairs 
 * shortest paths 
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 12/15/2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getShortestPathMatrix(vector<vector<int>> &matrix, int n);

int main()
{
    int numVertices, cell;
    cin >> numVertices;
    vector<vector<int> > matrix(numVertices);
    
    if(numVertices <= 0) return 0;

    // Add all cells into the matrix
    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            cin >> cell;
            if(cell == -1){
                matrix[i].push_back(INT8_MAX);
            } else {
                matrix[i].push_back(cell);
            }
        }
    }
    
    getShortestPathMatrix(matrix, numVertices);
    
    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
* Convert the input matrix into its shortest path matrix 
*/
void getShortestPathMatrix(vector<vector<int>> &matrix, int n){
    for(int i = 0; i < n; i++){
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                matrix[row][col] = min(matrix[row][col], matrix[i][col] + matrix[row][i]);
            }
        
        }
    }
}

