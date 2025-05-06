#include <iostream>
#include <set>

template<typename T>
class MySet {
private:
    std::multiset<T> data;

public:
    void add(const T& elem) {
        data.insert(elem);
    }

    void remove(const T& elem) {
        // Удаляет все вхождения элемента
        data.erase(elem);
    }

    // Добавить копию максимального элемента
    void addMaxToBegin() {
        if (data.empty()) return;
        T maxElem = *data.rbegin(); // Получаем максимальный элемент
        data.insert(maxElem);
    }

    // Удалить минимальный элемент
    void removeMin() {
        if (!data.empty()) {
            data.erase(data.begin());
        }
    }

    // Добавить среднее арифметическое к каждому элементу
    void addAverageToEach() {
        if (data.empty()) return;

        // Считаем сумму
        T sum = T();
        for (const T& elem : data) {
            sum = sum + elem; // Требуется перегрузка operator+ для типа T
        }

        // Вычисляем среднее
        double avg = static_cast<double>(sum) / data.size();

        // Обновляем элементы
        std::multiset<T> temp;
        for (const T& elem : data) {
            temp.insert(elem + avg); // Требуется перегрузка operator+ для T + double
        }

        data.swap(temp);
    }

    // Вывод элементов
    void print() const {
        for (const T& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MySet<double> s;
    s.add(2.5);
    s.add(4.0);
    s.add(6.5);

    s.addMaxToBegin();
    s.removeMin();
    s.addAverageToEach();

    std::cout << "Result: ";
    s.print();

    return 0;
}