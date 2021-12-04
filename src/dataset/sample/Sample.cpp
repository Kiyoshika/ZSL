#include "../../include/dataset/DataSet.hpp"
#include <unordered_map>
#include <time.h>

template class DataSet<double>;
template class DataSet<int>;
template class DataSet<std::string>;

template <typename DataSetType>
DataSet<DataSetType> DataSet<DataSetType>::sample(size_t n, bool sample_with_replacement)
{
    // get new random seed
    srand(time(NULL));

    DataSet<DataSetType> sampled_data(n, this->column_count);
    if (!sample_with_replacement && n > this->row_count)
    {
        throw std::invalid_argument("If not sampling with replacement, n must be less than or equal to the amount of rows in your data set.");
    }

    // map to keep track of what indices were used
    // only applies if sample_with_replacement = true
    std::unordered_map<size_t, bool> used_index_map;

    size_t samples_drawn = 0;
    size_t drawn_index;
    while (samples_drawn < n)
    {

        drawn_index = rand() % this->row_count;

        // if NOT sampling with replacement, make sure index hasn't already been used
        if (!sample_with_replacement && used_index_map.find(drawn_index) == used_index_map.end())
        {
            sampled_data.set_row(samples_drawn, this->get_row(drawn_index));
            samples_drawn++;
            used_index_map[drawn_index] = true;
        }

        if (sample_with_replacement)
        {
            sampled_data.set_row(samples_drawn, this->get_row(drawn_index));
            samples_drawn++;
        }
    }

    return sampled_data;

}