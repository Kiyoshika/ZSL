#ifndef PRINTTABLE_HPP
#define PRINTTABLE_HPP
#include <iostream>
#include <vector>

// A class to help with printing data sets to the console
// in a table format. All column sizes will be fixed to 16
// characters (two tab lengths). Any strings past 16 characters
// will have the last three characters replaced with "..."
class PrintTable
{
    public:
        template <typename DataSetType>
        static void print_table(DataSet<DataSetType> const& dataset, bool numeric = false)
        {

            // print headers first

            for (auto const& col : dataset.get_column_names())
            {
                print_horizontal_line();
            }

            std::cout << "-\n";

            std::string text;
            std::cout << "| ";
            for (auto const& col : dataset.get_column_names())
            {
                text = col;
                if (text.length() > 16)
                {
                    text = text.substr(0, 12);
                    text += "...";
                }
                else if (text.length() < 16)
                {
                    uint8_t whitespace = 15 - text.length();
                    std::string whitespace_str(whitespace, ' ');
                    text += whitespace_str;
                }

                std::cout << text << " | ";
            }
            std::cout << "\n";
            for (auto const& col : dataset.get_column_names())
            {
                print_horizontal_line();
            }
            std::cout << "-\n";
        }

    private:
        static void print_horizontal_line()
        {
            std::cout << "------------------";
        }

};
#endif