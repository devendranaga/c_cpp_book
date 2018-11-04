/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 * 
 * License Apache
 */
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::string input;
    std::ofstream fp;

    if (argc != 2) {
        std::cout << argv[0] << " filename" << std::endl;
        return -1;
    }
    
    fp.open(argv[1]);
    if (!fp) {
        std::cout << "failed to open " << argv[1] << std::endl;
        return -1;
    }

    fp << "Hello there" << std::endl;

    fp.close();
}
