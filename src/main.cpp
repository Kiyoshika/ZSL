#include <iostream>
#include "include/dataset/DataSet.hpp"

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<std::string> data("../datasets/repeated_value_cells.csv");
    data.replace("a", "f", 0, true);

    for (size_t row = 0; row < data.count_rows(); ++row)
    {
        for (size_t col = 0; col < data.count_columns(); ++col)
        {
            std::cout << data(row, col) << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}