#ifndef DATASET_HPP
#define DATASET_HPP
#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>

/**
 * @brief A data structure that holds matrix-style data (rows, columns) with some utility methods to select columns, filter, etc.
 * @tparam DataSetType Generic data set type (string, double, int)
 * 
 */
template <typename DataSetType>
class DataSet
{
    public:
        /**
         * @brief Assign a data set equal to another.
         * 
         * @param other_data The right-hand-side data set which will overwrite the current data set. 
         */
        void operator = (DataSet const& other_data);



        /**
         * @brief Check equality of two data sets.
         * This will check if all column names, data types AND cell values are exactly the same. I.e, complete equality.
         * 
         * @param other_data The data set to compare.
         * @return true if the data sets are equal according to the above description. Otherwise false.
         */
        bool operator == (DataSet const& other_data) const;



        /**
         * @brief Check inequality of two data sets.
         * This will check if any of the column names, data types or cell values don't match. If it's not a complete equality, it will return false.
         * @param other_data The data set to compare.
         * @return true if the data sets are not equal according to the above description. Otherwise false.
         */
        bool operator != (DataSet const& other_data) const;



        /**
         * @brief Return the value at index (row, column).
         * 
         * @tparam DataSetType Generic data set type (string, double, int)
         * @param row Row index
         * @param column Column index
         * @return The value at cell index (row, column)
         */
        DataSetType operator () (size_t row, size_t column) const;



        /**
         * @brief Return a reference to the value at index (row, column).
         * 
         * @tparam DataSetType Generic data set type (string, double, int)
         * @param row Row index
         * @param column Column index
         * @return The value at cell index (row, column)
         */
        DataSetType &operator () (size_t row, size_t column);



        /**
         * @brief Default constructor, does nothing.
         * 
         */
        DataSet() {}



        /**
         * @brief A constructor that reads a file and populates the data set.
         * 
         * @param file_name The name of the CSV file you want to load. Note that if the file is NOT in local path, you must specify a relative/full path.
         * @param delim The delimiter to separate columns. By default, it's a comma.
         */
        DataSet(std::string const& file_name, char delim = ',');



        /**
         * @brief A constructor that sizes the data set according to given rows and columns. Equivalent to resize().
         * For numerical types (e.g int, double) it will initialize all values to zero (0). For strings, it will initialize all values to blank strings ("").
         * @see resize()
         * 
         * @param rows The number of rows desired in the data set
         * @param columns The number of columns desired in the data set
         */
        DataSet(size_t rows, size_t columns);



        /**
         * @brief Resize the data set according to given rows and columns.
         * 
         * @param rows The number of rows desired in the data set
         * @param columns The number of columns desired in the data set
         */
        void resize(size_t rows, size_t columns);



        /**
         * @brief Set the value at cell index (row, column).
         * 
         * @tparam DataSetType Generic data set type (string, double, int)
         * @param row Row index
         * @param column Column index
         * @param value Value to set
         */
        void set_cell(size_t row, size_t column, DataSetType value);



        /**
         * @brief Get the value at cell index (row, column).
         * @note This is equivalent to using the (row, colum) operator, e.g `my_data(row, column);`
         * 
         * @tparam DataSetType Generic data set type (string, double, int)
         * @param row Row index
         * @param column Column index
         * @return The value at cell index (row, column)
         */
        DataSetType get_cell(size_t row, size_t column);



        /**
         * @brief Set a given column in a data set to a vector of values.
         * 
         * @tparam DataSetType Generic data set type (string, double, int)
         * @param column Column index
         * @param values A vector of values to set as the column.
         */
        void set_column(size_t column, std::vector<DataSetType> const& values);



        /**
         * @brief Extract a column as a vector.
         * 
         * @tparam DataSetType Generic data set type (string, double, int) 
         * @param column Column index
         * @return A vector of values extracted from the given column index. 
         */
        std::vector<DataSetType> get_column(size_t column) const;



        /**
         * @brief Get column names for data set.
         * 
         * @return A vector of strings with the column names.
         */
        std::vector<std::string> get_column_names() const;



        /**
         * @brief Add a column name.
         * 
         * @param column_name The column name to add
         */
        void add_column_name(std::string const& column_name);



        /**
         * @brief Set column names for data set.
         * 
         * @param column_names A vector of strings with the column names.
         */
        void set_column_names(std::vector<std::string> const& column_names);



        /**
         * @brief Set a given row in a data set to a vector of values.
         * 
         * @tparam DataSetType Generic data set type (string, double, int)
         * @param row Row index
         * @param values A vector of values to set as the row.
         */
        void set_row(size_t row, std::vector<DataSetType> const& values);



        /**
         * @brief Extract a row as a vector.
         * 
         * @tparam DataSetType Generic data set type (string, double, int)
         * @param row Row index
         * @return A vector of values extracted from the given row index. 
         */
        std::vector<DataSetType> get_row(size_t row) const;



