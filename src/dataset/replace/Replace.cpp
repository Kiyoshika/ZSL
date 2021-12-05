#include "../../include/dataset/DataSet.hpp"

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
DataSet<DataSetType> DataSet<DataSetType>::replace(DataSetType find_value, DataSetType replace_value, size_t occurences, bool modify_inplace)
{
    size_t occurence_count = 0;
    DataSet<DataSetType> data_copy = *this;
    for (size_t row = 0; row < data_copy.count_rows(); ++row)
    {
        for (size_t col = 0; col < data_copy.count_columns(); ++col)
        {
            if (data_copy(row, col) == find_value)
            {
                data_copy(row, col) = replace_value;
                occurence_count++;
                if (occurences != 0 && occurence_count >= occurences) { goto end_occurence; }
            }
        }
    }

    end_occurence:

    if (modify_inplace) { *this = data_copy; }
    return data_copy;
}