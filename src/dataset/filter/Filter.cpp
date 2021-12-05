#include "../../include/dataset/DataSet.hpp"

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
DataSet<DataSetType> DataSet<DataSetType>::filter(std::function<bool(std::vector<DataSetType>)> filter_conditions, bool modify_inplace)
{
    std::vector<size_t> kept_row_indices;

    // pass through data set and record which indices will be kept
    for (size_t row = 0; row < this->row_count; ++row)
    {
        if (filter_conditions(this->get_row(row))) { kept_row_indices.push_back(row); }
    }

    // size data set and filter
    DataSet<DataSetType> filtered_data(kept_row_indices.size(), this->column_count);
    filtered_data.set_column_names(this->column_names);
    size_t iter = 0;
    for (auto const& row_idx : kept_row_indices)
    {
        filtered_data.set_row(iter, this->get_row(row_idx));
        iter++;
    }

    if (modify_inplace) { *this = filtered_data; }
    return filtered_data;
}