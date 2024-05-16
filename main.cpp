//preprocessing
#include <thread>
#include "headers.hpp"
#include <vector>
#include <iostream>
#include <chrono> 

#define ALIVECHAR '\xe9'; 

//entry point
int main() {

    //create and fill matrix turn this into a function late when you 2d it. 
    std::vector<std::vector<int> > matrix;
    matrix = createMatrix(); 

    //loooooooooooop
    while (true) {
        std::cout << "\033c"; 
        printMatrix(matrix); 
        matrix = createBuffer(matrix);
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
      return 0; 
}


