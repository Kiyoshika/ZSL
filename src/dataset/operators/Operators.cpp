#include "../../include/dataset/DataSet.hpp"

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
void DataSet<DataSetType>::operator = (DataSet const& other_data)
{
    // setting a data set equal to another. This means resizing, setting columns and data
    this->resize(other_data.row_count, other_data.column_count);
    this->set_column_names(other_data.get_column_names());
    for (size_t i = 0; i < other_data.row_count; ++i)
    {
        this->set_row(i, other_data.get_row(i));
    }
}

template <typename DataSetType>
bool DataSet<DataSetType>::operator == (DataSet const& other_data) const
{
    // check if column names are equal and if all cell values are equal
    // the first obvious checks are the dimensions
    if (this->row_count != other_data.row_count || this->column_count != other_data.column_count) { return false; }
    
    // check column names
    std::vector<std::string> this_columns = this->get_column_names();
    std::vector<std::string> other_columns = other_data.get_column_names();
    for (size_t i = 0; i < other_data.column_count; ++i)
    {
        if (this_columns[i] != other_columns[i]) { return false; }
    }

    // check cell values
    for (size_t row = 0; row < other_data.row_count; ++row)
    {
        for (size_t col = 0; col < other_data.column_count; ++col)
        {
            if ((*this)(row, col) != other_data(row, col)) { return false; }
        }
    }

    // if all checks pass, then data sets are equal
    return true;
}

template <typename DataSetType>
bool DataSet<DataSetType>::operator != (DataSet const& other_data) const
{
    if ( !((*this) == other_data) ) { return true; }
    return false;
}

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