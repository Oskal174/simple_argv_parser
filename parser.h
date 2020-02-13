#include <string>
#include <vector>

namespace simple_argv_parser
{
    template <typename T>
    class option
    {
    public:
        option(std::string name, std::string description, T default_value)
            : name(name)
            , description(description)
            , default_value(default_value)
            , is_default_set(true)
        {}

        option(std::string name, std::string description)
            : name(name)
            , description(description)
            , is_default_set(false)
        {}

    private:
        std::string name;
        std::string description;
        T default_value;

        bool is_default_set;
    };

    class parser
    {
    public:
        template <typename T>
        void add_option(option<T> opt);

        void parse_argv(int argc, char* argv[]);
    
    private:
        
    };
}
