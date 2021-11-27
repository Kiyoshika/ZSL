#include "../../include/dataset/DataSet.hpp"
#include <string>

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

// different specifications for converting values from different types
template <typename DataSetType, typename CastType>
CastType converted_value(DataSetType value);

// string to double
template <>
double converted_value(std::string value) { return std::stod(value); }

// int to double
template <>
double converted_value(int value) { return (double)value; }

// string to int
template <>
int converted_value(std::string value) { return std::stoi(value); }

// double to int
template <>
int converted_value(double value) { return (int)value; }

// double to string
template <>
std::string converted_value(double value) { return std::to_string(value); }

// int to string
template <>
std::string converted_value(int value) { return std::to_string(value); }

template <typename DataSetType>
template <typename CastType>
DataSet<CastType> DataSet<DataSetType>::cast()
{
    DataSet<CastType> casted_dataset(this->row_count, this->column_count);
    casted_dataset.set_column_names(this->column_names);

    for (size_t row = 0; row < this->row_count; ++row)
    {
        for (size_t col = 0; col < this->column_count; ++col)
        {
            casted_dataset(row, col) = converted_value<DataSetType, CastType>((*this)(row, col));
        }
    }

    return casted_dataset;
}

// annoyingly have to force instantiation of different template types
// otherwise the linker complains that it's undefined
template DataSet<double> DataSet<std::string>::cast();
template DataSet<double> DataSet<int>::cast();
template DataSet<int> DataSet<std::string>::cast();
template DataSet<int> DataSet<double>::cast();
template DataSet<std::string> DataSet<double>::cast();
template DataSet<std::string> DataSet<int>::cast();