#pragma once
#include <iostream>

class VectorAttrs {
public:
    VectorAttrs(double x = 0, double y = 0, double z = 0);

    double x() const noexcept;
    double y() const noexcept;
    double z() const noexcept;

    friend std::ostream& operator<<(std::ostream& os,
                                    const VectorAttrs& a);
    friend std::istream& operator>>(std::istream& is,
                                    VectorAttrs& a);

private:
    double m_x;
    double m_y;
    double m_z;
};