//C++ INCLUDED LIBRARY
#include <iostream>
#include <chrono> 
#include <thread> 


//FILES INCLUDED
#include "headers.hpp" 

//ENTRY POINT
int main() {

    //creates matrix
    std::vector<std::vector<std::string> > matrix;  
    matrix = createMatrix();     




    std::string alive = "⬛️"; 
    std::string dead = "⬜️"; 
    
    matrix[2][2] = alive; 
    matrix[3][3] = alive; 
    matrix[3][4] = alive; 
    matrix[4][3] = alive; 
    matrix[2][4] = alive; 

    matrix[18][2] = alive; 
    matrix[16][2] = alive; 
    matrix[16][3] = alive; 
    matrix[17][3] = alive; 
    matrix[17][4] = alive; 


    //looooooop 
    while (true) {
        std::cout << "\033c";
        printMatrix(matrix);
        matrix = createBuffer(matrix); 
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    //return (:
    return 0; 

}
