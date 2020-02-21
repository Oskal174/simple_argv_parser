#include <cstdint>
#include <typeinfo>
#include <typeindex>
#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <any>


namespace simple_argv_parser {

using std::any;

class parser;

class option
{
public:
    option() : value_type(typeid(void)) {}

    option(std::string name, std::string description, any default_value)
        : name(name)
        , description(description)
        , default_value(default_value)
        , value(default_value)
        , value_type(value.type())
    {}

    option(std::string name, std::string description, std::type_index value_type)
        : name(name)
        , description(description)
        , value_type(value_type)
    {}

    friend parser;

private:
    std::string name;
    std::string description;
    any default_value;
    any value;
    std::type_index value_type;
};

class parser
{

typedef std::map<std::string, option> options_map_type;

public:
    void parse_argv(int argc, char* argv[]);

    std::string help() const;

    void add_option(option o);

    /// TODO: add_options()
    /// TODO: add_option() any
    /// TODO: operator []
    /// TODO: get_option<string>(name);

private:
    options_map_type options;
};

} // simple_argv_parser
