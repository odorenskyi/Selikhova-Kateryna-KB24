#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Record {
    string name;
    string type;
    string certificate;
    string registration_date;
    string founders;
    string registering_authority;
};
vector<Record> registry;

void search_by_name() {
    string search_name;
    cin.ignore();
    cout << "Ââåä³òü íàçâó âèäàííÿ äëÿ ïîøóêó: ";
    getline(cin, search_name);

    auto it = find_if(registry.begin(), registry.end(), [&](const Record& entry) {
        return entry.name == search_name;
    });

    if (it != registry.end()) {
        cout << "Çàïèñ çíàéäåíî: " << endl;
        cout << "Íàçâà: " << it->name << endl;
        cout << "Òèï: " << it->type << endl;
        cout << "Ñåðòèô³êàò: " << it->certificate << endl;
        cout << "Äàòà ðåºñòðàö³¿: " << it->registration_date << endl;
        cout << "Çàñíîâíèêè: " << it->founders << endl;
        cout << "Îðãàí, ùî âèäàâ ñåðòèô³êàò: " << it->registering_authority << endl;
    } else {
        cout << "Çàïèñ íå çíàéäåíî." << endl;
    }
}
