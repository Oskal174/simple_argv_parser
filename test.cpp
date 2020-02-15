#include <iostream>
#include <string>

#include <parser.h>


int main(int argc, char* argv[])
{
    simple_argv_parser::parser cli;

    cli.add_str_option({"host", "This is host", "127.0.0.1"});
    cli.add_uint_option({"port", "Port for any test connection", 3306});
    cli.add_str_option({"user", "Database user", "root"});
    cli.add_float_option({"freq", "Frequency", 868.1514});
    cli.add_int_option({"diff", "difffff", -115});

    cli.parse_argv(argc, argv);

    std::cout << cli.help() << std::endl;

    std::string host, user;
    int32_t diff;
    uint32_t port; 
    float freq;
    
    if (cli.is_set_option("host"))
    {
        host  = cli.get_str_option("host");
        std::cout << host << std::endl;
    }

    if (cli.is_set_option("port"))
    {
        port = cli.get_uint_option("port");
        std::cout << port << std::endl;
    }

    if (cli.is_set_option("user"))
    {
        user = cli.get_str_option("user");
        std::cout << user << std::endl;
    }

    if (cli.is_set_option("freq"))
    {
        freq = cli.get_uint_option("freq");
        std::cout << freq << std::endl;
    }

    if (cli.is_set_option("diff"))
    {
        diff = cli.get_int_option("diff");
        std::cout << diff << std::endl;
    }

    return 0;
}
