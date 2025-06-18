#include <iostream>
#include "ModulesSelikhova.h"

int main() {
    std::string inFile = "input.txt";
    std::string outFile = "output.txt";

    // Завдання 10.1
    Selikhova::task10_1(inFile, outFile);
    std::cout << "Завдання 10.1 виконано.\n";

    // Завдання 10.2
    Selikhova::task10_2(inFile);
    std::cout << "Завдання 10.2 виконано.\n";

    // Завдання 10.3
    double x = 3.0, y = 4.0;
    int B = 5;
    Selikhova::task10_3(inFile, outFile, x, y, B);
    std::cout << "Завдання 10.3 виконано.\n";

    return 0;
}
