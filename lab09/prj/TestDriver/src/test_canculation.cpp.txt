#include <iostream>
#include <cassert>
#include <cmath>
#include "../../Software/include/ModulesSelikhova.h"  

bool doubleEquals(double a, double b, double epsilon = 0.0001) {
    return std::abs(a - b) < epsilon;
}

int main() {
    double radius1 = 1.0;
    double area1 = calculateCircleArea(radius1);
    assert(doubleEquals(area1, 3.14159));

    double radius2 = 0.0;
    double area2 = calculateCircleArea(radius2);
    assert(doubleEquals(area2, 0.0));

    double radius3 = 2.5;
    double area3 = calculateCircleArea(radius3);
    assert(doubleEquals(area3, 19.63495));

    std::cout << "Тести для calculateCircleArea пройшли успішно!" << std::endl;
    return 0;
}
