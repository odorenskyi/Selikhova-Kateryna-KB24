#include <iostream>
#include "ModulesSelikhova.h"

int main() {
    int arr[] = {10, 4, 7, 3, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Факторіал 5 = " << factorial(5) << std::endl;
    std::cout << "Сума елементів масиву = " << sumArray(arr, size) << std::endl;
    std::cout << "Мінімальний елемент масиву = " << minInArray(arr, size) << std::endl;

    return 0;
}
