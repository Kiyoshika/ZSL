#include <iostream>
#include "include/dataset/DataSet.hpp"

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<double> data("../datasets/doubles3.csv");
    DataSet<double> train, test;
    data.split_data(train, test);
    // approx 3 rows should be in test
    // approx 7 rows should be in train 
    
    for (size_t row = 0; row < train.count_rows(); ++row)
    {
        for (size_t col = 0; col < train.count_columns(); ++col)
        {
            std::cout << train(row, col) << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for (auto col : train.get_column_names())
    {
        std::cout << col << " ";
    }

    std::cout << "\n\n";

    for (size_t row = 0; row < test.count_rows(); ++row)
    {
        for (size_t col = 0; col < test.count_columns(); ++col)
        {
            std::cout << test(row, col) << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for (auto col : test.get_column_names())
    {
        std::cout << col << " ";
    }
 

    return 0;
}