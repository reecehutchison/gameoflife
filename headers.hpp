#include <vector> 
//headers for my headers.cpp file


//make the 2d matrix
std::vector<std::vector<int> > createMatrix();  
//prints the 2d matrix
void printMatrix(std::vector<std::vector<int> > matrix);
//count neibohrs
int countNeighbors(int i, int j, std::vector<std::vector<int> > matrix); 
//create buffer array
std::vector<std::vector<int> > createBuffer (std::vector<std::vector<int> > matrix); 
