#include <iostream>
#include <vector>
#include "../../Software/include/ModulesSelikhova.h"

int main() {
    // Приклад використання ЗАДАЧІ 9.1
    int windSpeed = 150;
    std::cout << "Швидкість вітру: " << windSpeed << " км/год -> Категорія торнадо: " << getTornadoCategory(windSpeed) << std::endl;

    // Приклад використання ЗАДАЧІ 9.2
    std::vector<int> temperatures = {0, 4, 8, 12, 16, 20};
    std::pair<double, double> avgTemps = calculateAverageTemperature(temperatures);
    std::cout << "Середня температура: " << avgTemps.first << " °C / " << avgTemps.second << " °F" << std::endl;

    // Приклад використання ЗАДАЧІ 9.3
    int number = 10; // Двійкове представлення: 0000000000001010
    int count = countBinaryZerosOrOnes(number);
    if ((number & 1) == 0) {
        std::cout << "Число " << number << ", біт D0 = 0, кількість нулів: " << count << std::endl;
    } else {
        std::cout << "Число " << number << ", біт D0 = 1, кількість одиниць: " << count << std::endl;
    }

    return 0;
}
