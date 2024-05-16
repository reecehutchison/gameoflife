//C++ INCLUDED LIBRARIES
#include <vector>

//create matrix
std::vector<std::vector<std::string> > createMatrix();

//prints matrix
void printMatrix(std::vector<std::vector<std::string> > matrix);

//count the neighboring cells
int countNeighbors(int i, int j, std::vector<std::vector<std::string> > matrix); 

//creates the buffer matrix
std::vector<std::vector<std::string> > createBuffer(std::vector<std::vector<std::string> >);  
