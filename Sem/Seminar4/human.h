#include <string>
class human
{
    std::string name;
    std::string last_name;
    std::string second_name;
    
    public:
    human(std::string last_name, std::string name, std::string second_name);
    std::string get_full_name();
};