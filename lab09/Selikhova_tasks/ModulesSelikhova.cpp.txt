#include <iostream>
using namespace std;

// ЗАДАЧА 9.1 – категорія торнадо
void task9_1() {
    int speed;
    cout << "\n[Задача 9.1] Введіть швидкість вітру (км/год): ";
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

    cout << "\n[Задача 9.2] Введіть температуру за Цельсієм у години (00, 04, 08, 12, 16, 20):\n";
    for (int i = 0; i < 6; ++i) {
        cout << i * 4 << ":00 -> ";
        cin >> temp[i];
        sum += temp[i];
    }

    double avgC = sum / 6.0;
    double avgF = avgC * 9.0 / 5.0 + 32.0;

    cout << "Середня температура: " << avgC << " °C = " << avgF << " °F\n";
}

// ЗАДАЧА 9.3 – аналіз бітів
void task9_3() {
    unsigned int number;
    cout << "\n[Задача 9.3] Введіть натуральне число (0-65535): ";
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

// ЗАДАЧА 9.4 – заглушка calculation
void calculation() {
    cout << "\n[Задача 9.4] Функція calculation() поки що не реалізована.\n";
}
