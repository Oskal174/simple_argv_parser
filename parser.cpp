#include <parser.h>

namespace simple_argv_parser {

void parser::add_str_option(option<std::string> opt)
{
    this->str_opts["--" + opt.name] = opt;
}

void parser::add_uint_option(option<uint64_t> opt)
{
    this->uint_opts["--" + opt.name] = opt;
}

void parser::add_int_option(option<int64_t> opt)
{
    this->int_opts["--" + opt.name] = opt;
}

void parser::add_float_option(option<float> opt)
{
    this->float_opts["--" + opt.name] = opt;
}

std::string parser::help() const
{
    std::stringstream ss;
    ss << "Arguments:" << std::endl;
    for (auto &opt: this->str_opts)
    {
        ss << opt.first << " [string] (default: " << opt.second.default_value << ") " << opt.second.description << std::endl; 
    }

    for (auto &opt: this->uint_opts)
    {
        ss << opt.first << " [uint] (default: " << opt.second.default_value << ") " << opt.second.description << std::endl; 
    }

    for (auto &opt: this->int_opts)
    {
        ss << opt.first << " [int] (default: " << opt.second.default_value << ") " << opt.second.description << std::endl; 
    }

    for (auto &opt: this->float_opts)
    {
        ss << opt.first << " [float] (default: " << opt.second.default_value << ") " << opt.second.description << std::endl; 
    }

    return ss.str();
}

void parser::parse_argv(int argc, char* argv[])
{
    this->str_opts["--help"] = option<std::string>("help", "This help", "");
    
    std::map<std::string, std::string> argv_name_value;
    for (int i = 1; i < argc; i++)
    {
        std::string argv_str = std::string(argv[i]);
        if (argv_str.substr(0, 2) == "--")
        {
            if (i + 1 >= argc)
            {
                argv_name_value[argv_str] = "";
                continue;
            }

            std::string next_argv = argv[i + 1];
            if (next_argv.substr(0, 2) == "--")
            {
                argv_name_value[argv_str] = "";
                continue;
            }
            else
            {
                argv_name_value[argv_str] = next_argv;
                i++;
                continue;
            }
        }
    }

    for (auto &argv_it : argv_name_value)
    {
        std::cout << argv_it.first << " : " << argv_it.second << std::endl;
        if (this->str_opts.find(argv_it.first) != this->str_opts.end())
        {
            this->str_opts[argv_it.first].value = argv_it.second;
        }

        if (this->uint_opts.find(argv_it.first) != this->uint_opts.end())
        {
            this->uint_opts[argv_it.first].value = std::stoull(argv_it.second);
        }

        if (this->int_opts.find(argv_it.first) != this->int_opts.end())
        {
            this->int_opts[argv_it.first].value = std::stoll(argv_it.second);
        }

        if (this->float_opts.find(argv_it.first) != this->float_opts.end())
        {
            this->float_opts[argv_it.first].value = std::stof(argv_it.second);
        }
    }
}


template <typename T>
T get(parser &cli, std::string name)
{
    name = "--" + name;
    if (cli.str_opts.find(name) != cli.str_opts.end())
    {
        return cli.str_opts[name].value;
    }

    if (cli.uint_opts.find(name) != cli.uint_opts.end())
    {
        return cli.uint_opts[name].value;
    }

    if (cli.int_opts.find(name) != cli.int_opts.end())
    {
        return cli.int_opts[name].value;
    }

    if (cli.float_opts.find(name) != cli.float_opts.end())
    {
        return cli.float_opts[name].value;
    }
}

} // simple_argv_parser