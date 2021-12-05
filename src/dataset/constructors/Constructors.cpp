#include "../../include/dataset/DataSet.hpp"
#include <fstream>
#include <string>
#include <type_traits>

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
DataSet<DataSetType>::DataSet(size_t rows, size_t columns)
{
    this->row_count = rows;
    this->column_count = columns;
    this->data.resize(rows * columns);
}



// get row/column dimensions from file to size up data set
// modifying the row/col count by reference
void get_dims_from_file(std::string file_name, char delim, size_t &row_count, size_t &column_count)
{
    std::ifstream file(file_name);
    std::string current_line, cell_value = "";
    bool reading_headers = true; // read first line as headers
    bool inside_quotes = false;

    // pass through file initially to size up data set
    if (file.is_open())
    {
        while (std::getline(file, current_line))
        {
            row_count++;

            for (auto current_char = current_line.begin(); current_char != current_line.end(); ++current_char)
            {
                // checking inside quotes
                if (*current_char == '"' && inside_quotes == false) { inside_quotes = true; }
                else if (*current_char == '"' && inside_quotes == true) { inside_quotes = false; }

                // read cell into header
                if (*current_char == delim && !inside_quotes && reading_headers)
                {
                    column_count++;
                }

                // when reaching end of line and counting columns, there will be no delimiter
                if (current_char == current_line.end() - 1 && reading_headers)
                {
                    column_count++;
                }
            }
            reading_headers = false;
        }
        row_count--; // don't count header row towards row count
    }
    file.close();
}



std::string get_string_cell_value(std::string const& cell_value)
{
    return cell_value;
}

int get_int_cell_value(std::string const& cell_value)
{
    return std::stoi(cell_value);
}

double get_double_cell_value(std::string const& cell_value)
{
    return std::stod(cell_value);
}

template <typename ConversionType>
void parse_file(std::string file_name, char delim, size_t row_count, size_t column_count, std::vector<ConversionType> &data, std::vector<std::string> &headers, ConversionType (*convert_cell_value)(std::string const&))
{
    std::string current_line, cell_value = "";
    bool reading_headers = true; // read first line as headers
    bool inside_quotes = false;

    size_t current_row = 0, current_column = 0;
    
    // parse file and populate data set
    std::ifstream file(file_name);
    if (file.is_open())
    {
        while (std::getline(file, current_line))
        {
            for (auto current_char = current_line.begin(); current_char != current_line.end(); ++current_char)
            {
                cell_value += *current_char;

                // checking inside quotes
                if (*current_char == '"' && inside_quotes == false) { inside_quotes = true; }
                else if (*current_char == '"' && inside_quotes == true) { inside_quotes = false; }

                // read cell into header
                if (*current_char == delim && !inside_quotes && reading_headers)
                {
                    cell_value.pop_back(); // take off delimiter
                    headers.push_back(cell_value);
                    cell_value.clear();
                }

                // read cell into data
                if (*current_char == delim && !inside_quotes && !reading_headers)
                {
                    cell_value.pop_back(); // take off delimiter
                    data[current_row * column_count + current_column] = convert_cell_value(cell_value);
                    current_column++;
                    cell_value.clear();
                }

                // when reaching end of line, there will be no delimiter
                if (current_char == current_line.end() - 1 && reading_headers)
                {
                    headers.push_back(cell_value);
                    cell_value.clear();
                }

                // when reaching end of line, there will be no delimiter
                if (current_char == current_line.end() - 1 && !reading_headers)
                {
                    data[current_row * column_count + current_column] = convert_cell_value(cell_value);
                    cell_value.clear();
                }
            }
            if (!reading_headers) { current_row++; }
            reading_headers = false;
            current_column = 0;
        }
    }
    file.close();
}

template <typename DataSetType>
void set_dims(DataSet<DataSetType> &data_set, std::string const& file_name, char const& delim)
{
    size_t row_count = 0, column_count = 0;

    // pass through file initially to size up data set
    get_dims_from_file(file_name, delim, row_count, column_count);
    
    // size data set based on the dimensions we've gathered from the file
    data_set.set_row_count(row_count);
    data_set.set_column_count(column_count);
    data_set.resize(row_count, column_count);
}

template <>
DataSet<std::string>::DataSet(std::string const& file_name, char const delim)
{
    set_dims(*this, file_name, delim);
    parse_file<std::string>(file_name, delim, row_count, column_count, this->data, this->column_names, get_string_cell_value);
}

template <>
DataSet<double>::DataSet(std::string const& file_name, char const delim)
{
    set_dims(*this, file_name, delim);
    parse_file<double>(file_name, delim, row_count, column_count, this->data, this->column_names, get_double_cell_value);
}

template <>
DataSet<int>::DataSet(std::string const& file_name, char const delim)
{
    set_dims(*this, file_name, delim);
    parse_file<int>(file_name, delim, row_count, column_count, this->data, this->column_names, get_int_cell_value);

}

template <typename DataSetType>
DataSet<DataSetType>::DataSet(std::vector<DataSetType> const& data, std::vector<std::string> const& column_names)
{
    // equivalent to load()
    this->load(data, column_names);
}

template <typename DataSetType>
DataSet<DataSetType>::DataSet(std::vector<DataSetType> const& data, std::string const& column_name)
{
    // equivalent to load()
    this->load(data, column_name);
}