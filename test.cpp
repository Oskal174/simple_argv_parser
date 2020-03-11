#include <iostream>
#include <string>

#include <argv_parser.h>


int main(int argc, char* argv[])
{
    simple_argv_parser::parser cli;

    //cli.add_option({"host", "This is host", std::string("127.0.0.1")});
    //cli.add_option({"port", "Port for any test connection", 3306});
    //cli.add_option({"user", "Database user", "root"});
    //cli.add_option({"freq", "Frequency", 868.1514});
    //cli.add_option({"diff", "difffff", -115});
    //cli.add_option({"special", "no default value", typeid(int)});

    cli.add_options(
    {
        {"host", "This is host", std::string("127.0.0.1")},
        {"port", "Port for any test connection", 3306},
        {"user", "Database user", "root"},
        {"freq", "Frequency", 868.1514},
        {"diff", "difffff", -115},
        {"special", "no default value", typeid(int)}
    });

    cli.parse_argv(argc, argv);

    std::cout << cli.help() << std::endl;

    std::string host, user;
    int32_t diff;
    uint32_t port; 
    float freq;
    int special;

    cli.get_option("host", host);
    std::cout << "HOST: " << host;
    
    // if (cli.is_set_option("host"))
    // {
    //     host  = cli.get_str_option("host");
    //     std::cout << host << std::endl;
    // }

    // if (cli.is_set_option("port"))
    // {
    //     port = cli.get_uint_option("port");
    //     std::cout << port << std::endl;
    // }

    // if (cli.is_set_option("user"))
    // {
    //     user = cli.get_str_option("user");
    //     std::cout << user << std::endl;
    // }

    // if (cli.is_set_option("freq"))
    // {
    //     freq = cli.get_uint_option("freq");
    //     std::cout << freq << std::endl;
    // }

    // if (cli.is_set_option("diff"))
    // {
    //     diff = cli.get_int_option("diff");
    //     std::cout << diff << std::endl;
    // }

    return 0;
}
