
#include <iostream>
#include "common/resistor.h"

int main(int argc, char *argv[]) {

    // Create a dummy object
    Resistor a;

    std::cout << a.get_resistor_int() << std::endl;

    return 0;
}
