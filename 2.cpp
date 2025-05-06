#include <iostream>
#include <map>

class Money {
private:
    double amount;
public:
    Money(double amt) : amount(amt) {}
    bool operator<(const Money& other) const { return amount < other.amount; }
    Money operator+(const Money& other) const { return Money(amount + other.amount); }
    double getAmount() const { return amount; }
};

// Исправлено: добавлено std::
std::ostream& operator<<(std::ostream& os, const Money& m) {
    os << m.getAmount();
    return os;
}

using MoneyMultiMap = std::multimap<double, Money>;

void addMaxToBegin(MoneyMultiMap& mm) {
    if (mm.empty()) return;
    auto max_it = --mm.end();
    double new_key = mm.begin()->first - 1.0;
    mm.insert(std::make_pair(new_key, max_it->second));
}

void removeMin(MoneyMultiMap& mm) {
    if (!mm.empty()) mm.erase(mm.begin());
}

void addAverage(MoneyMultiMap& mm) {
    if (mm.empty()) return;

    double sum = 0.0;
    for (const auto& pair : mm) {
        sum += pair.second.getAmount();
    }
    double avg = sum / mm.size();

    MoneyMultiMap temp;
    for (const auto& pair : mm) {
        temp.insert(std::make_pair(pair.first, Money(pair.second.getAmount() + avg)));
    }
    mm = temp;
}

int main() {
    MoneyMultiMap moneyMap;

    moneyMap.insert(std::make_pair(1.1, Money(2.5)));
    moneyMap.insert(std::make_pair(3.3, Money(4.0)));
    moneyMap.insert(std::make_pair(5.5, Money(6.5)));

    addMaxToBegin(moneyMap);
    removeMin(moneyMap);
    addAverage(moneyMap);

    std::cout << "Результат:\n";
    for (const auto& pair : moneyMap) {
        std::cout << "Ключ: " << pair.first << ", Значение: " << pair.second << std::endl;
    }

    return 0;
}