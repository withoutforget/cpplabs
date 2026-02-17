#pragma once
#include "vector_attrs.h"

class Vector {
public:
    Vector(double x = 0, double y = 0, double z = 0);
    explicit Vector(const VectorAttrs& attrs);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;

    static Vector fromInput();

    void init(double x, double y, double z);
    void init();

    void print() const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(double scalar) const;
    double operator*(const Vector& other) const;

    friend Vector operator*(double scalar, const Vector& v);

private:
    VectorAttrs m_attrs;
};