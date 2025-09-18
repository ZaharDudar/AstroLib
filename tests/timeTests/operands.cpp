#include <gtest/gtest.h>
#include "astrolib/time/time.hpp"

TEST(Time, Initializers){
    Time testedTime1(2025*365, 0.29);
    EXPECT_NEAR(testedTime1.jdInt(), 2025*365, 1e-10);
    EXPECT_NEAR(testedTime1.jdFrac(), 0.29, 1e-10);

    Time testedTime2(2025 * 365 + 0.29);
    EXPECT_NEAR(testedTime2.jdInt(), 2025*365, 1e-10);
    EXPECT_NEAR(testedTime2.jdFrac(), 0.29, 1e-10);

    Time testedTime3(2025*365+0.1, 0.19);
    EXPECT_NEAR(testedTime3.jdInt(), 2025*365, 1e-10);
    EXPECT_NEAR(testedTime3.jdFrac(), 0.29, 1e-10);
}