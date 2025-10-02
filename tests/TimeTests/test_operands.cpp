#include <gtest/gtest.h>
#include "Astrolib/Time/Time.hpp"

TEST(Time, Initializers){
    Time<Scale::UTC> testedTime1(1, 0.5);
    EXPECT_NEAR(testedTime1.jdInt(), 1, std::numeric_limits<double>::min());
    EXPECT_NEAR(testedTime1.jdFrac(), 0.5, std::numeric_limits<double>::min());

    Time<Scale::UTC> testedTime2(1.5);
    EXPECT_NEAR(testedTime2.jdInt(), 1, std::numeric_limits<double>::min());
    EXPECT_NEAR(testedTime2.jdFrac(), 0.5, std::numeric_limits<double>::min());

    Time<Scale::UTC> testedTime3(1.2,0.3);
    EXPECT_NEAR(testedTime3.jdInt(), 1, std::numeric_limits<double>::min());
    EXPECT_NEAR(testedTime3.jdFrac(), 0.5, std::numeric_limits<double>::min());
}

TEST(Time, OperationsSeconds) {
    constexpr auto epsilon = std::numeric_limits<double>::epsilon();

    Time<Scale::UTC> testedTime1(1.5l);
    Time<Scale::UTC> testedTime2(1.2l);
    auto deltaTime = testedTime1 - testedTime2;
    EXPECT_NEAR(deltaTime, 0.3, epsilon);

    Time<Scale::UTC> testedTime3(1.5);
    Time<Scale::UTC> testedTime4(0.6);
    deltaTime = testedTime3 - testedTime4;
    EXPECT_NEAR(deltaTime, 0.9, epsilon);
}

TEST(Time, OperationsDays) {
    constexpr auto SECONDS_PER_DAY = Time<Scale::UTC>::SECONDS_PER_DAY;
    constexpr auto epsilon = std::numeric_limits<double>::epsilon();

    Time<Scale::UTC> testedTime1(1.5);
    auto newTime = testedTime1 + SECONDS_PER_DAY * 0.5;
    EXPECT_NEAR(newTime.jdInt(), 2, epsilon);
    EXPECT_NEAR(newTime.jdFrac(), 0, epsilon);

    newTime = testedTime1 + SECONDS_PER_DAY * 0.4;
    EXPECT_NEAR(newTime.jdInt(), 1, epsilon);
    EXPECT_NEAR(newTime.jdFrac(), 0.9, epsilon);

    newTime = testedTime1 - SECONDS_PER_DAY * 0.9;
    EXPECT_NEAR(newTime.jdInt(), 0, epsilon);
    EXPECT_NEAR(newTime.jdFrac(), 0.6, epsilon);

    newTime = testedTime1 - SECONDS_PER_DAY * 0.4;
    EXPECT_NEAR(newTime.jdInt(), 1, epsilon);
    EXPECT_NEAR(newTime.jdFrac(), 0.1, epsilon);
}
