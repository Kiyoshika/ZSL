#include <iostream>
#include "include/dataset/DataSet.hpp"

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<double> data("../datasets/example_csv_2.csv");
    std::vector<size_t> drop_idx = {1};

    DataSet<double> data_drop = data.drop(drop_idx);

    for (size_t row = 0; row < data_drop.count_rows(); ++row)
    {
        for (size_t col = 0; col < data_drop.count_columns(); ++col)
        {
            std::cout << data_drop(row, col) << " ";
        }
        std::cout << "\n";
    }
    
    

    return 0;
}