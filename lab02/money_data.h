#pragma once
#include <iostream>

class MoneyData {
public:
    MoneyData(long rubles, unsigned char penny);
    MoneyData(long penny);
    MoneyData();
    MoneyData(const MoneyData& rhs);
    MoneyData(MoneyData&& rhs) noexcept;
    MoneyData& operator=(const MoneyData& rhs);
    MoneyData& operator=(MoneyData&& rhs) noexcept;

    MoneyData clone() const;
    MoneyData& add(const MoneyData& rhs);
    MoneyData& sub(const MoneyData& rhs);
    long div(const MoneyData& rhs) const;
    int cmp(const MoneyData& rhs) const;

    long get_rubles() const noexcept;
    unsigned char get_penny() const noexcept;

    friend std::ostream& operator<<(std::ostream&,
                                    const MoneyData&);
    friend std::istream& operator>>(std::istream&,
                                    MoneyData&);

private:
    long m_rubles;
    unsigned char m_penny;
};