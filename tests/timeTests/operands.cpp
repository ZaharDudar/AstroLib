#include <gtest/gtest.h>
#include "astrolib/time/time.hpp"

TEST(time, first){
// Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}