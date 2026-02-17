#include "vector_attrs.h"

VectorAttrs::VectorAttrs(double x, double y, double z)
    : m_x(x), m_y(y), m_z(z) {}

double VectorAttrs::x() const noexcept { return m_x; }
double VectorAttrs::y() const noexcept { return m_y; }
double VectorAttrs::z() const noexcept { return m_z; }

std::ostream& operator<<(std::ostream& os,
                         const VectorAttrs& a) {
    os << "(" << a.m_x << ", " << a.m_y << ", " << a.m_z
       << ")";
    return os;
}

std::istream& operator>>(std::istream& is, VectorAttrs& a) {
    is >> a.m_x >> a.m_y >> a.m_z;
    return is;
}