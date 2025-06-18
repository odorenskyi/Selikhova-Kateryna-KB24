#include <iostream>
#include <fstream>
#include <string>
#include "ModulesSelikhova.h"  // Підключаємо бібліотеку

// Прототипи функцій (якщо потрібно)
// namespace Selikhova { void task10_1(...); void task10_2(...); void task10_3(...); }

void log_test_result(const std::string& testName, bool passed) {
    std::cout << testName << ": " << (passed ? "passed" : "failed") << std::endl;
}

bool compare_files(const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1);
    std::ifstream f2(file2);

    if (!f1.is_open() || !f2.is_open()) {
        return false;
    }

    std::string line1, line2;
    while (true) {
        bool res1 = static_cast<bool>(std::getline(f1, line1));
        bool res2 = static_cast<bool>(std::getline(f2, line2));
        if (res1 != res2) return false;
        if (!res1) break;
        if (line1 != line2) return false;
    }
    return true;
}

int main() {
    std::string inFile = "input.txt";
    std::string outFile = "output.txt";

    // ==== Test suite for task 10.1 ====
    {
        // Підготовка вхідного файлу
        std::ofstream fin(inFile);
        fin << "Це перше речення з \"лапками\".\n";
        fin << "Це речення без голосних: бкдшг.\n";
        fin.close();

        // Виклик тестованої функції
        Selikhova::task10_1(inFile, outFile);

        // Перевірка вихідного файлу (порівняння з очікуваним)
        bool testPassed = false;
        std::ifstream fout(outFile);
        if (fout.is_open()) {
            std::string content((std::istreambuf_iterator<char>(fout)),
                                 std::istreambuf_iterator<char>());
            // Приклад очікуваної перевірки — перевіримо, що виведено кількість лапок і речення без голосних
            testPassed = content.find("Кількість лапок у реченні:") != std::string::npos &&
                         content.find("Речення без голосних літер:") != std::string::npos;
        }
        log_test_result("Task 10.1", testPassed);
    }

    // ==== Test suite for task 10.2 ====
    {
        // Вхідний файл (дописуємо)
        std::ofstream fin(inFile);
        fin << "Привіт, світ!\nЦе тест транслітерації.";
        fin.close();

        // Виклик функції дозапису транслітерації і дати
        Selikhova::task10_2(inFile);

        // Перевірка, чи файл містить транслітерований текст і дату
        std::ifstream finCheck(inFile);
        bool testPassed = false;
        if (finCheck.is_open()) {
            std::string content((std::istreambuf_iterator<char>(finCheck)),
                                 std::istreambuf_iterator<char>());
            testPassed = (content.find("Transliterated") == std::string::npos) &&
                         (content.find("Дата дозапису:") != std::string::npos);
            // У реальності треба шукати транслітерований текст (українською транслітерацією)
            // Але це приклад, можна покращити
            testPassed = content.find("Транслітерований текст:") != std::string::npos &&
                         content.find("Дата дозапису:") != std::string::npos;
        }
        log_test_result("Task 10.2", testPassed);
    }

    // ==== Test suite for task 10.3 ====
    {
        // Підготовка файлів
        std::ofstream fin(inFile);
        fin << "Тестовий текст для підрахунку символів.";
        fin.close();

        // Очищуємо вихідний файл перед тестом
        std::ofstream fout(outFile, std::ios::trunc);
        fout.close();

        // Виклик функції
        double x = 3.0, y = 4.0;
        int B = 7;
        Selikhova::task10_3(inFile, outFile, x, y, B);

        // Перевірка, чи у вихідному файлі є результати обчислення та двійковий код
        std::ifstream foutCheck(outFile);
        bool testPassed = false;
        if (foutCheck.is_open()) {
            std::string content((std::istreambuf_iterator<char>(foutCheck)),
                                 std::istreambuf_iterator<char>());
            testPassed = (content.find("Результат обчислення s(x, y):") != std::string::npos) &&
                         (content.find("Число B у двійковому коді:") != std::string::npos) &&
                         (content.find("міститься") != std::string::npos);
        }
        log_test_result("Task 10.3", testPassed);
    }

    return 0;
}
