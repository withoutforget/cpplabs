#include "money.h"

Money::Money(long rubles, unsigned char penny)
    : m_data(rubles, penny) {}
Money::Money() { initialize(); }

void Money::initialize(long rubles, unsigned char penny) {
    m_data = MoneyData{rubles, penny};
}

Money::Money(const Money& rhs) : m_data(rhs.m_data) {}

Money::Money(Money&& rhs) noexcept : m_data() {
    std::swap(m_data, rhs.m_data);
}

Money& Money::operator=(const Money& rhs) {
    Money tmp{rhs};
    std::swap(*this, tmp);
    return *this;
}

Money& Money::operator=(Money&& rhs) noexcept {
    std::swap(m_data, rhs.m_data);
    return *this;
}

Money Money::operator+(const Money& rhs) const {
    MoneyData tmp = m_data.clone();
    tmp.add(rhs.m_data);
    return Money{tmp.get_rubles(), tmp.get_penny()};
}

Money Money::operator-(const Money& rhs) const {
    MoneyData tmp = m_data.clone();
    tmp.sub(rhs.m_data);
    return Money{tmp.get_rubles(), tmp.get_penny()};
}

Money Money::operator/(const Money& rhs) const {
    MoneyData tmp = m_data.clone();
    long k = tmp.div(rhs.m_data);
    tmp = MoneyData{
        k * (rhs.m_data.get_rubles() * 100 +
             static_cast<long>(rhs.m_data.get_penny()))};
    return Money{tmp.get_rubles(), tmp.get_penny()};
}

bool Money::operator>(const Money& rhs) const noexcept {
    return m_data.cmp(rhs.m_data) > 0;
}

bool Money::operator==(const Money& rhs) const noexcept {
    return m_data.cmp(rhs.m_data) == 0;
}

bool Money::operator<(const Money& rhs) const noexcept {
    return m_data.cmp(rhs.m_data) < 0;
}

void Money::initialize() {
    MoneyData tmp{0};
    std::cin >> tmp;
    std::swap(m_data, tmp);
}

void Money::print() const { std::cout << m_data << "\n"; }