        /**
         * @brief Count rows present in data set (excluding column names).
         * 
         * @return Count of rows
         */
        size_t count_rows() const;



        /**
         * @brief Set the row count
         * 
         */
        void set_row_count(size_t rows);



        /**
         * @brief Count columns present in data set.
         * 
         * @return Count of columns 
         */
        size_t count_columns() const;



        /**
         * @brief Set the column count
         * 
         * @param columns The number of desired columns
         */
        void set_column_count(size_t columns);



        /**
         * @brief Load a data set with a 1D vector.
         * This accepts a vector of strings for the column names, implying that this data will be loaded as one ROW.
         * 
         * @tparam DataSetType Generic data set type (string, double int)
         * @param data The 1D vector containing the data you want to add to the data set.
         * @param column_names A vector of strings containing the column names you want to set.
         */
        void load(std::vector<DataSetType> const& data, std::vector<std::string> const& column_names);



        /**
         * @brief A constructor to load a 1D vector row-wise. Equivalent to load(std::vector<DataSetType>, std::vector<std::string>)
         * @see load(std::vector<DataSetType>, std::vector<std::string>)
         * 
         * @tparam DataSetType Generic data set type (string, double, int)
         * @param data The 1D vector containing the data you want to add to the data set.
         * @param column_names A vector of strings containing the column names you want to set.
         */
        DataSet(std::vector<DataSetType> const& data, std::vector<std::string> const& column_names);



        /**
         * @brief Load a data set with a 1D vector.
         * This accepts a single string for the column name, implying that this data will be loaded as one COLUMN.
         * 
         * @tparam DataSetType Generic data set type (string, double, int)
         * @param data The 1D vector containing the data you want to add to the data set.
         * @param column_name The name of the column you want to set.
         */
        void load(std::vector<DataSetType> const& data, std::string const& column_name);



        /**
         * @brief A constructor to load a 1D vector column-wise. Equivalent to load(std::vector<DataSetType>, std::string)
         * 
         * @tparam DataSetType Generic data set type (string, double, int)
         * @param data The 1D vector containing the data you want to add to the data set.
         * @param column_name The name of the column you want to set.
         */
        DataSet(std::vector<DataSetType> const& data, std::string const& column_name);



        /**
         * @brief Write contents of a data set to a CSV file.
         * 
         * @param file_name The desired file name (you must include your own extension, e.g .csv, .txt, etc)
         * @param delim The delimiter to separate columns. By default, it's a comma.
         */
        void to_csv(std::string const& file_name, char const delim = ',');



        /**
         * @brief Cast your dataset into a different data type.
         * @note Due to C++ template limitations, you cannot overwrite the current data set's type. You will have to assign this cast to a new DataSet object.
         * 
         * @return A copy of the data set converted to the desired data type.
         */
        DataSet cast();



        /**
         * @brief Select a subset of your original data set by passing the desired column indices.
         * 
         * @param column_indices A vector of size_t representing the indices of the desired columns.
         * @param modify_inplace A boolean indicating if you want to overwrite the original data set. By default it's false.
         * @return A copy of the data set with the selected columns. If modify_inplace = true, the original data set will be overwritten. 
         */
        DataSet select(std::vector<size_t> const& column_indices, bool modify_inplace = false);



        /**
         * @brief Select a subset of your original data set by passing the desired column names.
         * 
         * @param column_names A vector of strings representing the names of the desired columns.
         * @param modify_inplace A boolean indicating if you want to overwrite the original data set. By default it's false.
         * @return A copy of the data set with the selected columns. If modify_inplace = true, the original data set will be overwritten. 
         */
        DataSet select(std::vector<std::string> const& column_names, bool modify_inplace = false);



        /**
         * @brief Pass a lambda to this method to filter a data set's rows based on user-defined conditions.
         * The vector in the lambda argument represents a vector of the current row (when iterating through the data set).
         * Thus, the indices of the vector represent the volumn indices. vec[0] represents the zeroth column for example.
         * 
         * @tparam VectorType Generic type for the data set (string, double, int)
         * @param filter_conditions A boolean user-defined lambda that defines the filter conditions using the VectorType vector.
         * @param modify_inplace A boolean indicating if you want to overwrite the original data set. By default it's false.
         * @return A copy of the data set with the filter conditions applied. If modify_inplace = true, the original data set will be overwritten.
         */
        template <typename VectorType>
        DataSet filter(std::function<bool(std::vector<VectorType>)> filter_conditions, bool modify_inplace = false);



        /**
         * @brief Drop a set of columns from your original data set by passing the desired column indices.
         * 
         * @param column_indices A vector of size_t representing the indices of the desired columns to drop.
         * @param modify_inplace A boolean indicating if you want to overwrite the original data set. By default it's false.
         * @return A copy of the data set with the desired columns removed. If modify_inplace = true, the original data set will be overwritten.
         */
        DataSet drop(std::vector<size_t> const& column_indices, bool modify_inplace = false);



