#ifndef __RESISTOR_H_INCLUDED__
#define __RESISTOR_H_INCLUDED__

#include <string>
#include <vector>

class Resistor 
{

public:

    Resistor();
    ~Resistor();

    // Get and set resistor using integer
    inline int get_resistor_int() { return resistor_value; }
    inline void set_resistor_int( const int val) { resistor_value = val; }

    // Get and set but defined with some strings
    std::vector< std::string > get_resistor_string();
    void set_resistor_string( const std::vector< const std::string > val );

private:
    
    // Keep track of the resistance as an integer
    int resistor_value;

    // Table for

    // Function to convert from ohm to color
    const std::vector< const std::string > cvt_ohm_color( const int val ) const;
    // Function to convert from color to ohm
    const int cvt_color_ohm( const std::vector< const std::string > val ) const;

};

#endif // __RESISTOR_H_INCLUDED__
