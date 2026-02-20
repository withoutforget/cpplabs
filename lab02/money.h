#pragma once
#include "money_data.h"

class Money {
public:
    Money(long rubles, unsigned char penny = 0);
    Money();
    Money(const Money& rhs);
    Money(Money&& rhs) noexcept;

    Money& operator=(const Money& rhs);
    Money& operator=(Money&& rhs) noexcept;
    Money operator+(const Money& rhs) const;
    Money operator-(const Money& rhs) const;
    Money operator/(const Money& rhs) const;

    bool operator>(const Money& rhs) const noexcept;
    bool operator==(const Money& rhs) const noexcept;
    bool operator<(const Money& rhs) const noexcept;

    void initialize(long rubles, unsigned char penny);
    void initialize();
    void print() const;

private:
    MoneyData m_data;
};
