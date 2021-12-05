#include "../../include/dataset/DataSet.hpp"
#include <algorithm>

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
void DataSet<DataSetType>::rename(std::unordered_map<std::string, std::string> const& old_new_column_names)
{
    std::vector<std::string> current_columns = this->get_column_names();
    size_t idx;

    for (const auto& col_map : old_new_column_names)
    {
        auto it = std::find(current_columns.begin(), current_columns.end(), col_map.first);
        
        if (it == current_columns.end()) { throw std::runtime_error("Could not find column when trying to rename(). Ensure column names are correct."); }
        else
        {
            idx = std::distance(current_columns.begin(), it);
            this->column_names[idx] = col_map.second;
        }
    }
}