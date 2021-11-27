#include "../../include/dataset/DataSet.hpp"

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

// getters
template <typename DataSetType>
std::vector<std::string> DataSet<DataSetType>::get_column_names() const { return this->column_names; }

template <typename DataSetType>
DataSetType DataSet<DataSetType>::get_cell(size_t row, size_t column) { return (*this)(row, column); }

template <typename DataSetType>
std::vector<DataSetType> DataSet<DataSetType>::get_column(size_t column) const
{
    std::vector<DataSetType> column_data(this->row_count);
    for (size_t row = 0; row < this->row_count; ++row)
    {
        column_data[row] = (*this)(row, column);
    }

    return column_data;
}

template <typename DataSetType>
std::vector<DataSetType> DataSet<DataSetType>::get_row(size_t row) const
{
    std::vector<DataSetType> row_data(this->column_count);
    for (size_t column = 0; column < this->column_count; ++column)
    {
        row_data[column] = (*this)(row, column);
    }

    return row_data;
}

template <typename DataSetType>
size_t DataSet<DataSetType>::count_rows() const { return this->row_count; }

template <typename DataSetType>
size_t DataSet<DataSetType>::count_columns() const { return this->column_count; }

template <typename DataSetType>
std::vector<size_t> DataSet<DataSetType>::get_column_indices(std::vector<std::string> const& column_names)
{
    std::vector<size_t> column_indices(column_names.size());

    size_t iter = 0;
    for (auto const& col : column_names)
    {
        auto find_index = std::lower_bound(this->column_names.begin(), this->column_names.end(), col);
        if (find_index == this->column_names.end())
        {
            throw std::invalid_argument("get_column_indices() - Could not find all passed column values when trying to get their indices.");
        }
        column_indices[iter] = std::distance(this->column_names.begin(), find_index);
        iter++;
    }

    return column_indices;
}





// setters
template <typename DataSetType>
void DataSet<DataSetType>::add_column_name(std::string const& column_name) { this->column_names.push_back(column_name); }

template <typename DataSetType>
void DataSet<DataSetType>::set_cell(size_t row, size_t column, DataSetType value) { (*this)(row, column) = value; }

template <typename DataSetType>
void DataSet<DataSetType>::set_column(size_t column, std::vector<DataSetType> const& values)
{
    for (size_t row = 0; row < this->row_count; ++row)
    {
        (*this)(row, column) = values[row];
    }
}

template <typename DataSetType>
void DataSet<DataSetType>::set_column_names(std::vector<std::string> const& column_names)
{
    this->column_names = column_names;
}

template <typename DataSetType>
void DataSet<DataSetType>::set_row(size_t row, std::vector<DataSetType> const& values)
{
    for (size_t column = 0; column < this->column_count; ++column)
    {
        (*this)(row, column) = values[column];
    }
}

template <typename DataSetType>
void DataSet<DataSetType>::set_row_count(size_t rows) { this->row_count = rows; }

template <typename DataSetType>
void DataSet<DataSetType>::set_column_count(size_t columns) { this->column_count = columns; }