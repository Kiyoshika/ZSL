#include "../../include/dataset/DataSet.hpp"

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
DataSet<DataSetType> DataSet<DataSetType>::select(std::vector<std::string> const& column_names, bool modify_inplace)
{
    DataSet<DataSetType> subset(this->row_count, column_names.size());
    std::vector<size_t> column_indices = get_column_indices(column_names);

    std::vector<std::string> original_column_names = this->get_column_names();
    std::vector<std::string> subset_column_names(column_indices.size());

    // populate data column-wise
    for (size_t col = 0; col < column_indices.size(); ++col)
    {
        subset_column_names[col] = original_column_names[column_indices[col]];
        subset.set_column(col, this->get_column(column_indices[col]));
    }

    subset.set_column_names(subset_column_names);

    if (modify_inplace) { *this = subset; }
    return subset;
}

template <typename DataSetType>
DataSet<DataSetType> DataSet<DataSetType>::select(std::vector<size_t> const& column_indices, bool modify_inplace)
{
    DataSet<DataSetType> subset(this->row_count, column_indices.size());

    std::vector<std::string> original_column_names = this->get_column_names();
    std::vector<std::string> subset_column_names(column_indices.size());

    // populate data column-wise
    for (size_t col = 0; col < column_indices.size(); ++col)
    {
        subset_column_names[col] = original_column_names[column_indices[col]];
        subset.set_column(col, this->get_column(column_indices[col]));
    }

    subset.set_column_names(subset_column_names);

    if (modify_inplace) { *this = subset; }
    return subset;
}