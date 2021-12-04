#include "../../include/dataset/DataSet.hpp"

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

// generic methods that don't really fit into any of the subfolders I've created

template<typename DataSetType>
void DataSet<DataSetType>::resize(size_t rows, size_t columns)
{
    this->row_count = rows;
    this->column_count = columns;
    this->data.resize(rows * columns);
}