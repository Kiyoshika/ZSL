#include "../DataSet.hpp"

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
DataSetType DataSet<DataSetType>::operator () (size_t row, size_t column) const
{
    return this->data[row * this->column_count + column];
}

template <typename DataSetType>
DataSetType &DataSet<DataSetType>::operator () (size_t row, size_t column)
{
    return this->data[row * this->column_count + column]; // returning a reference instead of a value so we can directly modify it
}

template <typename DataSetType>
DataSetType DataSet<DataSetType>::get_cell (size_t row, size_t column)
{
    return this->data[row * this->column_count + column];
}