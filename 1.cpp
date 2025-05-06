#include <iostream>
#include <map>

using namespace std;

// ������� ��� ���������� ������������� �������� � ������
void addMaxToBegin(multimap<double, double>& mm) {
    if (mm.empty()) return;

    // ������� ������������ ���� (��������� ������� � multimap)
    auto max_it = --mm.end();
    double max_key = max_it->first;
    double max_value = max_it->second;

    // ������� ����� ���� ������ ������������, ����� ������� ���� ������
    double new_key = mm.begin()->first - 1.0;
    mm.insert(make_pair(new_key, max_value));
}

// ������� ��� �������� ������������ ��������
void removeMin(multimap<double, double>& mm) {
    if (!mm.empty()) {
        mm.erase(mm.begin());
    }
}

// ������� ��� ���������� �������� ��������������� � ���������
void addAverage(multimap<double, double>& mm) {
    if (mm.empty()) return;

    // ������� ����� ���� ��������
    double sum = 0.0;
    for (auto& pair : mm) {
        sum += pair.second;
    }

    // ��������� �������
    double avg = sum / mm.size();

    // ��������� ��������
    multimap<double, double> temp;
    for (auto& pair : mm) {
        temp.insert(make_pair(pair.first, pair.second + avg));
    }

    mm = temp;
}

int main() {
    multimap<double, double> myMap;

    // ��������� ���������
    myMap.insert(make_pair(1.1, 2.5));
    myMap.insert(make_pair(3.3, 4.0));
    myMap.insert(make_pair(5.5, 6.5));

    // ��������� �������
    addMaxToBegin(myMap);
    removeMin(myMap);
    addAverage(myMap);

    // ������� ���������
    cout << "���������:\n";
    for (auto& pair : myMap) {
        cout << "����: " << pair.first << ", ��������: " << pair.second << endl;
    }

    return 0;
}