#include <iostream>
#include "common/resistor.h"

int main() {

    // Create different resistor
    // default
    Resistor* a = new Resistor();
    // argument with int
    Resistor* b = new Resistor(100);
    // argument with std::vector< std::string >
    std::vector< std::string > input_vec_string;
    input_vec_string.push_back("red"); 
    input_vec_string.push_back("red"); 
    input_vec_string.push_back("red");
    Resistor* c = new Resistor(input_vec_string);

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

    // Make some conversion without the need of a specific objects
    std::cout << Resistor::cvt_color_ohm( input_vec_string ) << std::endl;
    std::vector< std::string > code_clr = Resistor::cvt_ohm_color(8900);
    for (auto cd_clr_it = code_clr.begin(); cd_clr_it != code_clr.end(); ++cd_clr_it) // Go throgh the vector
	std::cout << *cd_clr_it << " ";
    std::cout << std::endl;

    return 0;
}
