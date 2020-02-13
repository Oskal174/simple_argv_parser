#include <iostream>

#include <parser.h>

int main(int argc, char* argv[])
{
    simple_argv_parser::option<int> o("name", "desc", 32);
    return 0;
}
