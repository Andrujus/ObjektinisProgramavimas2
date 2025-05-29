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

    Vector<int> b = a; // copy

    REQUIRE(b.size() == 2);
    REQUIRE(b[0] == 5);
    REQUIRE(b[1] == 15);
}

TEST_CASE("Vector move constructor", "[Vector]") {
    Vector<int> a;
    a.push_back(9);
    a.push_back(8);

    Vector<int> b = std::move(a); // move

    REQUIRE(b.size() == 2);
    REQUIRE(b[0] == 9);
    REQUIRE(b[1] == 8);
}
