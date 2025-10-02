//
// Created by zahar on 25.09.2025.
//

#include "Astrolib/Time/Converters/TimeConverter.hpp"
#include "Astrolib/Time/Converters/DutContainer.hpp"
#include <gtest/gtest.h>
namespace testTimes {

}


class ConverterTest : public testing::Test {
public:
    const Time<Scale::UTC> utcTime{2459215, 0.899199259166127};
    const Time<Scale::TAI> taiTime{2459215, 0.899627499906868};
    const Time<Scale::UT1> ut1Time{2459215, 0.899197231865367};
    const Time<Scale::TT>  ttTime{2459215, 0.899999999906868};
    const Time<Scale::TDB>  tdbTime{2459215, 0.89999999923088};
    static constexpr auto epsilon = std::numeric_limits<double>::epsilon() * 2459215;
    BasicDutContainer dutContainer{{-0.175371, -0.1748394},59215};
    TimeConverter<BasicDutContainer> convertor{dutContainer};
};

/******************** UTC to _********************/
TEST_F(ConverterTest, UTC2TAI) {
    auto from = utcTime;
    auto to = taiTime;
    auto result = convertor.convert<Scale::TAI>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, UTC2UT1) {
    auto from = utcTime;
    auto to = ut1Time;
    auto result = convertor.convert<Scale::UT1>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}

TEST_F(ConverterTest, UTC2TT) {
    auto from = utcTime;
    auto to = ttTime;
    auto result = convertor.convert<Scale::TT>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, UTC2TDB) {
    auto from = utcTime;
    auto to = tdbTime;
    auto result = convertor.convert<Scale::TDB>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}



/****************** TAI to _ ********************/
TEST_F(ConverterTest, TAI2UTC) {
    auto from = taiTime;
    auto to = utcTime;
    auto result = convertor.convert<Scale::UTC>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, TAI2UT1) {
    auto from = taiTime;
    auto to = ut1Time;
    auto result = convertor.convert<Scale::UT1>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, TAI2TT) {
    auto from = taiTime;
    auto to = ttTime;
    auto result = convertor.convert<Scale::TT>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, TAI2TDB) {
    auto from = taiTime;
    auto to = tdbTime;
    auto result = convertor.convert<Scale::TDB>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}


/******************* UT1 to _ ****************/
TEST_F(ConverterTest, UT12UTC) {
    auto from = ut1Time;
    auto to = utcTime;
    auto result = convertor.convert<Scale::UTC>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, UT12TAI) {
    auto from = ut1Time;
    auto to = taiTime;
    auto result = convertor.convert<Scale::TAI>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, UT12TT) {
    auto from = ut1Time;
    auto to = ttTime;
    auto result = convertor.convert<Scale::TT>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, UT12TDB) {
    auto from = ut1Time;
    auto to = tdbTime;
    auto result = convertor.convert<Scale::TDB>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}


/****************** TT to _******************/
TEST_F(ConverterTest, TT2UTC) {
    auto from = ttTime;
    auto to = utcTime;
    auto result = convertor.convert<Scale::UTC>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, TT2TAI) {
    auto from = ttTime;
    auto to = taiTime;
    auto result = convertor.convert<Scale::TAI>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, TT2UT1) {
    auto from = ttTime;
    auto to = ut1Time;
    auto result = convertor.convert<Scale::UT1>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, TT2TDB) {
    auto from = ttTime;
    auto to = tdbTime;
    auto result = convertor.convert<Scale::TDB>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}


/************ TDB to _ *********************/
TEST_F(ConverterTest, TDB2UTC) {
    auto from = tdbTime;
    auto to = utcTime;
    auto result = convertor.convert<Scale::UTC>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, TDB2TAI) {
    auto from = tdbTime;
    auto to = taiTime;
    auto result = convertor.convert<Scale::TAI>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, TDB2UT1) {
    auto from = tdbTime;
    auto to = ut1Time;
    auto result = convertor.convert<Scale::UT1>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
TEST_F(ConverterTest, TDB2TT) {
    auto from = tdbTime;
    auto to = ttTime;
    auto result = convertor.convert<Scale::TT>(from);
    EXPECT_NEAR(result.jdInt(), to.jdInt(), epsilon);
    EXPECT_NEAR(result.jdFrac(), to.jdFrac(), epsilon);
}
