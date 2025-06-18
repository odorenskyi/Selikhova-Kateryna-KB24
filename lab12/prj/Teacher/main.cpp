#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>    // Для std::string
#include <cmath>     // Для round, M_PI (якщо використовується напряму)
#include <iomanip>   // Для std::fixed, std::setprecision (для кращого виводу)
#include <stdexcept> // Для обробки винятків з класу

// Включаємо файл заголовка нашого класу ClassLab12_Selikhova
// Важливо: переконайтеся, що шлях до файлу правильний відносно main.cpp
#include "../moduleselikhova.h"

using namespace std;

// Оновлена структура для тестового набору
struct TestSuite {
    string shape;    // Форма столу
    float param1;    // Перший параметр
    float param2;    // Другий параметр
    float expResult; // Очікуваний результат (площа)
};

// Функція для читання CSV-файлу (оновлена під нові параметри)
vector<TestSuite> readCSVFile(string filePath) {
    ifstream testSuiteFile(filePath);
    vector<TestSuite> autotest;
    TestSuite ts;
    string line, value;

    if (!testSuiteFile.is_open()) {
        cerr << "Помилка: Не вдалося відкрити файл " << filePath << endl;
        return autotest; // Повертаємо порожній вектор у випадку помилки
    }

    getline(testSuiteFile, line); // Пропускаємо заголовок CSV (перший рядок)

    while (getline(testSuiteFile, line)) {
        stringstream s(line);
        vector<string> row;

        while (getline(s, value, ',')) {
            // Видаляємо пробіли на початку та в кінці кожного значення
            value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
            value.erase(value.find_last_not_of(" \t\n\r\f\v") + 1);
            row.push_back(value);
        }

        // Очікуємо 4 стовпці: форма, param1, param2, expResult
        if (row.size() >= 4) {
            ts.shape = row[0];
            ts.param1 = stof(row[1]);
            // param2 може бути порожнім для деяких форм (наприклад, коло)
            ts.param2 = (row[2].empty() || row[2] == "0") ? 0.0f : stof(row[2]);
            ts.expResult = stof(row[3]);
            autotest.push_back(ts);
        } else {
            cerr << "Попередження: Пропущено рядок з некоректною кількістю стовпців: " << line << endl;
        }
    }

    testSuiteFile.close();
    return autotest;
}

int main() {
    ofstream testResultFile;
    string pathFile = __FILE__;
    size_t found = pathFile.find("\\Lab12\\prj");

    // Встановлюємо точність виводу для результатів тесту
    cout << fixed << setprecision(2);

    if (found == string::npos) {
        testResultFile.open("TestResult.txt");
        if (!testResultFile.is_open()) return -1;

        // Необхідно вказати причину порушення вимог, а не просто "біп"
        // Видалено цикл з '\a'
        testResultFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
        testResultFile << "Будь ласка, розмістіть проект у відповідній директорії: ...\\Lab12\\prj\\teacher\\main.cpp" << endl;
    } else {
        testResultFile.open("..\\..\\TestSuite\\TestResult.txt");
        if (!testResultFile.is_open()) {
            cerr << "Помилка: Не вдалося відкрити файл результатів тестування TestResult.txt" << endl;
            return -1;
        }

        vector<TestSuite> autotest = readCSVFile("..\\..\\TestSuite\\TS.txt");

        if (autotest.empty()) {
            testResultFile << "Немає даних для тестування. Перевірте файл TS.txt" << endl;
        }

        for (int i = 0; i < autotest.size(); i++) {
            float result = 0.0f;
            bool test_passed = false;
            string status_message = "";

            try {
                // Створення об'єкта класу ClassLab12_Selikhova з параметрами з тестового набору
                ClassLab12_Selikhova table(autotest[i].shape, autotest[i].param1, autotest[i].param2);
                result = table.calculateArea();

                // Порівняння з округленням (для плаваючих чисел)
                // Використовуємо невеликий допуск для порівняння float
                float tolerance = 0.01f; // Допуск, наприклад, 0.01
                if (abs(autotest[i].expResult - result) < tolerance) {
                    test_passed = true;
                    status_message = "passed";
                } else {
                    status_message = "failed";
                }

            } catch (const invalid_argument& e) {
                status_message = "failed (Помилка валідації: " + string(e.what()) + ")";
            } catch (const runtime_error& e) {
                status_message = "failed (Помилка виконання: " + string(e.what()) + ")";
            } catch (const exception& e) {
                status_message = "failed (Невідома помилка: " + string(e.what()) + ")";
            }

            testResultFile << "test №" << i + 1 << " -> " << status_message << endl;
            if (!test_passed && status_message.find("passed") == string::npos) { // Якщо тест не пройшов або виникла помилка
                testResultFile << "  Очікувано -> " << autotest[i].expResult << endl;
                testResultFile << "  Фактично -> " << result << endl;
                testResultFile << "  Параметри: Форма='" << autotest[i].shape
                               << "', P1=" << autotest[i].param1
                               << ", P2=" << autotest[i].param2 << endl;
            }
            testResultFile << endl;
        }
    }

    testResultFile.close();
    system("pause"); // Залишаємо для зручності відладки в Windows
    return 0;
}