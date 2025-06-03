#ifndef MODULES_SELIKHOVA_H
#define MODULES_SELIKHOVA_H

#include <string>
#include <vector>
#include <utility>

// ЗАДАЧА 9.1: Визначення категорії торнадо за шкалою Фуджита
// Вхід: швидкість вітру (км/год)
// Вихід: назва категорії (наприклад, "F0", "F1", ...) або повідомлення про помилку
std::string getTornadoCategory(int windSpeedKmH);

// ЗАДАЧА 9.2: Обчислення середньої температури у Цельсіях і Фаренгейтах
// Вхід: вектор із 6 значень температур у Цельсіях (години: 00, 04, 08, 12, 16, 20)
// Вихід: пара <середня Цельсія, середня Фаренгейта>
std::pair<double, double> calculateAverageTemperature(const std::vector<int>& celsiusTemperatures);

// ЗАДАЧА 9.3: Підрахунок кількості нулів або одиниць у 16-бітному представленні числа
// Вхід: ціле число від 0 до 65535
// Вихід: кількість однакових бітів, як у молодшому біті (0 або 1)
int countBinaryZerosOrOnes(int n);

// ЗАДАЧА 9.4: Визначення пори року за номером місяця
// Вхід: номер місяця (1–12)
// Вихід: назва пори року (наприклад, "зима", "весна", ...)
std::string getSeasonByMonth(int month);

#endif // MODULES_SELIKHOVA_H
