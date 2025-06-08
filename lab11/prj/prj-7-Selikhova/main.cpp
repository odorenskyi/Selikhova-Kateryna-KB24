#include <iostream>
#include "ModulesNovak.h"
#include "ModulesRadchenko.h"
#include "ModulesSelikhova.h"

int main() {
    setlocale(LC_ALL, "");
    load_registry_data(registry, "registry.dat");

    int choice;
    while (true) {
        cout << "\n����:\n";
        cout << "1. ������ �����\n";
        cout << "2. �������� �����\n";
        cout << "3. ������ ����� �� ������\n";
        cout << "4. ����������� ����� � �����\n";
        cout << "5. ������� �����\n";
        cout << "6. �������� �����\n";
        cout << "7. ����� � ��������\n";
        cout << "������� �����: ";
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
                cout << "������� ����. ��������� �� ���." << endl;
        }
    }

    return 0;
}
