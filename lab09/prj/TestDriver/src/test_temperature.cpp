#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include "../../Software/include/ModulesSelikhova.h"

bool doubleEquals(double a, double b, double epsilon = 0.0001) {
    return std::abs(a - b) < epsilon;
}

int main() {
    std::vector<int> temps1 = {0, 10, 20};
    std::pair<double, double> avg1 = calculateAverageTemperature(temps1);
    assert(doubleEquals(avg1.first, 10.0));
    assert(doubleEquals(avg1.second, 50.0));

    std::vector<int> temps2 = {-5, 5};
    std::pair<double, double> avg2 = calculateAverageTemperature(temps2);
    assert(doubleEquals(avg2.first, 0.0));
    assert(doubleEquals(avg2.second, 32.0));

    std::vector<int> temps3 = {};
    std::pair<double, double> avg3 = calculateAverageTemperature(temps3);
    assert(doubleEquals(avg3.first, 0.0));
    assert(doubleEquals(avg3.second, 32.0));

    std::cout << "Тести для calculateAverageTemperature пройшли успішно!" << std::endl;
    return 0;
}
