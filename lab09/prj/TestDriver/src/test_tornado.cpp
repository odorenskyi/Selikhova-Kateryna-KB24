#include <iostream>
#include <cassert>
#include "../../Software/include/ModulesSelikhova.h"

int main() {
    assert(getTornadoCategory(100) == "F0 (38,8%)");
    assert(getTornadoCategory(150) == "F1 (35,8%)");
    assert(getTornadoCategory(200) == "F2 (19,4%)");
    assert(getTornadoCategory(300) == "F3 (4,9%)");
    assert(getTornadoCategory(350) == "F4 (1,1%)");
    assert(getTornadoCategory(450) == "F5 (менше 0,1%)");
    assert(getTornadoCategory(50) == "Не класифіковано");
    std::cout << "Тести для getTornadoCategory пройшли успішно!" << std::endl;
    return 0;
}
