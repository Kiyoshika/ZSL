#include <iostream>
#include <dataset/DataSet.hpp>

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<std::string> data("../datasets/rows_with_nulls.csv");
    std::cout << data.count_na() << "\n";

    return 0;
}