#include "ModulesSelikhova.h" 
#include <iostream>
#include <numeric>
#include <algorithm>
#include <cmath>

// ЗАДАЧА 9.1
std::string getTornadoCategory(int windSpeedKmH) {
    if (windSpeedKmH >= 419) return "F5 (менше 0,1%)";
    if (windSpeedKmH >= 333) return "F4 (1,1%)";
    if (windSpeedKmH >= 254) return "F3 (4,9%)";
    if (windSpeedKmH >= 181) return "F2 (19,4%)";
    if (windSpeedKmH >= 117) return "F1 (35,8%)";
    if (windSpeedKmH >= 64) return "F0 (38,8%)";
    return "Не класифіковано";
}

// ЗАДАЧА 9.2
std::pair<double, double> calculateAverageTemperature(const std::vector<int>& celsiusTemperatures) {
    if (celsiusTemperatures.empty()) {
        return {0.0, 32.0};
    }
    double sumCelsius = std::accumulate(celsiusTemperatures.begin(), celsiusTemperatures.end(), 0.0);
    double avgCelsius = sumCelsius / celsiusTemperatures.size();
    double avgFahrenheit = (9.0/5.0) * avgCelsius + 32.0;
    return {avgCelsius, avgFahrenheit};
}

// ЗАДАЧА 9.3
int countBinaryZerosOrOnes(int n) {
    if ((n & 1) == 0) {
        int zeros = 0;
        for (int i = 0; i < 16; ++i) {
            if (!((n >> i) & 1)) {
                zeros++;
            }
        }
        return zeros;
    } else {
        int ones = 0;
        for (int i = 0; i < 16; ++i) {
            if ((n >> i) & 1) {
                ones++;
            }
        }
        return ones;
    }
}

// ЗАДАЧА 9.4
std::string getSeasonByMonth(int month) {
    if (month < 1 || month > 12) return "Невідомий місяць";
    if (month == 12 || month == 1 || month == 2) return "Зима";
    if (month >= 3 && month <= 5) return "Весна";
    if (month >= 6 && month <= 8) return "Літо";
    if (month >= 9 && month <= 11) return "Осінь";
    return "Невідомий місяць"; // для безпеки
}
