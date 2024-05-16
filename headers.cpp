//#include <iostream>
#include <vector>
#include "headers.hpp"
#include <iostream>
#include <cstdlib>
//make the 2d vector
std::vector<std::vector<int> > createMatrix() {
    std::vector<std::vector<int> > matrix;  
    for (int i = 0; i < 22; i++) {
        matrix.emplace_back(42, 0); 
    }
    //THIS IS FOR RANDOM GENERATION OF PATTERNS
//    for (int i = 1; i < matrix.size() - 1; i++) {
//        for (int j = 1; j < matrix[i].size(); j++) {
//        matrix[i][j] = rand() % 2; 
//        }
//    }

        // Glider Gun Pattern
    matrix[5][1] = 1;
    matrix[5][2] = 1;
    matrix[6][1] = 1;
    matrix[6][2] = 1;

    matrix[3][13] = 1;
    matrix[3][14] = 1;
    matrix[4][12] = 1;
    matrix[4][16] = 1;
    matrix[5][11] = 1;
    matrix[5][17] = 1;
    matrix[6][11] = 1;
    matrix[6][15] = 1;
    matrix[6][17] = 1;
    matrix[6][18] = 1;
    matrix[7][11] = 1;
    matrix[7][17] = 1;
    matrix[8][12] = 1;
    matrix[8][16] = 1;
    matrix[9][13] = 1;
    matrix[9][14] = 1;

    matrix[3][21] = 1;
    matrix[4][21] = 1;
    matrix[5][21] = 1;
    


    return matrix;
}

//prints 2d matrix
void printMatrix(std::vector<std::vector<int> > matrix) {
    std::cout << "\033c"; 
    for (int i = 1; i < matrix.size() - 1; i++) {
        for (int j = 1; j < matrix[i].size() - 1; j++) { 
            std::cout << matrix[i][j];  
        }
        std::cout << "\n"; 
    }
}

//counts neighbors
int countNeighbors(int i, int j, std::vector<std::vector<int> > matrix) {
    int count = 0;  
    if (matrix[i][j + 1] == 1) count++; 
    if (matrix[i + 1][j + 1] == 1) count++; 
    if (matrix[i + 1][j] == 1) count++; 
    if (matrix[i + 1][j - 1] == 1) count++; 
    if (matrix[i][j - 1] == 1) count++; 
    if (matrix[i - 1][j - 1] == 1) count++;
    if (matrix[i - 1][j] == 1) count++; 
    if (matrix[i - 1][j + 1] == 1) count++; 
    return count; 
}

//create buffer matrix
std::vector<std::vector<int> > createBuffer (std::vector<std::vector<int> > matrix) { 
   
    for (int i = 1; i < matrix.size() - 1; i++) {
        for (int j = 1; j < matrix[i].size() - 1; j++) {
            int neighborCount = countNeighbors(i, j, matrix);

            //dead cell
            if (matrix[i][j] == 0) {
                //rule 4
                if (neighborCount == 3) {
                    matrix[i][j] = 1; 
                }
            }
            //live cell
            if (matrix[i][j] == 1) {
                //rule 1
                if (neighborCount < 2) {
                    matrix[i][j] = 0; 
                } 
                //rule 2
                //it just stays the same
                
                //rule 3
                if (neighborCount > 3) {
                    matrix[i][j] = 0; 
                }
            }
        }
    }
    return matrix; 
}


