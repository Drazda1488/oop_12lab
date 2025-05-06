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
        // ������� ��� ��������� ��������
        data.erase(elem);
    }

    // �������� ����� ������������� ��������
    void addMaxToBegin() {
        if (data.empty()) return;
        T maxElem = *data.rbegin(); // �������� ������������ �������
        data.insert(maxElem);
    }

    // ������� ����������� �������
    void removeMin() {
        if (!data.empty()) {
            data.erase(data.begin());
        }
    }

    // �������� ������� �������������� � ������� ��������
    void addAverageToEach() {
        if (data.empty()) return;

        // ������� �����
        T sum = T();
        for (const T& elem : data) {
            sum = sum + elem; // ��������� ���������� operator+ ��� ���� T
        }

        // ��������� �������
        double avg = static_cast<double>(sum) / data.size();

        // ��������� ��������
        std::multiset<T> temp;
        for (const T& elem : data) {
            temp.insert(elem + avg); // ��������� ���������� operator+ ��� T + double
        }

        data.swap(temp);
    }

    // ����� ���������
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