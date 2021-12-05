#include "../../include/dataset/DataSet.hpp"
#include <algorithm>

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
DataSet<DataSetType> DataSet<DataSetType>::drop(std::vector<size_t> const& column_indices, bool modify_inplace)
{
    std::vector<size_t> original_column_indices(this->column_count);
    for (size_t i = 0; i < this->column_count; ++i)
    {
        original_column_indices[i] = i;
    }

    std::vector<size_t> new_column_indices;
    // take the vector complement of original \ drop to get the select indices
    for (auto const& col_idx : original_column_indices)
    {
        // if original column index is not in the index to drop
        // add it to our new select indicies
        if (std::find(column_indices.begin(), column_indices.end(), col_idx) == column_indices.end())
        {
            new_column_indices.push_back(col_idx);
        }
    }

    // after identifying which indices to select, now we can call select()
    return select(new_column_indices, modify_inplace);
}

template <typename DataSetType>
DataSet<DataSetType> DataSet<DataSetType>::drop(std::vector<std::string> const& column_names, bool modify_inplace)
{
    std::vector<size_t> original_column_indices(this->column_count);
    for (size_t i = 0; i < this->column_count; ++i)
    {
        original_column_indices[i] = i;
    }

    std::vector<size_t> column_indices = get_column_indices(column_names);
    std::vector<size_t> new_column_indices;
    // take the vector complement of original \ drop to get the select indices
    for (auto const& col_idx : original_column_indices)
    {
        // if original column index is not in the index to drop
        // add it to our new select indicies
        if (std::find(column_indices.begin(), column_indices.end(), col_idx) == column_indices.end())
        {
            new_column_indices.push_back(col_idx);
        }
    }

    // after identifying which indices to select, now we can call select()
    return select(new_column_indices, modify_inplace);
}

template <>
DataSet<std::string> DataSet<std::string>::dropna(std::string const& null_value, bool modify_inplace)
{
    std::vector<std::string> current_row;
    std::vector<size_t> keep_row_indices;
    for (size_t row = 0; row < this->row_count; ++row)
    {
        // for each row, check if there are no null values in any columns
        current_row = this->get_row(row);
        if (std::find(current_row.begin(), current_row.end(), null_value) == current_row.end())
        {
            keep_row_indices.push_back(row);
        }
    }

    // after gathering which incdices to keep, size up data set and add rows
    DataSet<std::string> subset(keep_row_indices.size(), this->column_count);
    for (size_t row = 0; row < keep_row_indices.size(); ++row)
    {
        subset.set_row(row, this->get_row(keep_row_indices[row]));
    }

    if (modify_inplace) { *this = subset; }
    return subset;
}