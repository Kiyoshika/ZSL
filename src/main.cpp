#include <iostream>
#include "include/dataset/DataSet.hpp"

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<std::string> data("../datasets/example_csv_2.csv");

    DataSet<double> data_double = data.cast<double>();
    DataSet<int> data_int = data_double.cast<int>();
    std::cout << data_int(0, 0) << "\n";

    return 0;
}