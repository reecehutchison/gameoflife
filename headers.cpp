//C++ Included Library
#include <iostream>
#include <vector>

//FILES INCLUDED
#include "headers.hpp"

//creates the matrix
std::vector<std::vector<std::string> > createMatrix() {
    //init matrix 
    std::vector<std::vector<std::string> > matrix; 
    //sizes : 
    int n = 22; 
    int m = 22; 
    matrix.resize(n, std::vector<std::string>(m, "⬜️")); 
    return matrix; 
}

//print the matrix
void printMatrix(std::vector<std::vector<std::string> > matrix) { 
   for (int i = 1; i < matrix.size() - 1; i++) {
       for (int j = 1; j < matrix[i].size() - 1; j++) {
            std::cout << matrix[i][j];
       }
       std::cout << std::endl; 
   }
}

//counts neighbors
int countNeighbors(int i, int j, std::vector<std::vector<std::string> > matrix) {
    int count = 0;  
    std::string alive = "⬛️"; 
    if (matrix[i][j + 1] == alive) count++; 
    if (matrix[i + 1][j + 1] == alive) count++; 
    if (matrix[i + 1][j] == alive) count++; 
    if (matrix[i + 1][j - 1] == alive) count++; 
    if (matrix[i][j - 1] == alive) count++; 
    if (matrix[i - 1][j - 1] == alive) count++;
    if (matrix[i - 1][j] == alive) count++; 
    if (matrix[i - 1][j + 1] == alive) count++; 
    return count; 
}

//creates the buffer matrix
std::vector<std::vector<std::string> > createBuffer(std::vector<std::vector<std::string> > matrix) { 

    std::string alive = "⬛️"; 
    std::string dead = "⬜️"; 
    int n = matrix.size(); 
    int m = matrix[0].size(); 

    std::vector<std::vector<std::string> > newMatrix(n, std::vector<std::string>(m, "⬜️"));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            newMatrix[i][j] = matrix[i][j]; 
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            int neighborCount = countNeighbors(i, j, matrix);

            //dead cell
            if (matrix[i][j] == dead) {
                //rule 4
                if (neighborCount == 3) {
                    newMatrix[i][j] = alive; 
                }
            }
            //live cell
            else {
                //rule 1
                if (neighborCount < 2) {
                    newMatrix[i][j] = dead; 
                } 
                //rule 2
                else if (neighborCount == 2 || neighborCount == 3) {
                    newMatrix[i][j] = alive; 
                }
                //rule 3
                else if (neighborCount > 3) {
                    newMatrix[i][j] = dead; 
                }
            }
        }
    }
    return newMatrix; 
}
