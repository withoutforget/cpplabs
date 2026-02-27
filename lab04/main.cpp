#include <algorithm>
#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>

static constexpr size_t N = 5'000'000;

template <typename Cont, typename Gen>
void fill_container(Cont& cont, size_t n, Gen gen) {
    std::generate_n(std::inserter(cont, cont.end()), n,
                    gen);
}

template <typename Func, typename... Args>
void benchmark(std::string_view title, Func&& func,
               Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    std::invoke(std::forward<Func>(func),
                std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::setw(10) << title << ": "
              << std::chrono::duration_cast<
                     std::chrono::milliseconds>(end - start)
                     .count()
              << " ms" << std::endl;
}

template <typename T>
std::vector<T> concat(const std::vector<T>& lhs,
                      const std::vector<T>& rhs) {
    std::vector<T> result;
    result.reserve(lhs.size() + rhs.size());
    std::merge(lhs.begin(), lhs.end(), rhs.begin(),
               rhs.end(), std::back_inserter(result));
    return result;
}

template <typename T>
std::list<T> concat(const std::list<T>& lhs,
                    const std::list<T>& rhs) {
    std::list<T> result;
    std::merge(lhs.begin(), lhs.end(), rhs.begin(),
               rhs.end(), std::back_inserter(result));
    return result;
}

template <typename K, typename T>
std::map<K, T> concat(const std::map<K, T>& lhs,
                      const std::map<K, T>& rhs) {
    std::map<K, T> res = lhs;
    res.insert(rhs.begin(), rhs.end());
    return res;
}

template <typename K>
std::multiset<K> concat(const std::multiset<K>& lhs,
                        const std::multiset<K>& rhs) {
    std::multiset<K> res = lhs;
    res.insert(rhs.begin(), rhs.end());
    return res;
}

template <typename K, typename V>
void output(std::string_view title,
            const std::map<K, V>& cont) {
    std::cout << std::setw(12) << title << " | ";
    for (const auto& [k, v] : cont) {
        std::cout << k << "=" << v << ", ";
    }
    std::cout << std::endl;
}

template <typename Cont>
void output(std::string_view title, const Cont& cont) {
    std::cout << std::setw(12) << title << " | ";
    for (const auto& v : cont) {
        std::cout << v << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> a{1, 2, 3}, b{0, 4, 5};
    std::list<int> c{1, 2, 3}, d{0, 4, 5};
    std::map<int, int> x{{1, 1}, {2, 2}, {3, 3}},
        y{{0, 0}, {3, 3}, {4, 4}};
    std::multiset<int> m1{1, 1, 2, 3}, m2{2, 2, 2, 3, 3, 5};

    std::cout << std::endl;
    output("vector 1", a);
    output("vector 2", b);
    output("vector", concat(a, b));

    output("list 1", c);
    output("list 2", d);
    output("list", concat(c, d));

    output("map 1", x);
    output("map 2", y);
    output("map", concat(x, y));

    output("multiset 1", m1);
    output("multiset 2", m2);
    output("multiset", concat(m1, m2));

    std::cout << std::endl;
    std::cout << std::format("----->iters={}\n", N);

    benchmark("vector", []() {
        std::vector<int> v1, v2;
        fill_container(
            v1, N, [n = 0]() mutable { return n += 2; });
        fill_container(
            v2, N, [n = 1]() mutable { return n += 2; });
        auto res = concat(v1, v2);
    });

    benchmark("list", []() {
        std::list<int> l1, l2;
        fill_container(
            l1, N, [n = 0]() mutable { return n += 2; });
        fill_container(
            l2, N, [n = 1]() mutable { return n += 2; });
        auto res = concat(l1, l2);
    });

    benchmark("multiset", []() {
        std::multiset<int> ms1, ms2;
        fill_container(
            ms1, N, [n = 0]() mutable { return n += 2; });
        fill_container(
            ms2, N, [n = 1]() mutable { return n += 2; });
        auto res = concat(ms1, ms2);
    });

    benchmark("map", []() {
        std::map<int, int> mp1, mp2;
        fill_container(
            mp1, N,
            [n = 0]() mutable -> std::pair<int, int> {
                int v = n;
                n += 2;
                return {v, v};
            });
        fill_container(
            mp2, N,
            [n = 1]() mutable -> std::pair<int, int> {
                int v = n;
                n += 2;
                return {v, v};
            });
        auto res = concat(mp1, mp2);
    });
}