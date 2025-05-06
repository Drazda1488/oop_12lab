#include <iostream>
#include <map>

using namespace std;

// Функция для добавления максимального элемента в начало
void addMaxToBegin(multimap<double, double>& mm) {
    if (mm.empty()) return;

    // Находим максимальный ключ (последний элемент в multimap)
    auto max_it = --mm.end();
    double max_key = max_it->first;
    double max_value = max_it->second;

    // Создаем новый ключ меньше минимального, чтобы элемент стал первым
    double new_key = mm.begin()->first - 1.0;
    mm.insert(make_pair(new_key, max_value));
}

// Функция для удаления минимального элемента
void removeMin(multimap<double, double>& mm) {
    if (!mm.empty()) {
        mm.erase(mm.begin());
    }
}

// Функция для добавления среднего арифметического к значениям
void addAverage(multimap<double, double>& mm) {
    if (mm.empty()) return;

    // Считаем сумму всех значений
    double sum = 0.0;
    for (auto& pair : mm) {
        sum += pair.second;
    }

    // Вычисляем среднее
    double avg = sum / mm.size();

    // Обновляем значения
    multimap<double, double> temp;
    for (auto& pair : mm) {
        temp.insert(make_pair(pair.first, pair.second + avg));
    }

    mm = temp;
}

int main() {
    multimap<double, double> myMap;

    // Заполняем контейнер
    myMap.insert(make_pair(1.1, 2.5));
    myMap.insert(make_pair(3.3, 4.0));
    myMap.insert(make_pair(5.5, 6.5));

    // Выполняем задания
    addMaxToBegin(myMap);
    removeMin(myMap);
    addAverage(myMap);

    // Выводим результат
    cout << "Результат:\n";
    for (auto& pair : myMap) {
        cout << "Ключ: " << pair.first << ", Значение: " << pair.second << endl;
    }

    return 0;
}