#include <iostream>
#include <string>

#include <parser.h>

int main(int argc, char* argv[])
{
    simple_argv_parser::parser cli;

    cli.add_uint_option({"port", "Port for any test connection", 3306});
    cli.add_str_option({"host", "This is host", "127.0.0.1"});
    
    cli.parse_argv(argc, argv);

    std::cout << cli.help() << std::endl;

    std::string host = simple_argv_parser::get<std::string>(cli, "host");

    return 0;
}
