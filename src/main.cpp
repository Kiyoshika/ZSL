#include <iostream>
#include "include/dataset/DataSet.hpp"

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<int> mydata("../datasets/example_csv_2.csv");

    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t col = 0; col < 3; ++col)
        {
            std::cout << mydata(row, col) << " ";
        }
        std::cout << "\n";
    }

    for (auto const& cols : mydata.get_column_names())
    {
        std::cout << cols << " ";
    }

    return 0;
}