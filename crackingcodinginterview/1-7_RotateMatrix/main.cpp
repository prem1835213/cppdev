#include <string>
#include <iostream>

template<size_t rows, size_t cols>
void rotateMatrix(int M[rows][cols], size_t N){
    if (N <= 1) {
        return;
    }
    if (rows != cols && rows != N){
        return;
    }

    size_t numLayers = N / 2;
    for (size_t layer = 0; layer < numLayers; layer++){
        size_t n = N - 2*layer - 1;
        for (size_t i = 0; i < n; i++){
            int temp = M[layer][i + layer];
            M[layer][i+layer] = M[N - 1 - i - layer][layer]; // A gets B
            M[N - 1 - i - layer][layer] = M[N - 1 - layer][N - 1 - i - layer]; // B gets D
            M[N - 1 - layer][N - 1 - i - layer] = M[i + layer][N - 1 - layer]; // D gets C
            M[i + layer][N - 1 - layer] = temp; // C gets A
        }
    }

    return;
}

int main(){
    int M[5][5];
    std::cout << "Original: " << std::endl;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            M[i][j] = i + j;
            std::cout << i+j << " ";
        }
        std::cout << std::endl;
    }
    
    rotateMatrix<(size_t) 5, (size_t) 5>(M, 5);
    std::cout << std::endl;
    std::cout << "Result: " << std::endl;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
}