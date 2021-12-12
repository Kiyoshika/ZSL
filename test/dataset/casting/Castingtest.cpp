#include <gtest/gtest.h>
#include <dataset/DataSet.hpp>

TEST(Castingtest, cast_string_to_double) {
    DataSet<std::string> original_data("../../datasets/doubles2.csv");
    DataSet<double> double_data = original_data.cast<double>();
    EXPECT_EQ(typeid(double), typeid(double_data(0,0)));
}

TEST(Castingtest, cast_string_to_int) {
    DataSet<std::string> original_data("../../datasets/doubles2.csv");
    DataSet<int> int_data = original_data.cast<int>();
    EXPECT_EQ(typeid(int), typeid(int_data(0,0)));
}

TEST(Castingtest, cast_string_to_string) {

}

TEST(Castingtest, cast_double_to_double) {

}

TEST(Castingtest, cast_double_to_int) {

}

TEST(Castingtest, cast_double_to_string) {

}

TEST(Castingtest, cast_int_to_double) {

}

TEST(Castingtest, cast_int_to_int {

}

TEST(Castingtest, cast_int_to_string) {

}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}