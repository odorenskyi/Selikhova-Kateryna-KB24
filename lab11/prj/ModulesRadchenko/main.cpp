#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "ModulesPopov.h"

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


// ����� ���������� �� ������
void add_entry() {

    MediaEntry entry;
    cin.ignore();
    cout << "����� �������: ";
    getline(cin, entry.name);

    cout << "��� �������: ";
    getline(cin, entry.type);

    cout << "���� �� ����� ��������: ";
    getline(cin, entry.certificate);

    cout << "���� ���������: ";
    getline(cin, entry.registration_date);

    cout << "³������ ��� ����������: ";
    getline(cin, entry.founders);

    cout << "�����, ���� ������� ���������: ";
    getline(cin, entry.registering_authority);

    registry.push_back(entry);

    cout << "����� ������ ������." << endl;
}

// ��������� ���������� �� ������
void load_registry(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "������� ��� ������� �����: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        MediaEntry entry;

        getline(ss, entry.name, ',');
        getline(ss, entry.type, ',');
        getline(ss, entry.certificate, ',');
        getline(ss, entry.registration_date, ',');
        getline(ss, entry.founders, ',');
        getline(ss, entry.registering_authority, ',');

        if (!entry.name.empty() && !entry.type.empty()) {
            registry.push_back(entry);
        } else {
            cerr << "������� ����� �������� � ����: " << line << endl;
        }
    }

    file.close();
    if (file.bad()) {
        cerr << "������� �� ��� ������� �����: " << filename << endl;
    }
}

// ��������� ���������� � ������
void remove_entry() {

    string search_term;
    cin.ignore();
    cout << "������ ����� ������� ��� ���� �� ����� �������� ��� ���������: ";
    getline(cin, search_term);

    auto it = remove_if(registry.begin(), registry.end(), [&](const MediaEntry& entry) {
        return entry.name == search_term || entry.certificate == search_term;
    });

    if (it != registry.end()) {
        registry.erase(it, registry.end());
        cout << "����� �������� ������." << endl;
    } else {
        cout << "����� �� ��������." << endl;
    }
}

