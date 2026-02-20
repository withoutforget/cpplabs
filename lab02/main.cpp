#include <iomanip>
#include <iostream>

class Money {
public:
    Money(long rubles, unsigned char penny)
        : rubles_(rubles), penny_(penny) {}
    Money(long penny)
        : rubles_(penny / 100), penny_(penny % 100) {}
    Money() : rubles_(0), penny_(0) {}
    Money(const Money& rhs)
        : rubles_(rhs.rubles_), penny_(rhs.penny_) {}
    Money(Money&& rhs) noexcept {
        std::swap(rubles_, rhs.rubles_);
        std::swap(penny_, rhs.penny_);
    }

    Money& operator=(const Money& rhs) {
        Money tmp{rhs};
        std::swap(*this, tmp);
        return *this;
    }

    Money& operator=(Money&& rhs) noexcept {
        std::swap(rubles_, rhs.rubles_);
        std::swap(penny_, rhs.penny_);
        return *this;
    }

    Money& operator+(const Money& rhs) {
        rubles_ += rhs.rubles_;
        penny_ += rhs.penny_;
        rubles_ += penny_ / 100;
        penny_ %= 100;
        return *this;
    }

    long operator/(const Money& rhs) {
        long a = get_total_penny();
        long b = rhs.get_total_penny();
        return a / b;
    }

    Money& operator-(const Money& rhs) {
        if (*this < rhs)
            throw std::runtime_error{
                "Cannot get negative money"};
        rubles_ -= rhs.rubles_;
        if (penny_ < rhs.penny_) {
            penny_ += 100;
            rubles_ -= 1;
        }
        penny_ -= rhs.penny_;
        return *this;
    }

    bool operator>(const Money& rhs) const noexcept {
        if (rubles_ == rhs.rubles_)
            return penny_ > rhs.penny_;
        return rubles_ > rhs.rubles_;
    }

    bool operator==(const Money& rhs) const noexcept {
        return rubles_ == rhs.rubles_ &&
               penny_ == rhs.penny_;
    }

    bool operator<(const Money& rhs) const noexcept {
        return *this != rhs && !(*this > rhs);
    }

    friend std::ostream& operator<<(std::ostream& ss,
                                    const Money& m);
    friend std::istream& operator>>(std::istream& ss,
                                    Money& m);

private:
    long rubles_;
    unsigned char penny_;

    long get_total_penny() const noexcept {
        return rubles_ * 100 + static_cast<long>(penny_);
    }
};

std::ostream& operator<<(std::ostream& ss, const Money& m) {
    ss << m.rubles_ << "," << std::fixed
       << std::setfill('0') << std::setw(2)
       << static_cast<long>(m.penny_) << "rub";
    return ss;
}
std::istream& operator>>(std::istream& ss, Money& m) {
    long tmp = 0;
    ss >> m.rubles_ >> tmp;
    m.penny_ = static_cast<unsigned char>(tmp);
    return ss;
}


int main() {
    Money a{10, 20};
    Money b{2, 30};
    std::cout << (a / b) << std::endl;
}