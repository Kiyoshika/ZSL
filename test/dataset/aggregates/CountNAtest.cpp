#include <gtest/gtest.h>
#include <dataset/DataSet.hpp>

TEST(CountNAtest, count_na) {
    DataSet<std::string> data("../../../datasets/rows_with_nulls.csv");
    EXPECT_EQ(6, data.count_na());
}