#include <iostream>
#include "include/dataset/DataSet.hpp"

// file is used for ad-hoc testing/experimenting
// will be removed in releases

int main()
{
    DataSet<double> mydata(2, 2);
    std::cout << mydata(0, 0) << "\n";
    return 0;
}