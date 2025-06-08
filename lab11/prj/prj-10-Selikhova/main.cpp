#include <iostream>
#include "ModulesNovak.h"
#include "ModulesRadchenko.h"
#include "ModulesSelikhova.h"

int main() {
    setlocale(LC_ALL, "");
    load_registry_data(registry, "registry.dat");

    int choice;
    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Додати запис\n";
        cout << "2. Видалити запис\n";
        cout << "3. Шукати запис за назвою\n";
        cout << "4. Завантажити реєстр з файлу\n";
        cout << "5. Вивести реєстр\n";
        cout << "6. Зберегти реєстр\n";
        cout << "7. Вийти з програми\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                remove_entry();
                break;
            case 3:
                search_by_name();
                break;
            case 4:
                loadRegistryData("registry.txt");
                break;
            case 5:
                outputRegistry(registry);
                break;
            case 6:
                save_registry_data(registry);
                break;
            case 7:
                exitProgram(registry, "registry.dat");
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    }

    return 0;
}
