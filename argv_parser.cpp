#include <argv_parser.h>

namespace simple_argv_parser {

void parser::add_option(option o)
{
    this->options["--" + o.name] = o;
}

void parser::get_option(std::string name, std::string &container)
{
    std::string option_name = "--" + name;
    auto option_it = this->options.find(option_name);
    if (option_it != this->options.end())
    {
        container = std::any_cast<std::string>(*option_it);
    }
    else
    {
        throw std::runtime_error("Unknown option name: " + option_name);
    }
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
        std::string option_name = argv_it.first;
        if (this->options.find(option_name) != this->options.end())
        {
            if (this->options[option_name].value_type == typeid(int8_t)  ||
                this->options[option_name].value_type == typeid(int16_t) ||
                this->options[option_name].value_type == typeid(int32_t) ||
                this->options[option_name].value_type == typeid(int64_t))
            {
                this->options[option_name].value = std::stoll(argv_it.second.empty() ? "0" : argv_it.second);
            }
            else
            if (this->options[option_name].value_type == typeid(uint8_t)  ||
                this->options[option_name].value_type == typeid(uint16_t) ||
                this->options[option_name].value_type == typeid(uint32_t) ||
                this->options[option_name].value_type == typeid(uint64_t))
            {
                this->options[option_name].value = std::stoull(argv_it.second.empty() ? "0" : argv_it.second);
            }
            else 
            if (this->options[option_name].value_type == typeid(float) ||
                this->options[option_name].value_type == typeid(double)) 
            {
                this->options[option_name].value = std::stof(argv_it.second.empty() ? "0" : argv_it.second);
            }
            else // std::string
            {
                this->options[option_name].value = argv_it.second;
            }
        }
    }
}



} // simple_argv_parser