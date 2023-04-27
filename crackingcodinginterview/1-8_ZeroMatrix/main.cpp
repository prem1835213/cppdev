#include <vector>
#include <iostream>

/*
    Zero out the row and the column of every element that is a 0
    in a given MxN matrix
*/

void zeroRow(int *matrix, int M, int N, int row){
    if (row >= M || row < 0) return;
    for (int j = 0; j < N; j++){
        *(matrix + row*N + j) = 0;
    }
}

void zeroColumn(int *matrix, int M, int N, int col){
    if (col >= N || col < 0) return;
    for (int i = 0; i < M; i++){
        *(matrix + i*N + col) = 0;
    }
}

void zeroMatrix(int *matrix, int M, int N){
    std::vector<int> rows;
    std::vector<int> cols;

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if (*(matrix + i*N + j) == 0){
                rows.push_back(i);
                cols.push_back(j);
            }
        }
    }

    for (int i = 0; i < rows.size(); i++){
        zeroRow(matrix, M, N, rows[i]);
    }
    for (int i = 0; i < cols.size(); i++){
        zeroColumn(matrix, M, N, cols[i]);
    }
}

int main(){
    int rows = 6;
    int cols = 4;
    int matrix[rows][cols] = {
        {1, 2, 0, 4},
        {3, 0, 1, 1},
        {9, 9, 9, 9},
        {11, 0, 4, 6},
        {10, 0, 3, 1},
        {1, 1, 1, 1}
    };

    zeroMatrix(&matrix[0][0], rows, cols);

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}