#include <iostream>
#include "human.h"
#include "student.h"

int main(int argc, char *argv[])
{
    student *stud = new student("Сидоров", "Петр", "Иванович", 10);
    
    std::cout << stud->get_full_name() << std::endl;
    std::cout << stud->get_score() << std::endl;
    return 0;
}