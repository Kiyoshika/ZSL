#include "../../include/dataset/DataSet.hpp"
#include <algorithm>

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

// returns true if duplicate column names are found, otherwise returns false
bool check_column_collision(std::vector<std::string> const& original_columns, std::vector<std::string> const& other_columns)
{
    // iterate over the other_columns and check if we already have a column with the same name
    for (auto col : other_columns)
    {
        if (std::find(original_columns.begin(), original_columns.end(), col) != original_columns.end()) { return true; }
    }

    return false;
}

template <typename DataSetType>
DataSet<DataSetType> DataSet<DataSetType>::append(DataSet<DataSetType> const& other_data, char type, bool modify_inplace)
{
    DataSet<DataSetType> appended_data; // will resize depending on type
    switch (type)
    {
        case 'r':
            // when appending along rows, column dimensions must match
            if (this->column_count != other_data.count_columns()) { throw std::runtime_error("When appending data along rows, column sizes must match."); }
            
            appended_data.resize(this->row_count + other_data.count_rows(), this->column_count);
            // first copy original data set then populate other_data
            for (size_t row = 0; row < this->row_count; ++row)
            {
                for (size_t col = 0; col < this->column_count; ++col)
                {
                    appended_data(row, col) = (*this)(row, col);
                }
            }

            for (size_t row = this->row_count; row < this->row_count + other_data.count_rows(); ++row)
            {
                for (size_t col = 0; col < this->column_count; ++col)
                {
                    appended_data(row, col) = other_data(row - this->row_count, col);
                }
            }

            // add the original column names
            for (auto col : this->get_column_names())
            {
                appended_data.add_column_name(col);
            }
        break;

        case 'c':
            // check column collision (cannot duplicate column names)
            if (check_column_collision(this->get_column_names(), other_data.get_column_names())) 
            { 
                throw std::runtime_error("Duplicate column names found when appending data. Please ensure column names are unique."); 
            }
            
            // when appending data along columns, row sizes must match
            if (this->row_count != other_data.count_rows()) { throw std::runtime_error("When appending data along columns, row sizes must match."); }
            
            appended_data.resize(this->row_count, this->column_count + other_data.count_columns());
            // first copy original data then populate other_data
            for (size_t row = 0; row < this->row_count; ++row)
            {
                for (size_t col = 0; col < this->column_count; ++col)
                {
                    appended_data(row, col) = (*this)(row, col);
                }
            }

            for (size_t row = 0; row < this->row_count; ++row)
            {
                for (size_t col = this->column_count; col < this->column_count + other_data.count_columns(); ++col)
                {
                    appended_data(row, col) = other_data(row, col - this->column_count);
                }
            }

            // add original column names to the vector of column names
            for (auto col : this->get_column_names())
            {
                appended_data.add_column_name(col);
            }

            // add other_columns to the vector of column names
            for (auto col : other_data.get_column_names())
            {
                appended_data.add_column_name(col);
            }
        break;

        default:
            throw std::invalid_argument("Please use 'r' (rows) or 'c' (columns) as the 'type' argument for append().");
        break;
    }

    if (modify_inplace) { *this = appended_data; }
    return appended_data;
}