#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/vector.hpp"

TEST_CASE("Vector push_back and access", "[Vector]") {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 20);
    REQUIRE(v[2] == 30);
}

TEST_CASE("Vector copy constructor", "[Vector]") {
    Vector<int> a;
    a.push_back(5);
    a.push_back(15);
    Vector<int> b = a;
    REQUIRE(b.size() == 2);
    REQUIRE(b[0] == 5);
    REQUIRE(b[1] == 15);
}

TEST_CASE("Vector move constructor", "[Vector]") {
    Vector<int> a;
    a.push_back(9);
    a.push_back(8);
    Vector<int> b = std::move(a);
    REQUIRE(b.size() == 2);
    REQUIRE(b[0] == 9);
    REQUIRE(b[1] == 8);
}

TEST_CASE("Vector copy assignment", "[Vector]") {
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);
    Vector<int> b;
    b = a;
    REQUIRE(b.size() == 2);
    REQUIRE(b[0] == 1);
    REQUIRE(b[1] == 2);
}

TEST_CASE("Vector move assignment", "[Vector]") {
    Vector<int> a;
    a.push_back(7);
    a.push_back(3);
    Vector<int> b;
    b = std::move(a);
    REQUIRE(b.size() == 2);
    REQUIRE(b[0] == 7);
    REQUIRE(b[1] == 3);
}

TEST_CASE("Vector pop_back", "[Vector]") {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.pop_back();
    REQUIRE(v.size() == 1);
    REQUIRE(v[0] == 10);
}

TEST_CASE("Vector clear", "[Vector]") {
    Vector<int> v = {1, 2, 3, 4, 5};
    v.clear();
    REQUIRE(v.size() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("Vector at() throws", "[Vector]") {
    Vector<int> v;
    v.push_back(100);
    REQUIRE_THROWS_AS(v.at(1), std::out_of_range);
}

TEST_CASE("Vector front and back", "[Vector]") {
    Vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    REQUIRE(v.front() == 4);
    REQUIRE(v.back() == 6);
}

TEST_CASE("Vector initializer list constructor", "[Vector]") {
    Vector<int> v = {7, 8, 9};
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 7);
    REQUIRE(v[1] == 8);
    REQUIRE(v[2] == 9);
}

TEST_CASE("Vector reserve and capacity", "[Vector]") {
    Vector<int> v;
    v.reserve(100);
    REQUIRE(v.capacity() >= 100);
    for (int i = 0; i < 100; ++i) v.push_back(i);
    REQUIRE(v.size() == 100);
    REQUIRE(v[99] == 99);
}

TEST_CASE("Vector empty", "[Vector]") {
    Vector<int> v;
    REQUIRE(v.empty());
    v.push_back(1);
    REQUIRE_FALSE(v.empty());
}
