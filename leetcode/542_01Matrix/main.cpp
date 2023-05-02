#include <vector>
#include <iostream>
#include <queue>

/*
    Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
    Distance is considered as the Manhattan Distance.
    Distance betwen two adjacent cells is 1.
*/

bool checkFree(int i, int j, int numRows, int numCols, std::vector<std::vector<int>>& mat){
    if (i < 0 || j < 0 || i >= numRows || j >= numRows) return false;
    if (mat[i][j] != -1) return false;
    return true;
}

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat){
    int numRows = mat.size();
    int numCols = mat[0].size();

    // start BFS from each 0
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            if (mat[i][j] == 0) {
                q.push(std::make_pair(i, j));
            }
            else{
                mat[i][j] = -1;
            }
        }
    }

    while (!q.empty()){
        std::pair<int, int> loc = q.front();
        q.pop();
        // Check all 4 neighbors, add to queue if unexplored
        if (checkFree(loc.first+1, loc.second, numRows, numCols, mat)){
            q.push(std::make_pair(loc.first+1, loc.second));
            mat[loc.first+1][loc.second] = 1 + mat[loc.first][loc.second];
        }
        if (checkFree(loc.first-1, loc.second, numRows, numCols, mat)){
            q.push(std::make_pair(loc.first-1, loc.second));
            mat[loc.first-1][loc.second] = 1 + mat[loc.first][loc.second];
        }
        if (checkFree(loc.first, loc.second+1, numRows, numCols, mat)){
            q.push(std::make_pair(loc.first, loc.second+1));
            mat[loc.first][loc.second+1] = 1 + mat[loc.first][loc.second];
        }
        if (checkFree(loc.first, loc.second-1, numRows, numCols, mat)){
            q.push(std::make_pair(loc.first, loc.second-1));
            mat[loc.first][loc.second-1] = 1 + mat[loc.first][loc.second];
        }
    }

    return mat;
}

int main(){
    std::vector<std::vector<int>> mat = {{0, 1, 1}, {1, 1, 1}, {1, 1, 0}};
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[0].size(); j++){
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Updated to: " << std::endl;

    mat = updateMatrix(mat);
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[0].size(); j++){
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}