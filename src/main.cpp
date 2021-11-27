#include <iostream>
#include "include/dataset/DataSet.hpp"

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<double> data("../datasets/example_csv_2.csv");

    std::vector<std::string> col_names = {"col1", "col3"};
    DataSet<double> select_data = data.select(col_names);

    for (auto const& col : select_data.get_column_names())
    {
        std::cout << col << " ";
    }

    return 0;
}