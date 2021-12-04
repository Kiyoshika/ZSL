#include <iostream>
#include "include/dataset/DataSet.hpp"

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<double> data("../datasets/doubles3.csv");
    std::unordered_map<std::string, std::string> remap = {
        {"col1", "newcol1"},
        {"col4", "newcol3"}
    };
    data.rename(remap);

    for (auto col : data.get_column_names())
    {
        std::cout << col << " ";
    }

    return 0;
}