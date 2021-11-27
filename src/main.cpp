#include <iostream>
#include "include/dataset/DataSet.hpp"

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<std::string> data1("../datasets/example_csv.csv");
    DataSet<std::string> data2 = data1;
    DataSet<std::string> data3("../datasets/example_csv_2.csv");

    bool is_equal = data2 == data1;
    bool is_equal2 = data3 == data1;
    bool is_notequal = data3 != data1;
    std::cout << is_equal << "\n"; // 1
    std::cout << is_equal2 << "\n"; // 0
    std::cout << is_notequal << "\n"; // 1

    return 0;
}