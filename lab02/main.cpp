#include "vector.h"

int main() {
    Vector v1;
    Vector v2(1.0, 2.0, 3.0);
    Vector v3(v2);
    Vector v4(std::move(v3));
    Vector v5(VectorAttrs(4, 5, 6));
    Vector v6 = Vector::fromInput();

    v1.init(7.0, 8.0, 9.0);

    v1.print();
    v2.print();
    v4.print();
    v5.print();
    v6.print();

    (v1 + v2).print();
    (v1 - v2).print();
    (v2 * 3.0).print();
    (3.0 * v2).print();

    Vector dot_result = v1;
    dot_result.init(v1 * v2, 0, 0);
}