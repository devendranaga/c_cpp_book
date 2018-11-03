/**
 * @brief - pseudorandom number generator in C++
 *
 * Written by Dev Naga <devendra.aaru@gmail.com>
 *
 * All rights reserved Dev Naga, Apache 2.0 license
 */
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

// random generator class
class rand_num_gen {
    private:
        int fd;
    public:
        rand_num_gen();
        ~rand_num_gen();
        int gen_rand(uint8_t *rand_num);
        int gen_rand(uint16_t *rand_num);
        int gen_rand(uint32_t *rand_num);
        int gen_rand(uint64_t *rand_num);
        int gen_rand(uint64_t *rand_num, uint64_t min, uint64_t max);
};

// open fd to /dev/urandom
rand_num_gen::rand_num_gen()
{
    fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0) {
        return;
    }
}

rand_num_gen::~rand_num_gen()
{
    close(fd);
}

int rand_num_gen::gen_rand(uint8_t *rand_num)
{
    int ret;

    ret = read(fd, rand_num, sizeof(*rand_num));
    if (ret > 0)
        return 0;

    return -1;
}

int rand_num_gen::gen_rand(uint16_t *rand_num)
{
    int ret;

    ret = read(fd, rand_num, sizeof(*rand_num));
    if (ret > 0)
        return 0;

    return -1;
}

int rand_num_gen::gen_rand(uint32_t *rand_num)
{
    int ret;

    ret = read(fd, rand_num, sizeof(*rand_num));
    if (ret > 0)
        return 0;

    return -1;
}

int rand_num_gen::gen_rand(uint64_t *rand_num)
{
    int ret;

    ret = read(fd, rand_num, sizeof(*rand_num));
    if (ret > 0)
        return 0;

    return -1;
}

int rand_num_gen::gen_rand(uint64_t *rand_num, uint64_t min, uint64_t max)
{
    int ret;

    if (min == max) {
        return -1;
    }

    ret = read(fd, rand_num, sizeof(*rand_num));
    if (ret > 0) {
        *rand_num = *rand_num % (max - min);
    }

    return -1;
}


int main(int argc, char **argv)
{
    rand_num_gen r;
    int i;

    if (argc != 2) {
        std::cout << argv[0] << " random number of times " << std::endl;
        return -1;
    }

    for (i = 0; i < std::stoi(argv[1]); i ++) {
        uint32_t rand_num32;
        uint64_t rand_num64;

        r.gen_rand(&rand_num32);
        r.gen_rand(&rand_num64);

        std::cout << "Rand number: (32 bits) " << rand_num32 << std::endl;
        std::cout << "Rand number: (64 bits) " << rand_num64 << std::endl;
    }
}
