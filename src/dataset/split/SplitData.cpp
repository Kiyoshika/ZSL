#include "../../include/dataset/DataSet.hpp"
#include <unordered_map>
#include <time.h>
#include <math.h>

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
void DataSet<DataSetType>::split_data(DataSet &train_data, DataSet &test_data, double test_ratio)
{
    // set random seed
    srand(time(NULL));

    if (test_ratio < 0 || test_ratio > 1) { throw std::invalid_argument("test_ratio must be between 0 and 1."); }

    // since doubles usually slightly under-represent (0.2999 instead of 0.3)
    // I use the ceil() function to get over this
    size_t test_size = ceil(this->row_count * test_ratio);
    size_t train_size = this->row_count - test_size;

    train_data.resize(train_size, this->column_count);
    test_data.resize(test_size, this->column_count);

    std::cout << test_size << "\n\n";
    std::cout << test_data.count_rows() << "\n\n";

    for (auto col : this->get_column_names())
    {
        train_data.add_column_name(col);
        test_data.add_column_name(col);
    }

    std::unordered_map<size_t, bool> used_index_map;

    // sample for test data
    size_t test_samples_drawn = 0;
    size_t rand_idx;
    while (test_samples_drawn < test_size)
    {
        rand_idx = rand() % this->row_count;
        if (used_index_map.find(rand_idx) == used_index_map.end())
        {
            test_data.set_row(test_samples_drawn, this->get_row(rand_idx));
            test_samples_drawn++;
            used_index_map[rand_idx] = true;
        }
    }

    // iterate over remaining indices and allocate them to training data
    size_t train_samples_drawn = 0;
    for (size_t row = 0; row < this->row_count; ++row)
    {
        if (used_index_map.find(row) == used_index_map.end())
        {
            train_data.set_row(train_samples_drawn, this->get_row(row));
            train_samples_drawn++;
        }
    }
}