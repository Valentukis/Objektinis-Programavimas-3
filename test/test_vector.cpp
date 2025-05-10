#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "../vector/Vector.hpp"
#include <vector>

TEST_CASE("Default constructor creates empty vector") {
    Vector<int> v;
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("Size constructor fills with default value") {
    Vector<int> v(3, 42);
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 42);
    REQUIRE(v[2] == 42);
}

TEST_CASE("Initializer list constructor") {
    Vector<int> v{1, 2, 3};
    REQUIRE(v.size() == 3);
    REQUIRE(v[1] == 2);
}

TEST_CASE("Copy constructor and assignment") {
    Vector<int> a{10, 20};
    Vector<int> b = a;
    REQUIRE(b.size() == 2);
    REQUIRE(b[0] == 10);

    Vector<int> c;
    c = a;
    REQUIRE(c[1] == 20);
}

TEST_CASE("Move constructor and assignment") {
    Vector<int> a{1, 2, 3};
    Vector<int> b = std::move(a);
    REQUIRE(b.size() == 3);

    Vector<int> c;
    c = std::move(b);
    REQUIRE(c[2] == 3);
}

TEST_CASE("Push_back and pop_back") {
    Vector<int> v;
    v.push_back(5);
    v.push_back(10);
    REQUIRE(v.size() == 2);
    v.pop_back();
    REQUIRE(v.size() == 1);
    REQUIRE(v[0] == 5);
}

TEST_CASE("Emplace_back with constructor args") {
    struct Point {
        int x, y;
        Point(int a, int b) : x(a), y(b) {}
        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }
    };
    Vector<Point> v;
    v.emplace_back(1, 2);
    REQUIRE(v[0] == Point(1, 2));
}

TEST_CASE("Resize expands and shrinks vector") {
    Vector<int> v{1, 2};
    v.resize(4, 99);
    REQUIRE(v.size() == 4);
    REQUIRE(v[3] == 99);

    v.resize(2);
    REQUIRE(v.size() == 2);
}

TEST_CASE("Reserve and shrink_to_fit") {
    Vector<int> v;
    v.reserve(100);
    REQUIRE(v.capacity() >= 100);
    v.push_back(1);
    v.shrink_to_fit();
    REQUIRE(v.capacity() == v.size());
}

TEST_CASE("Insert and erase single element") {
    Vector<int> v{1, 2, 4};
    v.insert(v.begin() + 2, 3); // Insert 3 at position 2
    REQUIRE(v[2] == 3);
    v.erase(v.begin() + 2);
    REQUIRE(v[2] == 4);
}

TEST_CASE("Erase range of elements") {
    Vector<int> v{1, 2, 3, 4, 5};
    v.erase(v.begin() + 1, v.begin() + 4); // remove 2,3,4
    REQUIRE(v.size() == 2);
    REQUIRE(v[1] == 5);
}

TEST_CASE("Element access functions") {
    Vector<int> v{7, 8, 9};
    REQUIRE(v.front() == 7);
    REQUIRE(v.back() == 9);
    REQUIRE(v.at(1) == 8);
    REQUIRE_THROWS_AS(v.at(10), std::out_of_range);
}

TEST_CASE("Iterators and reverse iterators") {
    Vector<int> v{1, 2, 3};
    int sum = 0;
    for (auto it = v.begin(); it != v.end(); ++it) sum += *it;
    REQUIRE(sum == 6);

    int reversed = 0;
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit) reversed += *rit;
    REQUIRE(reversed == 6);
}

TEST_CASE("Comparison operators and stream output") {
    Vector<int> a{1, 2, 3};
    Vector<int> b{1, 2, 3};
    Vector<int> c{1, 2};

    REQUIRE(a == b);
    REQUIRE(a != c);

    std::stringstream ss;
    ss << a;
    REQUIRE(ss.str() == "[1, 2, 3]");
}

TEST_CASE("Swap member and non-member") {
    Vector<int> a{1, 2}, b{3, 4};
    a.swap(b);
    REQUIRE(a[0] == 3);
    REQUIRE(b[0] == 1);
    
    swap(a, b);
    REQUIRE(a[0] == 1);
}
