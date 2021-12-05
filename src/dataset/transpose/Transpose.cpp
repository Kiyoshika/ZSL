#include "../../include/dataset/DataSet.hpp"
#include <string>

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
DataSet<DataSetType> DataSet<DataSetType>::transpose(bool modify_inplace)
{
    // dimensions will be reversed
    DataSet<DataSetType> transposed_data(this->column_count, this->row_count);
    
    // reset columns to generic column names
    for (size_t i = 0; i < this->row_count; ++i)
    {
        transposed_data.add_column_name("col" + std::to_string(i));
    }
    
    // swap row and column indices
    for (size_t row = 0; row < this->row_count; ++row)
    {
        for (size_t col = 0; col < this->column_count; ++col)
        {
            transposed_data(col, row) = (*this)(row, col);
        }
    }

    if (modify_inplace) { *this = transposed_data; }
    return transposed_data;
}