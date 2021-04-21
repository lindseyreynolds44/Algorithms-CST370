/*
 * Title: hw6_2.cpp
 * Abstract: This program takes a grid of n x m. Each cell is represented by a 0, 1 or 2. 
 * 1 means that space has a coin, 0 means it has no coin and 2 means it is not accessible. This 
 * program finds the path that collects the maximum number of coins going from the top 
 * left corner down to the bottom right corner. 
 * Author: Lindsey Reynolds
 * Date: 12/15/2020
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fillCostGrid(vector<vector<int> > &input_grid, vector<vector<int> > &cost_grid);
void setCellValue(vector<vector<int> > &input_grid, 
    vector<vector<int> > &cost_grid, int row, int col);
void printResults(vector<vector<int> > &cost_grid, int maxRow, int maxCol);

int main()
{
    int width, height, cell;
    cin >> width >> height;
    vector<vector<int> > input_grid(height);
    vector<vector<int> > cost_grid(height);
    
    if(width <= 0 || height <= 0) return 0;

    // Add all cells into the grid
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cin >> cell;
            input_grid[i].push_back(cell);
            cost_grid[i].push_back(0);
        }
    }
    fillCostGrid(input_grid, cost_grid);
    printResults(cost_grid, height, width);

    return 0;
}

/*
* Method to fill in the cost for every cell of the grid
*/
void fillCostGrid(vector<vector<int> > &input_grid, vector<vector<int> > &cost_grid){

    //Initialize the first row
    cost_grid[0][0] = input_grid[0][0]; 
    for(int col = 1; col < input_grid[0].size(); col++){
        if(input_grid[0][col] == 2 || cost_grid[0][col - 1] == -1){
            cost_grid[0][col] = -1;
        } else {
            cost_grid[0][col] = input_grid[0][col] + cost_grid[0][col - 1];
        }
    }
    //Fill in the the rest of the rows
    for(int row = 1; row < input_grid.size(); row++){
        if(input_grid[row][0] == 2 || cost_grid[row - 1][0] == -1){
            cost_grid[row][0] = -1;
        } else {
            cost_grid[row][0] = input_grid[row][0] + cost_grid[row-1][0];
        }
        for(int col = 1; col < input_grid[0].size(); col++){
            setCellValue(input_grid, cost_grid, row, col);
        }
    }
}

/*
* Helper method to set a cell's value. It will take the greater value between
* the cell above it or to its left and add that to its own value
*/
void setCellValue(vector<vector<int> > &input_grid, 
    vector<vector<int> > &cost_grid, int row, int col){
        if(input_grid[row][col] == 2){
            cost_grid[row][col] = -1;
        } 
        else {
            int maxNum = max(cost_grid[row-1][col], cost_grid[row][col-1]);
            cost_grid[row][col] = maxNum + input_grid[row][col];
        }
}

/*
* Using the cost grid, print out the best path starting from the top left
* corner and going to the bottom right corner.
*/
void printResults(vector<vector<int> > &cost_grid, int maxRow, int maxCol){
    vector<vector<int> > path;
    int curRow = maxRow -1;
    int curCol = maxCol -1;
    
    // Travel from the bottom right, to the top left, on the best path
    while(curRow != 0 || curCol != 0){
        path.push_back({curCol+1, curRow+1});
        if(curRow == 0) { // If we cannot go up anymore
            curCol--;
        } else if(curCol == 0){ // If we cannot go left anymore
            curRow--;
        } else {
            // Check if the top or left has a better cost
            if(cost_grid[curRow-1][curCol] > cost_grid[curRow][curCol-1]){
                curRow--;
            } else {
                curCol--;
            }
        }
    }
    path.push_back({curCol+1, curRow+1});
    
    cout << "Max coins:" << cost_grid[maxRow-1][maxCol-1] << endl;
    cout << "Path: (" << path[path.size()-1][0] << "," << path[path.size()-1][1] << ")";
    for(int i = path.size()-2; i >= 0; i--){
        cout << "->(" << path[i][0] << "," << path[i][1] << ")";
    }
    cout << endl;
}