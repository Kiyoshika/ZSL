#include "../../include/dataset/DataSet.hpp"
#include "../../include/console/PrintTable.hpp"

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <>
void DataSet<std::string>::head(size_t rows, size_t column_width)
{
    PrintTable::print_table(*this, rows, column_width);
}

// for numerical types, need to pass a std::string data set
template <typename DataSetType>
void DataSet<DataSetType>::head(size_t rows, size_t column_width)
{
    // assuming the DataSetType is either double or int
    // since std::string is already defined above
    DataSet<std::string> string_data_set = (*this).cast<std::string>();
    PrintTable::print_table(string_data_set, rows, column_width);
}