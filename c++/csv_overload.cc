#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

// csv class to write contents to the buffer
class csv_class {
    private:
        std::vector<std::string> rows; // list of rows
        std::string cur_buf; // current row buffer
        FILE *csv;
    public:
        // ctor
        csv_class() { }

        // dtor
        ~csv_class() { }

        // create csv file
        int create_csv(std::string name);

        // write data into new column
        void new_col(void);

        // append string
        void append(std::string var, bool last);

        // append double
        void append(double var, bool last);

        // append int
        void append(int var, bool last);

        // write contents of the buffer and reset the buffer
        void write_csv();

        // close the csv file
        void close_csv();
};

int csv_class::create_csv(std::string name)
{
    //create a csv file
    csv = fopen(name.c_str(), "w");
    if (csv == nullptr) {
        return -1;
    }

    return 0;
}

void csv_class::new_col(void)
{
    // write a row to the row list
    rows.push_back(cur_buf);

    // clear current buffer
    cur_buf.clear();
}

void csv_class::append(std::string var, bool last)
{
    cur_buf += var;

    // if its not a last item in the row then append ',' to it

    if (!last)
        cur_buf += ",";
}

void csv_class::append(double var, bool last)
{
    cur_buf += std::to_string(var);

    if (!last)
        cur_buf += ",";
}

void csv_class::append(int var, bool last)
{
    cur_buf += std::to_string(var);

    if (!last)
        cur_buf += ",";
}


void csv_class::write_csv()
{
    std::vector<std::string>::const_iterator it;

    // flush all into the row list before writing to disk
    rows.push_back(cur_buf);

    for (it = rows.begin(); it != rows.end(); it ++) {
        fprintf(csv, "%s\n", (*it).c_str());
    }
}

void csv_class::close_csv()
{
    fclose(csv);
}

int main()
{
    csv_class csv;

    csv.create_csv("test.csv");

    csv.append("name", 0);
    csv.append("age", 0);
    csv.append("height", 1);

    csv.new_col();

    csv.append("dev", 0);
    csv.append(29, 0);
    csv.append(6.2, 1);

    csv.write_csv();

    csv.close_csv();
}
