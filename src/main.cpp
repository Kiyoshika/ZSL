#include <iostream>
#include "include/dataset/DataSet.hpp"

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<double> data("../datasets/doubles.csv");
    DataSet<double> data2("../datasets/doubles2.csv");

    //data.append(data2, 'r', true);

    data.transpose(true);

    for (size_t row = 0; row < data.count_rows(); ++row)
    {
        for (size_t col = 0; col < data.count_columns(); ++col)
        {
            std::cout << data(row, col) << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for (auto col : data.get_column_names())
    {
        std::cout << col << " ";
    }
    
    return 0;
}