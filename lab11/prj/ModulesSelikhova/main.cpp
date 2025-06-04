#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct MediaEntry {
    string name;
    string type;
    string certificate;
    string registration_date;
    string founders;
    string registering_authority;
};
vector<MediaEntry> registry;

void search_by_name() {
    string search_name;
    cin.ignore();
    cout << "Введіть назву видання для пошуку: ";
    getline(cin, search_name);

    auto it = find_if(registry.begin(), registry.end(), [&](const MediaEntry& entry) {
        return entry.name == search_name;
    });

    if (it != registry.end()) {
        cout << "Запис знайдено: " << endl;
        cout << "Назва: " << it->name << endl;
        cout << "Тип: " << it->type << endl;
        cout << "Сертифікат: " << it->certificate << endl;
        cout << "Дата реєстрації: " << it->registration_date << endl;
        cout << "Засновники: " << it->founders << endl;
        cout << "Орган, що видав сертифікат: " << it->registering_authority << endl;
    } else {
        cout << "Запис не знайдено." << endl;
    }
}
