/**
 * Author: Devendra Naga (devendra.aaru@gmail.com)
 * 
 * License apache
 */
#include <iostream>
#include <list>

// writes our class to print list elements
class list_class {
    public:
        void list_print(std::list<int> i)
        {
            std::list<int>::const_iterator t;

            for (t = i.begin(); t != i.end(); t ++) {
                std::cout << *t << "->";
            }
            std::cout << std::endl;
        }

        void list_cprint(std::list<int> i)
        {
            std::list<int>::const_iterator t;

            for (t = i.cbegin(); t != i.cend(); t ++) {
                std::cout << *t << "->";
            }
            std::cout << std::endl;
        }

        void list_rprint(std::list<int> i)
        {
            std::list<int>::const_reverse_iterator t;

            for (t = i.rbegin(); t != i.rend(); t ++) {
                std::cout << *t << "->";
            }
            std::cout << std::endl;
        }
};

int main()
{
    std::list<int> i {1, 2, 3, 4, 5}; // setting up the list initialisation
    std::list<int>::const_iterator t;
    std::list<int>::const_reverse_iterator rt;

    std::list<int> new_list {4, 1, 2, 4};

    // value and ptr for testing of the contents after i being modified
    std::list<int> i_copy = i; // copy constructor ?
    std::list<int> *i_ptr = &i; // assign the address of the old list

    list_class l;

    //add at front
    i.push_front(4);
    //add at end
    i.push_back(8);

    std::cout << "print from begin" << std::endl;
    l.list_print(i);

    std::cout << "print from cbegin" << std::endl;
    l.list_cprint(i);

    std::cout << "print from rbegin" << std::endl;
    l.list_rprint(i);

    std::cout <<"front element:" << i.front() << std::endl;
    std::cout <<"last element:" << i.back() << std::endl;

    std::cout << "list empty: " << (i.empty() ? "Yes" : "No") << std::endl;

    std::cout << "list element number: " << i.size() << std::endl;

    std::cout << "list max_size: " << i.max_size() << std::endl;

    std::cout << "clearing list" << std::endl;

    i.clear();

    std::cout << "list count: " << i.size() << std::endl
              << "list empty: " << (i.empty() ? "Yes" : "No") << std::endl;

    i.assign(new_list.begin(), new_list.end());

    std::cout << "print the list i" << std::endl;
    l.list_print(i);

    std::cout << "print the list i_copy" << std::endl;
    l.list_print(i_copy);

    std::cout << "print the list i_ptr" << std::endl;
    l.list_print(*i_ptr);

    std::cout << "sort in ascending order" << std::endl;
    // sorts them in ascending order
    i.sort(std::greater<int>());

    std::cout << "print list i" << std::endl;
    l.list_print(i);
}
