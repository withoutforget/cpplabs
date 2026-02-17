#include "vector.h"

#include <iostream>

Vector::Vector(double x, double y, double z)
    : m_attrs(x, y, z) {}

Vector::Vector(const VectorAttrs& attrs) : m_attrs(attrs) {}

Vector::Vector(const Vector& other)
    : m_attrs(other.m_attrs) {}

Vector::Vector(Vector&& other) noexcept {
    std::swap(m_attrs, other.m_attrs);
}

Vector Vector::fromInput() {
    Vector v;
    v.init();
    return v;
}

void Vector::init(double x, double y, double z) {
    m_attrs = VectorAttrs(x, y, z);
}

void Vector::init() {
    std::cout << "Enter x y z: ";
    std::cin >> m_attrs;
}

void Vector::print() const {
    std::cout << "Vector: " << m_attrs << std::endl;
}

Vector Vector::operator+(const Vector& other) const {
    return Vector(m_attrs.x() + other.m_attrs.x(),
                  m_attrs.y() + other.m_attrs.y(),
                  m_attrs.z() + other.m_attrs.z());
}

Vector Vector::operator-(const Vector& other) const {
    return Vector(m_attrs.x() - other.m_attrs.x(),
                  m_attrs.y() - other.m_attrs.y(),
                  m_attrs.z() - other.m_attrs.z());
}

Vector Vector::operator*(double scalar) const {
    return Vector(m_attrs.x() * scalar,
                  m_attrs.y() * scalar,
                  m_attrs.z() * scalar);
}

double Vector::operator*(const Vector& other) const {
    return m_attrs.x() * other.m_attrs.x() +
           m_attrs.y() * other.m_attrs.y() +
           m_attrs.z() * other.m_attrs.z();
}

Vector operator*(double scalar, const Vector& v) {
    return v * scalar;
}