#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>    // ��� std::string
#include <cmath>     // ��� round, M_PI (���� ��������������� �������)
#include <iomanip>   // ��� std::fixed, std::setprecision (��� ������� ������)
#include <stdexcept> // ��� ������� ������� � �����

// �������� ���� ��������� ������ ����� ClassLab12_Selikhova
// �������: �������������, �� ���� �� ����� ���������� ������� main.cpp
#include "../moduleselikhova.h"

using namespace std;

// �������� ��������� ��� ��������� ������
struct TestSuite {
    string shape;    // ����� �����
    float param1;    // ������ ��������
    float param2;    // ������ ��������
    float expResult; // ���������� ��������� (�����)
};

// ������� ��� ������� CSV-����� (�������� �� ��� ���������)
vector<TestSuite> readCSVFile(string filePath) {
    ifstream testSuiteFile(filePath);
    vector<TestSuite> autotest;
    TestSuite ts;
    string line, value;

    if (!testSuiteFile.is_open()) {
        cerr << "�������: �� ������� ������� ���� " << filePath << endl;
        return autotest; // ��������� ������� ������ � ������� �������
    }

    getline(testSuiteFile, line); // ���������� ��������� CSV (������ �����)

    while (getline(testSuiteFile, line)) {
        stringstream s(line);
        vector<string> row;

        while (getline(s, value, ',')) {
            // ��������� ������ �� ������� �� � ���� ������� ��������
            value.erase(0, value.find_first_not_of(" \t\n\r\f\v"));
            value.erase(value.find_last_not_of(" \t\n\r\f\v") + 1);
            row.push_back(value);
        }

        // ������� 4 �������: �����, param1, param2, expResult
        if (row.size() >= 4) {
            ts.shape = row[0];
            ts.param1 = stof(row[1]);
            // param2 ���� ���� ������� ��� ������ ���� (���������, ����)
            ts.param2 = (row[2].empty() || row[2] == "0") ? 0.0f : stof(row[2]);
            ts.expResult = stof(row[3]);
            autotest.push_back(ts);
        } else {
            cerr << "������������: ��������� ����� � ����������� ������� ��������: " << line << endl;
        }
    }

    testSuiteFile.close();
    return autotest;
}

int main() {
    ofstream testResultFile;
    string pathFile = __FILE__;
    size_t found = pathFile.find("\\Lab12\\prj");

    // ������������ ������� ������ ��� ���������� �����
    cout << fixed << setprecision(2);

    if (found == string::npos) {
        testResultFile.open("TestResult.txt");
        if (!testResultFile.is_open()) return -1;

        // ��������� ������� ������� ��������� �����, � �� ������ "��"
        // �������� ���� � '\a'
        testResultFile << "���������� ������ ������� ��������� ����������� ������ ��������!" << endl;
        testResultFile << "���� �����, �������� ������ � �������� ��������: ...\\Lab12\\prj\\teacher\\main.cpp" << endl;
    } else {
        testResultFile.open("..\\..\\TestSuite\\TestResult.txt");
        if (!testResultFile.is_open()) {
            cerr << "�������: �� ������� ������� ���� ���������� ���������� TestResult.txt" << endl;
            return -1;
        }

        vector<TestSuite> autotest = readCSVFile("..\\..\\TestSuite\\TS.txt");

        if (autotest.empty()) {
            testResultFile << "���� ����� ��� ����������. �������� ���� TS.txt" << endl;
        }

        for (int i = 0; i < autotest.size(); i++) {
            float result = 0.0f;
            bool test_passed = false;
            string status_message = "";

            try {
                // ��������� ��'���� ����� ClassLab12_Selikhova � ����������� � ��������� ������
                ClassLab12_Selikhova table(autotest[i].shape, autotest[i].param1, autotest[i].param2);
                result = table.calculateArea();

                // ��������� � ����������� (��� ��������� �����)
                // ������������� ��������� ������ ��� ��������� float
                float tolerance = 0.01f; // ������, ���������, 0.01
                if (abs(autotest[i].expResult - result) < tolerance) {
                    test_passed = true;
                    status_message = "passed";
                } else {
                    status_message = "failed";
                }

            } catch (const invalid_argument& e) {
                status_message = "failed (������� ��������: " + string(e.what()) + ")";
            } catch (const runtime_error& e) {
                status_message = "failed (������� ���������: " + string(e.what()) + ")";
            } catch (const exception& e) {
                status_message = "failed (������� �������: " + string(e.what()) + ")";
            }

            testResultFile << "test �" << i + 1 << " -> " << status_message << endl;
            if (!test_passed && status_message.find("passed") == string::npos) { // ���� ���� �� ������� ��� ������� �������
                testResultFile << "  ��������� -> " << autotest[i].expResult << endl;
                testResultFile << "  �������� -> " << result << endl;
                testResultFile << "  ���������: �����='" << autotest[i].shape
                               << "', P1=" << autotest[i].param1
                               << ", P2=" << autotest[i].param2 << endl;
            }
            testResultFile << endl;
        }
    }

    testResultFile.close();
    system("pause"); // �������� ��� �������� ������� � Windows
    return 0;
}