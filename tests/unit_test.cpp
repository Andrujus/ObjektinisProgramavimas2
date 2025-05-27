#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "../student.h"

TEST_CASE("Rule of Five: Constructor") {
    Student s("Jonas", "Jonaitis", {8, 9, 10}, 7);
    REQUIRE(s.getVardas() == "Jonas");
    REQUIRE(s.getPavarde() == "Jonaitis");
    REQUIRE(s.getNamuDarbai() == std::vector<int>({8, 9, 10}));
    REQUIRE(s.getEgz() == 7);
}

TEST_CASE("Rule of Five: Copy Constructor") {
    Student original("Jonas", "Jonaitis", {8, 9, 10}, 7);
    Student copy(original);

    REQUIRE(copy.getVardas() == original.getVardas());
    REQUIRE(copy.getPavarde() == original.getPavarde());
    REQUIRE(copy.getNamuDarbai() == original.getNamuDarbai());
    REQUIRE(copy.getEgz() == original.getEgz());
}

TEST_CASE("Rule of Five: Copy Assignment") {
    Student s1("Jonas", "Jonaitis", {10, 10}, 10);
    Student s2;
    s2 = s1;

    REQUIRE(s2.getVardas() == "Jonas");
    REQUIRE(s2.getNamuDarbai() == s1.getNamuDarbai());
}

TEST_CASE("Rule of Five: Move Constructor") {
    Student original("Petras", "Petraitis", {6, 7, 8}, 9);
    Student moved(std::move(original));

    REQUIRE(moved.getVardas() == "Petras");
    REQUIRE(moved.getPavarde() == "Petraitis");
    REQUIRE(moved.getNamuDarbai() == std::vector<int>({6, 7, 8}));
    REQUIRE(moved.getEgz() == 9);
}

TEST_CASE("Rule of Five: Move Assignment") {
    Student s1("Aidas", "Aidaitis", {7, 8, 9}, 10);
    Student s2;
    s2 = std::move(s1);

    REQUIRE(s2.getVardas() == "Aidas");
    REQUIRE(s2.getPavarde() == "1234");
    REQUIRE(s2.getNamuDarbai() == std::vector<int>({7, 8, 9}));
    REQUIRE(s2.getEgz() == 10);
}

