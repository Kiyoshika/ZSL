#include "../DataSet.hpp"

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
DataSet<DataSetType>::DataSet(size_t rows, size_t columns)
{
    this->row_count = rows;
    this->column_count = columns;
    this->data.resize(rows * columns);
}