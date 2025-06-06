#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Record {
    std::string name;
    std::string type;
    std::string registration_number;
    std::string registration_date;
    std::string founders_info;
    std::string registering_authority;
};

std::vector<Record> registry;

void saveRegistryData(const std::vector<Record>& registry, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису: " << filename << std::endl;
        return;
    }
    for (const auto& record : registry) {
        file << record.name << '\n'
             << record.type << '\n'
             << record.registration_number << '\n'
             << record.registration_date << '\n'
             << record.founders_info << '\n'
             << record.registering_authority << '\n';
    }
}

void loadRegistryData(std::vector<Record>& registry, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Не вдалося відкрити файл для читання: " << filename << std::endl;
        return;
    }
    Record record;
    while (std::getline(file, record.name) &&
           std::getline(file, record.type) &&
           std::getline(file, record.registration_number) &&
           std::getline(file, record.registration_date) &&
           std::getline(file, record.founders_info) &&
           std::getline(file, record.registering_authority)) {
        registry.push_back(record);
    }
}

void outputRegistry(const std::vector<Record>& registry, const std::string& filename = "") {
    std::ostream* out;
    std::ofstream file;

    if (!filename.empty()) {
        file.open(filename);
        if (!file.is_open()) {
            std::cerr << "Не вдалося відкрити файл для запису: " << filename << std::endl;
            return;
        }
        out = &file;
    } else {
        out = &std::cout;
    }

    for (const auto& record : registry) {
        *out << "Назва видання: " << record.name << "\n"
             << "Тип видання: " << record.type << "\n"
             << "Серія та номер свідоцтва: " << record.registration_number << "\n"
             << "Дата реєстрації: " << record.registration_date << "\n"
             << "Інформація про засновників: " << record.founders_info << "\n"
             << "Орган, який здійснив реєстрацію: " << record.registering_authority << "\n"
             << "------------------------------" << std::endl;
    }

    if (file.is_open()) {
        file.close();
    }
}

void exitProgram(const std::vector<Record>& registry, const std::string& filename) {
    saveRegistryData(registry, filename);
    std::cout << "Дані збережено. Програму завершено." << std::endl;
    exit(0);
}

int main() {
    loadRegistryData(registry, "registry.dat");

    outputRegistry(registry);

    outputRegistry(registry, "exported_registry.txt");

    exitProgram(registry, "registry.dat");

    return 0;
}
