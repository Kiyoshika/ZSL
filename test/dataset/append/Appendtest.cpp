#include <gtest/gtest.h>
#include <dataset/DataSet.hpp>
#include <vector>
#include <exception>

TEST(Appendtest, append_rows_not_inplace) {
    DataSet<double> data1("../../datasets/doubles2.csv");
    DataSet<double> data2("../../datasets/doubles2.csv");
    DataSet<double> appended = data1.append(data2, 'r', false);
    EXPECT_EQ(data1.count_rows() + data2.count_rows(), appended.count_rows());
}

TEST(Appendtest, append_rows_inplace) {
    DataSet<double> data1("../../datasets/doubles2.csv");
    DataSet<double> data2("../../datasets/doubles2.csv");
    size_t new_size = data1.count_rows() + data2.count_columns();
    data1.append(data2, 'r', true);
    EXPECT_EQ(new_size, data1.count_rows());
}

TEST(Appendtest, append_columns_not_inplace)
{
    DataSet<double> data1("../../datasets/doubles2.csv");
    DataSet<double> data2("../../datasets/doubles2.csv");
    DataSet<double> appended;
    
    // since these are coming from the same file they will have duplicate columns names
    // an exception should be thrown for duplicate column names
    EXPECT_ANY_THROW(appended = data1.append(data2, 'c', false));

    // set new column names to avoid name collision
    std::vector<std::string> col_names = {"col4","col5","col6"};
    data2.set_column_names(col_names);
    appended = data1.append(data2, 'c', false);

    EXPECT_EQ(data1.count_columns() + data2.count_columns(), appended.count_columns());
}

TEST(Appendtest, append_columns_inplace) {
    DataSet<double> data1("../../datasets/doubles2.csv");
    DataSet<double> data2("../../datasets/doubles2.csv");
    size_t new_size = data1.count_columns() + data2.count_columns();

    // since these are coming from the same file they will have duplicate columns names
    // an exception should be thrown for duplicate column names
    EXPECT_ANY_THROW(data1.append(data2, 'c', true));

    // set new column names to avoid name collision
    std::vector<std::string> col_names = {"col4","col5","col6"};
    data2.set_column_names(col_names);
    data1.append(data2, 'c', true);

    EXPECT_EQ(new_size, data1.count_columns());
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}