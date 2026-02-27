#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>

template <typename T>
std::vector<T> concat(const std::vector<T>& lhs,
                      const std::vector<T>& rhs) {
    std::vector<T> result;
    result.reserve(lhs.size() + rhs.size());

    auto it = std::copy(lhs.begin(), lhs.end(),
                        std::back_inserter(result));
    std::copy(rhs.begin(), rhs.end(),
              std::back_inserter(result));
    std::sort(result.begin(), result.end());
    return result;
}

template <typename T>
std::list<T> concat(const std::list<T>& lhs,
                    const std::list<T>& rhs) {
    std::list<T> result;

    auto it = std::copy(lhs.begin(), lhs.end(),
                        std::back_inserter(result));
    std::copy(rhs.begin(), rhs.end(),
              std::back_inserter(result));
    result.sort();
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

int main() {
    std::vector<int> a{1, 2, 3}, b{0, 4, 5};
    std::list<int> c{1, 2, 3}, d{0, 4, 5};
    std::map<int, int> x{{1, 1}, {2, 2}, {3, 3}},
        y{{0, 0}, {3, 3}, {4, 4}};
    std::multiset<int> m1{1, 1, 2, 3}, m2{2, 2, 2, 3, 3, 5};

    for (auto&& v : concat(a, b))
        std::cout << v << ", ";
    std::cout << std::endl;

    for (auto&& v : concat(c, d))
        std::cout << v << ", ";
    std::cout << std::endl;

    for (auto&& [k, v] : concat(x, y))
        std::cout << k << "=" << v << "; ";
    std::cout << std::endl;

    for (auto&& v : concat(m1, m2))
        std::cout << v << ", ";
    std::cout << std::endl;
}