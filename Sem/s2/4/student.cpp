#include "human.h"
#include "student.h"
#include <string>

student::student(std::string last_name, std::string name, std::string second_name, int score):human(last_name, name, second_name)
{
    this->score = score;
}

int student::get_score()
{
    return this->score;
}