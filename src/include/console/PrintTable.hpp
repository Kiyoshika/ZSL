#ifndef PRINTTABLE_HPP
#define PRINTTABLE_HPP
#include <iostream>
#include <vector>

// A class to help with printing data sets to the console
// in a table format. All column sizes will be fixed to 15
// characters (two tab lengths). Any strings past 16 characters
// will have the last three characters replaced with "..."

// As an aside, this is pretty messy and could definitely use some cleaning,
// but for now I just want something that works.
class PrintTable
{
    public:
        static void print_table(DataSet<std::string> const& dataset, size_t rows, size_t column_width)
        {

            if (column_width < 5) { throw std::runtime_error("When setting table column width, please use a width of at least 5 characters."); }

            // if passed rows exceeds the total number of rows we have, then limit it
            // by the total rows we have. Otherwise, continue with the passed value
            rows = rows > dataset.count_rows() ? dataset.count_rows() : rows;

            // print top horizontal line

            for (auto const& col : dataset.get_column_names())
            {
                print_horizontal_line(column_width);
            }
            std::cout << "+\n";

            // print headers

            print_record(dataset.get_column_names(), column_width, true);

            // print body (will not need the top print_horizontal_line)
            for (size_t row = 0; row < rows; ++row)
            {
                print_record(dataset.get_row(row), column_width);
            }

            // print final bottom horizontal line
            for (auto const& col : dataset.get_column_names())
            {
                print_horizontal_line(column_width);
            }
            std::cout << "+\n";
        }

        

    private:
        static void print_horizontal_line(size_t column_width)
        {
            std::string prefix = "+";
            std::string line(column_width + 2, '-');
            std::cout << prefix << line;
        }

        // takes a vector of values to write as a record (row) using
        // vertical dividers (|)
        static void print_record(std::vector<std::string> const& content, size_t column_width, bool print_horizontal = false)
        {
            std::string text;
            std::cout << "| ";
            for (auto const& value : content)
            {
                text = value;
                if (text.length() > column_width)
                {
                    text = text.substr(0, column_width - 3);
                    text += "...";
                    std::cout << text << " | ";
                }
                else if (text.length() < column_width)
                {
                    uint8_t whitespace = column_width - text.length();
                    std::string whitespace_str(whitespace, ' ');
                    text += whitespace_str;
                    std::cout << text << " | ";
                }
                else
                {
                    std::cout << text << "| ";
                }
            }

            std::cout << "\n";

            if (print_horizontal)
            {
                for (auto const& value : content)
                {
                    print_horizontal_line(column_width);
                }
                std::cout << "+\n";
            }
        }

};
#endif