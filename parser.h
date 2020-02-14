#include <typeinfo>
#include <type_traits>
#include <cstdint>
#include <string>
#include <sstream>
#include <map>
#include <iostream>


namespace simple_argv_parser {

using std::is_same;

class parser;

template <typename T>
class option
{
public:
    option() {}

    option(std::string name, std::string description, T default_value)
        : name(name)
        , description(description)
        , default_value(default_value)
        , value(default_value)
    {}

    option(std::string name, std::string description)
        : name(name)
        , description(description)
    {}

    friend parser;

private:
    std::string name;
    std::string description;
    T default_value;
    T value;

    bool is_default_set;
};

class parser
{
    typedef std::map<std::string, option<std::string>> str_opts_type;
    typedef std::map<std::string, option<uint64_t>> uint_opts_type;
    typedef std::map<std::string, option<int64_t>> int_opts_type;
    typedef std::map<std::string, option<float>> float_opts_type;

public:
    void add_str_option(option<std::string> opt);
    void add_uint_option(option<uint64_t> opt);
    void add_int_option(option<int64_t> opt);
    void add_float_option(option<float> opt);

    std::string help() const;

    /// TODO: add_options()
    /// TODO: add_option() any
    /// TODO: operator []

    void parse_argv(int argc, char* argv[]);

    template <typename T>
    friend T get(parser &cli, std::string name);

private:
    str_opts_type str_opts;
    uint_opts_type uint_opts;
    int_opts_type int_opts;
    float_opts_type float_opts;
};

} // simple_argv_parser
