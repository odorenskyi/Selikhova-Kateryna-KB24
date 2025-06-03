#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <limits>

using namespace std;

// Прототипи функцій
void task9_1(); // категорія торнадо
void task9_2(); // середня температура
void task9_3(); // бітовий аналіз
void calculation(); // додаткова функція-заглушка

int main() {
    char command;

    while (true) {
        cout << "\nВведіть команду (г - торнадо, s - температура, t - бітовий аналіз, z - calculation): ";
        cin >> command;

        switch (command) {
            case 'г':
                task9_1();
                break;
            case 's':
                task9_2();
                break;
            case 't':
                task9_3();
                break;
            case 'z':
                calculation();
                break;
            default:
                cout << "Невідома команда. Спробуйте ще раз. \a\n";
                break;
        }

        cout << "\nБажаєте вийти з програми? (q або о для виходу, інше - продовження): ";
        char exitChar;
        cin >> exitChar;
        if (exitChar == 'q' || exitChar == 'о') {
            break;
        }
    }

    return 0;
}

// ЗАДАЧА 9.1 – категорія торнадо
void task9_1() {
    int speed;
    cout << "\nВведіть швидкість вітру (км/год): ";
    cin >> speed;

    if (speed >= 64 && speed <= 116)
        cout << "Категорія: F0, Частота: 38.9%\n";
    else if (speed >= 117 && speed <= 180)
        cout << "Категорія: F1, Частота: 35.6%\n";
    else if (speed >= 181 && speed <= 253)
        cout << "Категорія: F2, Частота: 19.4%\n";
    else if (speed >= 254 && speed <= 332)
        cout << "Категорія: F3, Частота: 4.9%\n";
    else if (speed >= 333 && speed <= 418)
        cout << "Категорія: F4, Частота: 1.1%\n";
    else if (speed >= 419 && speed <= 512)
        cout << "Категорія: F5, Частота: <0.1%\n";
    else
        cout << "Дані поза межами шкали Фудзіти\n";
}

// ЗАДАЧА 9.2 – середня температура
void task9_2() {
    double temp[6];
    double sum = 0;

    cout << "\nВведіть температуру за Цельсієм у такі години (00, 04, 08, 12, 16, 20):\n";
    for (int i = 0; i < 6; ++i) {
        cout << i * 4 << ":00 -> ";
        cin >> temp[i];
        sum += temp[i];
    }

    double avgC = sum / 6.0;
    double avgF = avgC * 9.0 / 5.0 + 32.0;

    cout << "Середня температура: " << avgC << " °C = " << avgF << " °F\n";
}

// ЗАДАЧА 9.3 – аналіз бітів числа
void task9_3() {
    unsigned int number;
    cout << "\nВведіть натуральне число (0-65535): ";
    cin >> number;

    if (number > 65535) {
        cout << "Число виходить за межі 16-бітного діапазону.\n";
        return;
    }

    int count = 0;
    int bit = number & 1;

    for (int i = 0; i < 16; ++i) {
        int currentBit = (number >> i) & 1;
        count += (bit == 0) ? (currentBit == 0) : (currentBit == 1);
    }

    cout << "Молодший біт = " << bit << ". Кількість ";
    if (bit == 0)
        cout << "нулів = " << count << endl;
    else
        cout << "одиниць = " << count << endl;
}

// ЗАДАЧА 9.4 – заглушка для функції calculation
void calculation() {
    cout << "\nФункція calculation() поки що не реалізована.\n";
}
