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