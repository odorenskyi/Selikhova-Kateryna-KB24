#include <iostream>
#include <cassert>
#include "../../Software/include/ModulesSelikhova.h"

int main() {
    assert(countBinaryZerosOrOnes(0) == 16);
    assert(countBinaryZerosOrOnes(1) == 15);
    assert(countBinaryZerosOrOnes(2) == 15);
    assert(countBinaryZerosOrOnes(3) == 14);
    assert(countBinaryZerosOrOnes(10) == 13);
    assert(countBinaryZerosOrOnes(65535) == 16);
    std::cout << "Тести для countBinaryZerosOrOnes пройшли успішно!" << std::endl;
    return 0;
}
