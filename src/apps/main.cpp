#include <iostream>
#include "common/resistor.h"

int main() {

    // Create different resistor
    // default
    inf3c::Resistor* a = new inf3c::Resistor();
    // argument with int
    inf3c::Resistor* b = new inf3c::Resistor(100);
    // argument with std::vector< std::string >
    std::vector< std::string > input_vec_string;
    input_vec_string.push_back("red"); 
    input_vec_string.push_back("red"); 
    input_vec_string.push_back("red");
    inf3c::Resistor* c = new inf3c::Resistor(input_vec_string);

    // Make some show for the different resistance
    a->show_resistor_int();
    a->show_resistor_string();
    b->show_resistor_int();
    b->show_resistor_string();
    c->show_resistor_int();
    c->show_resistor_string();

    // Reaffect the resistor a using the set function and display in the meanwhile
    a->set_resistor_int(220000);
    a->show_resistor_int();
    a->show_resistor_string();
    input_vec_string[1] = "blue";
    b->set_resistor_string(input_vec_string);
    b->show_resistor_int();
    b->show_resistor_string();

    return 0;
}
