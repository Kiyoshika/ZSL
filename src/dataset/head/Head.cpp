#include "../../include/dataset/DataSet.hpp"
#include "../../include/console/PrintTable.hpp"
#include <algorithm>

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
void DataSet<DataSetType>::head(size_t rows)
{
    PrintTable::print_table(*this);
}