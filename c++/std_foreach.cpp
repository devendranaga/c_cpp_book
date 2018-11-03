/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 * 
 * License Apache
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void callback(std::string _str)
{
    std::cout << "string " << _str << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<std::string> str;
    int i;

    for (i = 1; i < argc; i ++) {
        str.push_back(std::string{argv[i]});
    }

    std::cout << "strings:" << std::endl;
    std::for_each(str.begin(), str.end(), callback);
}
