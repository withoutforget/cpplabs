#include <functional>
#include <iostream>
#include <stdexcept>

using math_f = std::function<double(double)>;

constexpr double g_derivative_eps = 0.00001;
constexpr double g_newton_method_eps = 0.001;
constexpr size_t g_newton_method_max_iter = 1'000;
constexpr size_t g_integration_steps = 10'000;

math_f derivative(math_f func) {
    return [func](double x) -> double {
        return (func(x + g_derivative_eps) - func(x - g_derivative_eps)) /
               (2 * g_derivative_eps);
    };
}

double intersection(math_f f, double x0 = .0) {
    auto df = derivative(f);

    double curr = x0;
    for (size_t i = 1; i < g_newton_method_max_iter; i++) {
        auto fval = f(curr);
        auto dfval = df(curr);
        auto next = curr - fval / dfval;
        if (std::abs(f(next)) < g_newton_method_eps)
            return next;
        if (std::abs(next - curr) < g_newton_method_eps)
            break;
        curr = next;
    }
    throw std::runtime_error{"Cannot get enough accuracy"};
}

double intersection(math_f f, math_f g, double x0 = .0) {
    auto h = [f, g](double x) -> double {
        return f(x) - g(x);
    };
    return intersection(h);
}


double integrate(math_f f, double a, double b) {
    double step = (b - a) / g_integration_steps;
    double sum = 0.0;
    for (size_t i = 0; i < g_integration_steps; i++) {
        double x = a + step * i;
        sum += f(x + step / 2.0);
    }
    return sum * step;
}

double f(double x) {
    return - x * x + 6.0 * x - 5.0;
}

double g(double x) {
    return - x / 3.0 - 1.0 / 2.0;
}

int main() {
    double a = intersection(f);
    double b = intersection(f, g);
    if (b < a)
        std::swap(a, b);
    auto s = integrate([](double x) -> double { return f(x) - g(x); }, a, b);
    std::cout << s << std::endl;
}