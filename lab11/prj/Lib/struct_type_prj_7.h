#ifndef STRUCT_TYPE_PRJ_7_H_INCLUDED
#define STRUCT_TYPE_PRJ_7_H_INCLUDED
#include <iostream>

struct MediaEntry {
    string name;
    string type;
    string certificate;
    string registration_date;
    string founders;
    string registering_authority;
};

struct Record {
    string name;
    string type;
    string registration_number;
    string registration_date;
    string founders_info;
    string registering_authority;
};

vector<Record> registry;
vector<MediaEntry> registry;
    char chief;
    char regist;
};

#endif // STRUCT_TYPE_PRJ_7_H_INCLUDED