        /**
         * @brief Drop a set of columns from your original data set by passing the desired column names.
         * 
         * @param column_names A vector of strings representing the indices of the desired columns to drop.
         * @param modify_inplace A boolean indicating if you want to overwrite the original data set. By default it's false.
         * @return A copy of the data set with the desired columns removed. If modify_inplace = true, the original data set will be overwritten.
         */
        DataSet drop(std::vector<std::string> const& column_names, bool modify_inplace = false);



        /**
         * @brief Transpose the data set (i.e, switch the row/column indices to "rotate" the data).
         * @note When transposing data, the column names will be reverted to generic column names (col1, col2, ...) as the sizes can vary.
         * 
         * @param modify_inplace A boolean indicating if you want to overwrite the original data set. By default it's false.
         * @return A copy of the transposed data set. If modify_inplace = true, the original data set will be overwritten.
         */
        DataSet transpose(bool modify_inplace = false);



        /**
         * @brief Drop rows that contain null values.
         * @note This method ONLY works for string data types.
         * 
         * @param null_value Specify a specific null value such as "NA", "NaN", etc. By default it searches for blank strings "".
         * @param modify_inplace A boolean indicating if you want to overwrite the original data set. By default it's false.
         * @return A copy of the data set with rows removed that contained null values (in specified columns). If modify_inplace = true, the original data set will be overwritten. 
         */
        DataSet dropna(std::string const& null_value = "", bool modify_inplace = false);



        /**
         * @brief Replace cell values in a data set.
         * 
         * @tparam DataSetType Generic data set type (string, double, int)
         * @param find_value The value to search for
         * @param replace_value The value to replace find_value with
         * @param occurences Replace only the first N occurences. If 0 (default), it will replace all occurences.
         * @param modify_inplace A boolean indicating if you want to overwrite the original data set. By default it's false.
         * @return A copy of the data set will the cell values replaced according to the specified find_value and replace_value. If modify_inplace = true, the original data set will be overwritten. 
         */
        DataSet replace(DataSetType find_value, DataSetType replace_value, size_t occurences = 0, bool modify_inplace = false);

        

        /**
         * @brief Sample a data set with or without replacement.
         * 
         * @param n The number of observations to sample. If sample_with_replacement = false, n must be <= the total rows of the data set.
         * @return A new data set with the sampled rows.
         */
        DataSet sample(size_t n, bool sample_with_replacement = false);



        /**
         * @brief Append ("glue") two data sets together.
         * @note This is NOT the same thing as a join. We are simply taking two data sets and "gluing" them together as long as the row or column sizes match.
         * 
         * @param other_data The other data set to append with.
         * @param type Append data along rows ('r', default) or columns ('c'). If appending along rows, the data set will grow vertically. If appending on columns, it will grow horizontally.
         * @param modify_inplace A boolean indicating if you want to overwrite the original data set. By default it's false.
         * @return A copy of the data set appended with the other data set. If modify_inplace = true, the original data set will be overwritten. 
         */
        DataSet append(DataSet const& other_data, char type = 'r', bool modify_inplace = false);



        /**
         * @brief Count the number of null values present in the data set.
         * 
         * @param null_value Specify a specific null value such as "NA", "NaN", etc. By default it searches for blank strings "".
         * @return The count of null values present in the data set according to the specified null_value. 
         */
        size_t count_na(std::string const& null_value = "");



        /**
         * @brief Print the head of the data set to the console.
         * 
         * @param rows How many rows you would like to display. Set to 10 by default.
         */
        void head(size_t rows = 10);



        /**
         * @brief Split data set into two subsets, training and testing, according to a test_ratio.
         * 
         * @param test_ratio A double between 0 and 1 indicating the proportion of rows to go into test_data. The remaining will go into train_data.
         * @param train_data The train data set passed by reference. This can be an empty DataSet object, e.g `DataSet train_data;`
         * @param test_data The test data set passed by reference. This can be an empty DataSet object, e.g `DataSet test_data;`
         */
        void split_data(double test_ratio, DataSet &train_data, DataSet &test_data);



        /**
         * @brief Print common descriptive statistics about the data set to the console.
         * 
         */
        void describe();



        /**
         * @brief Rename a set of columns.
         * @note If the any of the old column names passed are not found in the original data set, an exception will be thrown.
         * @param old_new_column_names An unordered_map<string, string> where the key is the old column name and value is the new column name.
         */
        void rename(std::unordered_map<std::string, std::string> const& old_new_column_names);



    private:
        // vector of column names (i.e headers)
        std::vector<std::string> column_names;

        // vector to store the data set
        // I'm using the 1D vector trick to mimic a 2D matrix
        std::vector<DataSetType> data;

        // total rows/columns in the data set
        size_t row_count, column_count;
};
#endif