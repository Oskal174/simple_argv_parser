#include <argv_parser.h>

namespace simple_argv_parser {

void parser::add_option(option o)
{
    this->options["--" + o.name] = o;
}

std::string parser::help() const
{
    std::stringstream ss;
    ss << "Arguments:" << std::endl;
    
    return ss.str();
}

void parser::parse_argv(int argc, char* argv[])
{
    this->options["--help"] = option("help", "This help", "");
    
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
        if (this->options.find(argv_it.first) != this->options.end())
        {
            if (this->options[argv_it.first].value_type == typeid(int32_t))
            {
            }
        }
        // if (this->str_opts.find(argv_it.first) != this->str_opts.end())
        // {
        //     this->str_opts[argv_it.first].value = argv_it.second;
        // }

        // if (this->uint_opts.find(argv_it.first) != this->uint_opts.end())
        // {
        //     this->uint_opts[argv_it.first].value = std::stoull(argv_it.second.empty() ? "0" : argv_it.second);
        // }

        // if (this->int_opts.find(argv_it.first) != this->int_opts.end())
        // {
        //     this->int_opts[argv_it.first].value = std::stoll(argv_it.second.empty() ? "0" : argv_it.second);
        // }

        // if (this->float_opts.find(argv_it.first) != this->float_opts.end())
        // {
        //     this->float_opts[argv_it.first].value = std::stof(argv_it.second.empty() ? "0" : argv_it.second);
        // }
    }
}



} // simple_argv_parser