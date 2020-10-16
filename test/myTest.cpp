#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "timeSerie.h"

//SAMPLE TEST FOR GTEST
TEST(GTest, sample_test)
{
    EXPECT_EQ(1, 1);
}

//Class Constructor Tests
TEST(TS_Objects, ts_test_constructor_1)
{
    TimeSerie<double> ts1{};
	TimeSerie<double> ts2{ 1,"s" };
    EXPECT_EQ(ts1.getLength(), ts2.getLength());
    EXPECT_EQ(ts1.getTimeUnit(), ts2.getTimeUnit());
}

TEST(TS_Objects, ts_test_constructor_2)
{
    std::vector<double> data = {-3.0,2.0,-1.0,7.0,3.0};
    std::vector<long int> time = {1,2,3,4,5};
    TimeSerie<double> ts1{data, time, "s"};

    ASSERT_THAT(ts1.getValues(),::testing::ElementsAreArray({-3.0,2.0,-1.0,7.0,3.0}) );
    ASSERT_THAT(ts1.getTimeStamp(),::testing::ElementsAreArray({1,2,3,4,5}) );
}

TEST(TS_Objects, ts_test_constructor_3)
{
    std::vector<double> data(5,0);
    TimeSerie<double> ts1{5};

    ASSERT_THAT(ts1.getValues(),::testing::ElementsAreArray({0,0,0,0,0}) );
    ASSERT_THAT(ts1.getTimeStamp(),::testing::ElementsAreArray({0,1,2,3,4}) );
    ASSERT_EQ(ts1.getLength(), 5);
    ASSERT_EQ(ts1.getTimeUnit(), "s");
}

TEST(TS_Objects, ts_test_constructor_4)
{
    TimeSerie<double> ts1{5};
    TimeSerie<double> ts2{5,"h"};
    TimeSerie<double> ts3{};

    ASSERT_EQ(TimeSerie<double>::getNbTS(), 3);
    {
            TimeSerie<double> tsTemp{{2.0,3.0}, {1,2},"s"};
            ASSERT_EQ(TimeSerie<double>::getNbTS(), 4);
    }

    ASSERT_EQ(TimeSerie<double>::getNbTS(), 3);
}

int main(int argc, char **argv)
{
        ::testing::InitGoogleTest(&argc,argv);
        return RUN_ALL_TESTS();
}
