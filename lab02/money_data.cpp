#include "money_data.h"

#include <iomanip>

MoneyData::MoneyData() : m_rubles(0), m_penny(0) {}

MoneyData::MoneyData(long rubles, unsigned char penny)
    : m_rubles(rubles), m_penny(penny) {}

MoneyData::MoneyData(long penny)
    : m_rubles(penny / 100), m_penny(penny % 100) {}

MoneyData::MoneyData(const MoneyData& rhs)
    : m_rubles(rhs.m_rubles), m_penny(rhs.m_penny) {}

MoneyData::MoneyData(MoneyData&& rhs) noexcept
    : m_rubles(0), m_penny(0) {
    std::swap(m_rubles, rhs.m_rubles);
    std::swap(m_penny, rhs.m_penny);
}

MoneyData& MoneyData::operator=(const MoneyData& rhs) {
    MoneyData tmp{rhs};
    std::swap(*this, tmp);
    return *this;
}

MoneyData& MoneyData::operator=(MoneyData&& rhs) noexcept {
    std::swap(m_rubles, rhs.m_rubles);
    std::swap(m_penny, rhs.m_penny);
    return *this;
}

MoneyData MoneyData::clone() const {
    return MoneyData{*this};
}

MoneyData& MoneyData::add(const MoneyData& rhs) {
    m_rubles += rhs.m_rubles;
    m_penny += rhs.m_penny;
    m_rubles += m_penny / 100;
    m_penny %= 100;
    return *this;
}

MoneyData& MoneyData::sub(const MoneyData& rhs) {
    m_rubles -= rhs.m_rubles;
    if (m_penny < rhs.m_penny) {
        m_penny += 100;
        m_rubles -= 1;
    }
    m_penny -= rhs.m_penny;
    return *this;
}

long MoneyData::div(const MoneyData& rhs) const {
    long a = m_rubles * 100 + static_cast<long>(m_penny);
    long b =
        rhs.m_rubles * 100 + static_cast<long>(rhs.m_penny);
    return a / b;
}

int MoneyData::cmp(const MoneyData& rhs) const {
    if (m_rubles != rhs.m_rubles)
        return m_rubles > rhs.m_rubles ? 1 : -1;
    if (m_penny != rhs.m_penny)
        return m_penny > rhs.m_penny ? 1 : -1;
    return 0;
}

long MoneyData::get_rubles() const noexcept {
    return m_rubles;
}
unsigned char MoneyData::get_penny() const noexcept {
    return m_penny;
}

std::ostream& operator<<(std::ostream& ss,
                         const MoneyData& m) {
    ss << m.m_rubles << "," << std::fixed
       << std::setfill('0') << std::setw(2)
       << static_cast<long>(m.m_penny) << "rub";
    return ss;
}
std::istream& operator>>(std::istream& ss, MoneyData& m) {
    long tmp = 0;
    ss >> m.m_rubles >> tmp;
    m.m_penny = static_cast<unsigned char>(tmp);
    return ss;
}