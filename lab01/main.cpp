#include <functional>
#include <iostream>
#include <stdexcept>

using math_f = std::function<double(double)>;

constexpr double g_derivative_eps = 0.00001;
constexpr double g_newton_method_eps = 0.001;
constexpr size_t g_newton_method_max_iter = 1'000;

math_f derivative(math_f func) {
    return [func](double x) -> double {
        return (func(x + g_derivative_eps) - func(x)) /
               (g_derivative_eps);
    };
}

double intersection(math_f f) {
    auto df = derivative(f);
    double x0 = 0;

    double curr = x0;
    for (size_t i = 1; i < g_newton_method_max_iter; i++) {
        auto fval = f(curr);
        auto dfval = df(curr);
        auto next = curr - fval / dfval;
        if (std::abs(f(next)) < g_newton_method_eps)
            return next;
        if (std::abs(next - curr) < g_newton_method_eps)
            break;
    }
    throw std::runtime_error{"Cannot get enough accuracy"};
}

double intersection(math_f f, math_f g) {
    auto h = [f, g](double x) -> double {
        return f(x) - g(x);
    };
    return intersection(h);
}

double f(double x) {
    return - x * x + 6.0 * x - 5.0;
}

double g(double x) {
    return - x / 3.0 - 1.0 / 2.0;
}

int main() {
    std::cout << intersection(f, g) << std::endl;
}