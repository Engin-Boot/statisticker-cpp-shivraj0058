#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <cmath>

TEST_CASE("reports average, minimum and maximum") {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    auto computedStats = Statistics::ComputeStatistics({});
    REQUIRE(std::isnan(computedStats.average)==true);
    REQUIRE(std::isnan(computedStats.max)==true);
    REQUIRE(std::isnan(computedStats.min)==true);
}

TEST_CASE("reports average,minimum and maximum when there are NAN elemetns and non-NAN elements") {
    auto computedStats = Statistics::ComputeStatistics({6.5,9.2,1.4,NAN,4.5,NAN});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 5.4) < epsilon);
    REQUIRE(std::abs(computedStats.max - 9.2) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.4) < epsilon);
}

