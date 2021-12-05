#include "../../include/dataset/DataSet.hpp"
#include <fstream>

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
void DataSet<DataSetType>::load(std::vector<DataSetType> const& data, std::vector<std::string> const& column_names)
{
    this->resize(1, column_names.size());
    this->set_column_names(column_names);
    this->set_row(0, data);
}

template <typename DataSetType>
void DataSet<DataSetType>::load(std::vector<DataSetType> const& data, std::string const& column_name)
{
    this->resize(data.size(), 1);
    this->add_column_name(column_name);
    this->set_column(0, data);
}

template <typename DataSetType>
void DataSet<DataSetType>::to_csv(std::string const& file_name, char const delim)
{
    std::ofstream file;
    file.open(file_name);
    // write columns
    for (size_t col = 0; col < this->column_count; ++col)
    {
        file << this->get_column_names()[col];
        // don't write comma on last column
        if (col < this->column_count - 1) { file << delim; }
    }

    file << "\n";

    // write data
    for (size_t row = 0; row < this->row_count; ++row)
    {
        for (size_t col = 0; col < this->column_count; ++col)
        {
            file << (*this)(row, col);
            // don't write comma on last column
            if (col < this->column_count - 1) { file << delim; }
        }
        file << "\n";
    }

    file.close();
}