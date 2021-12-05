#include <iostream>
#include "include/dataset/DataSet.hpp"

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<std::string> data("../datasets/doubles.csv");
    data.head(10);

    return 0;
}