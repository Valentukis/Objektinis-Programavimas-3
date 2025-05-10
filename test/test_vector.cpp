#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "../vector/Vector.hpp"
#include <vector>

TEST_CASE("Vector default constructor creates empty vector") {
    Vector<int> v;
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("Vector push_back adds elements correctly") {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 20);
    REQUIRE(v[2] == 30);
}

TEST_CASE("Vector copy constructor works") {
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);

    Vector<int> b = a;
    REQUIRE(b.size() == 2);
    REQUIRE(b[0] == 1);
    REQUIRE(b[1] == 2);
}

TEST_CASE("Vector move constructor works") {
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);

    Vector<int> b = std::move(a);
    REQUIRE(b.size() == 2);
    REQUIRE(b[0] == 1);
    REQUIRE(b[1] == 2);
}

TEST_CASE("Vector at() throws out_of_range") {
    Vector<int> v(2, 5);
    REQUIRE_THROWS_AS(v.at(2), std::out_of_range);
}
