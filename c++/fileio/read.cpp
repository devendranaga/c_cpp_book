/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 * 
 * License Apache
 */
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::ifstream fp;
    std::string line;

    if (argc != 2) {
        std::cout << argv[0] << " filename" << std::endl;
        return -1;
    }

    fp.open(argv[1]);

    if (!fp) {
        return -1;
    }

    while (!fp.eof()) {
        std::getline(fp, line);

        std::cout << "line: " << line << std::endl;
    }

    fp.close();
}
