#include "../../include/dataset/DataSet.hpp"

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

// only works for std::string types
template <>
size_t DataSet<std::string>::count_na(std::string const& null_value)
{
    size_t na_count = 0;
    for (size_t row = 0; row < this->row_count; ++row)
    {
        for (size_t col = 0; col < this->column_count; ++col)
        {
            if ((*this)(row, col) == null_value) { na_count++; }
        }
    }

    return na_count;
}

template<>
void DataSet<std::string>::count_na_by_column(std::string const& null_value)
{
    // vector that stores the na count for each column
    std::vector<size_t> na_count_by_column(this->column_count);

    for (size_t row = 0; row < this->row_count; ++row)
    {
        for (size_t col = 0; col < this->column_count; ++col)
        {
            if ((*this)(row, col) == null_value) { na_count_by_column[col]++; }
        }
    }

    // print column name and null count to console
    // NOTE: want to overhaul this with a class to help "prettify" console outputs
    std::cout << "Column Name:\t| NA Count\n";
    std::cout << "-----------------------------\n";
    std::vector<std::string> col_names = this->get_column_names();
    for (size_t i = 0; i < this->column_count; ++i)
    {
        std::cout << col_names[i] << ":\t\t| " << na_count_by_column[i] << "\n";
    }
}