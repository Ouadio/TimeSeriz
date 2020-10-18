#include <iostream>
#include <vector>
#include <cmath>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "timeSerie.h"
#include "smoother.h"

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

//Smooth Moving Average Class Tests
TEST(Smooth_Objects, smooth_test_MA_Trivial_1)
{
    TimeSerie<double> ts1{10};
    MA<double> myModel{1, true};
    myModel.fit(ts1.getValues(), ts1.getTimeStamp());
    std::vector<double> myFittedValues = myModel.getFittedValues();
    ASSERT_THAT(myFittedValues, ::testing::ElementsAreArray({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
}

TEST(Smooth_Objects, smooth_test_MA_Trivial_2)
{
    TimeSerie<double> ts1{10};
    MA<double> myModel{3, true};
    myModel.fit(ts1.getValues(), ts1.getTimeStamp());
    std::vector<double> myFittedValues = myModel.getFittedValues();
    ASSERT_THAT(myFittedValues, ::testing::ElementsAreArray({0, 0, 0, 0, 0, 0, 0, 0}));
}

TEST(Smooth_Objects, smooth_test_MA_Trivial_3)
{
    std::vector<double> data = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    TimeSerie<double> ts1{data};
    MA<double> myModel{3, true};
    myModel.fit(ts1.getValues(), ts1.getTimeStamp());
    std::vector<double> myFittedValues = myModel.getFittedValues();
    ASSERT_THAT(myFittedValues, ::testing::ElementsAreArray({1, 1, 1, 1, 1, 1, 1, 1}));
}

TEST(Smooth_Objects, smooth_test_MA_Trivial_4)
{
    std::vector<double> data = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    TimeSerie<double> ts1{data};
    MA<double> myModel{3, false};
    myModel.fit(ts1.getValues(), ts1.getTimeStamp());
    std::vector<double> myFittedValues = myModel.getFittedValues();
    ASSERT_THAT(myFittedValues, ::testing::ElementsAreArray({1, 1, 1, 1, 1, 1, 1, 1,1}));
}


TEST(Smooth_Objects, smooth_test_MA_Trivial_5)
{
    std::vector<double> data = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    TimeSerie<double> ts1{data};
    MA<double> myModel{11, true};
    myModel.fit(ts1.getValues(), ts1.getTimeStamp());
    std::vector<double> myFittedValues = myModel.getFittedValues();
    ASSERT_EQ(myFittedValues.size(), 1);
    ASSERT_THAT(myFittedValues, ::testing::ElementsAreArray({1}));
}

TEST(Smooth_Objects, smooth_test_MA_Trivial_6)
{
    std::vector<double> data(1000);
    for(auto &elem:data){
        elem = rand()%20;
    }

    TimeSerie<double> ts1{data};

    MA<double> myModelCenterd{13, true};
    MA<double> myModelTrailed{13, false};

    myModelCenterd.fit(ts1.getValues(), ts1.getTimeStamp());
    myModelTrailed.fit(ts1.getValues(), ts1.getTimeStamp());

    std::vector<double> myFittedValuesC = myModelCenterd.getFittedValues();
    std::vector<double> myFittedValuesT = myModelTrailed.getFittedValues();

    ASSERT_EQ(myFittedValuesC.size(), 1000-13+1);
    ASSERT_EQ(myFittedValuesT.size(), 1000-(13/2));

}

int main(int argc, char **argv)
{
        ::testing::InitGoogleTest(&argc,argv);
        return RUN_ALL_TESTS();
}
