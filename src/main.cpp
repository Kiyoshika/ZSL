#include <iostream>
#include "include/dataset/DataSet.hpp"

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<double> data("../datasets/doubles.csv");
    //data.append(data2, 'r', true);

    DataSet<double> data2 = data.transpose().transpose();

    for (size_t row = 0; row < data2.count_rows(); ++row)
    {
        for (size_t col = 0; col < data2.count_columns(); ++col)
        {
            std::cout << data2(row, col) << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for (auto col : data2.get_column_names())
    {
        std::cout << col << " ";
    }
    
    return 0;
}