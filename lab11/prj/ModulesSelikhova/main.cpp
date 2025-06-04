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
    cout << "������ ����� ������� ��� ������: ";
    getline(cin, search_name);

    auto it = find_if(registry.begin(), registry.end(), [&](const MediaEntry& entry) {
        return entry.name == search_name;
    });

    if (it != registry.end()) {
        cout << "����� ��������: " << endl;
        cout << "�����: " << it->name << endl;
        cout << "���: " << it->type << endl;
        cout << "����������: " << it->certificate << endl;
        cout << "���� ���������: " << it->registration_date << endl;
        cout << "����������: " << it->founders << endl;
        cout << "�����, �� ����� ����������: " << it->registering_authority << endl;
    } else {
        cout << "����� �� ��������." << endl;
    }
}
