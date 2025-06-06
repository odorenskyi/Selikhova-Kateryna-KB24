#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "ModulesRadchenko.h"

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


// Çàïèñ ³íôîðìàö³¿ äî ðåºñòðó
void add_entry() {

    Record entry;
    cin.ignore();
    cout << "Íàçâà âèäàííÿ: ";
    getline(cin, entry.name);

    cout << "Âèä âèäàííÿ: ";
    getline(cin, entry.type);

    cout << "Ñåð³ÿ òà íîìåð ñâ³äîöòâà: ";
    getline(cin, entry.certificate);

    cout << "Äàòà ðåºñòðàö³¿: ";
    getline(cin, entry.registration_date);

    cout << "Â³äîìîñò³ ïðî çàñíîâíèê³â: ";
    getline(cin, entry.founders);

    cout << "Îðãàí, ÿêèé çä³éñíèâ ðåºñòðàö³þ: ";
    getline(cin, entry.registering_authority);

    registry.push_back(entry);

    cout << "Çàïèñ äîäàíî óñï³øíî." << endl;
}

// Äîäàâàííÿ ³íôîðìàö³¿ äî ðåºñòðó
void load_registry(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ïîìèëêà ïðè â³äêðèòò³ ôàéëó: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Record entry;

        getline(ss, entry.name, ',');
        getline(ss, entry.type, ',');
        getline(ss, entry.certificate, ',');
        getline(ss, entry.registration_date, ',');
        getline(ss, entry.founders, ',');
        getline(ss, entry.registering_authority, ',');

        if (!entry.name.empty() && !entry.type.empty()) {
            registry.push_back(entry);
        } else {
            cerr << "Íåâ³ðíèé çàïèñ çíàéäåíî ó ôàéë³: " << line << endl;
        }
    }

    file.close();
    if (file.bad()) {
        cerr << "Ïîìèëêà ï³ä ÷àñ ÷èòàííÿ ôàéëó: " << filename << endl;
    }
}

// Âèëó÷åííÿ ³íôîðìàö³¿ ç ðåºñòðó
void remove_entry() {

    string search_term;
    cin.ignore();
    cout << "Ââåä³òü íàçâó âèäàííÿ àáî ñåð³þ òà íîìåð ñâ³äîöòâà äëÿ âèëó÷åííÿ: ";
    getline(cin, search_term);

    auto it = remove_if(registry.begin(), registry.end(), [&](const Record& entry) {
        return entry.name == search_term || entry.certificate == search_term;
    });

    if (it != registry.end()) {
        registry.erase(it, registry.end());
        cout << "Çàïèñ âèëó÷åíî óñï³øíî." << endl;
    } else {
        cout << "Çàïèñ íå çíàéäåíî." << endl;
    }
}


