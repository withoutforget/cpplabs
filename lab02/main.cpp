#include "money.h"

int main() {
    Money a{10, 20};
    Money b{5};
    Money c{a};
    Money d{std::move(b)};
    Money e;

    a.print();
    c.print();
    d.print();
    e.print();

    a.initialize(10, 20);
    c.initialize(2, 30);

    Money sum = a + c;
    sum.print();

    Money diff = a - c;
    diff.print();

    Money quot = a / c;
    quot.print();

    return 0;
}