/**
 * Written by DevNaga <devendra.aaru@gmail.com>
 *
 * Copyright All rights reserved DevNaga. Apached 2.0 License
 */
#include <iostream>
#include <list>
#include <string>

// linked list class..
//
// wrapper around the std::list<int>
class linked_list_class {
    private:
        std::list<int> i; // 
    public:
        void add_element(int i);
        void remove_element(int i);
        void print_elements();
        bool search_element(int i);
        void delete_all();
        int element_count();
};

// add an element in the linked list
void linked_list_class::add_element(int elem)
{
    i.push_back(elem);
}

// remove an element in the linked list
void linked_list_class::remove_element(int elem)
{
    i.remove(elem);
}

// print all the elements of linked list
void linked_list_class::print_elements()
{
    std::list<int>::iterator it;

    for (it = i.begin(); it != i.end(); it ++) {
        std::cout << "elem: " << *it << std::endl;
    }
}

// find and check if the element exist in linked list
bool linked_list_class::search_element(int elem)
{
    std::list<int>::iterator it;

    for (it = i.begin(); it != i.end(); it ++) {
        if (elem == *it) {
            return true;
        }
    }

    return false;
}

// delete all the elements in the linked list
void linked_list_class::delete_all()
{
    i.erase(i.begin(), i.end());
}

// count the number of elements in the linked list
int linked_list_class::element_count()
{
    return i.size();
}

int main(int argc, char **argv)
{
    linked_list_class lc;
    int i;

    std::cout << "add elements in the list " << std::endl;
    for (i = 1; i <= argc - 1; i ++) {
        lc.add_element(std::stoi(argv[i]));
    }

    std::cout << "printing elements >>>>>>>>>>>>>>>> : Element count is " << lc.element_count() << std::endl;

    lc.print_elements();

    std::cout << "search and remove an element " << std::endl;
    if (lc.search_element(3)) {
        lc.remove_element(3);
    }

    std::cout << "printing elements >>>>>>>>>>>>>>>>> : Element count is " << lc.element_count() << std::endl;

    lc.print_elements();

    lc.delete_all();

    std::cout << "clear off linked list" << std::endl;
    std::cout << "printing elements >>>>>>>>>>>>>>>>> : Element count is " << lc.element_count() << std::endl;
    lc.print_elements();
}
