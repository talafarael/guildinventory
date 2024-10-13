#include <iostream>
#include "dataMatrixInput.h"
void dataMatrixInput(int& column, int& row, int& count) {
    std::cout << "Please enter Column ";
    std::cin >> column;
    std::cout << "Please enter Row: ";
    std::cin >> row;
    std::cout << "Enter count: ";
    std::cin >> count;
}