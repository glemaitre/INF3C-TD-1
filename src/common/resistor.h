#ifndef __RESISTOR_H_INCLUDED__
#define __RESISTOR_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>

namespace inf3c{

    // Function that can be used at the namespace level
    // Function to convert from ohm to color
    std::vector< std::string > cvt_ohm_color( int val );    
    // Function to convert from color to ohm
    int cvt_color_ohm( std::vector< std::string > val );

    class Resistor 
    {

    public:

	// List of constructor
	Resistor();
	// Constructor with arguments
	Resistor(std::vector< std::string > val);
	Resistor(const int val);
	// Constructor by recopy
	Resistor(const Resistor& val);
	// Destructor
	~Resistor();

	// Get and set resistor using integer
	inline int get_resistor_int() { return resistor_value; }
	inline void set_resistor_int( const int val) { resistor_value = val; }

	// Get and set but defined with some strings
	inline std::vector< std::string > get_resistor_string() const { 
	    return cvt_ohm_color(resistor_value); 
	}
	inline void set_resistor_string( std::vector< std::string > val ) { 
	    resistor_value = cvt_color_ohm(val); 
	}

	// Function to show the value of the resistor
	inline void show_resistor_int( void ) const { std::cout << resistor_value << std::endl; }
	void show_resistor_string( void ) const;

    private:
    
	// Keep track of the resistance as an integer
	int resistor_value;

    };

} // namespace inf3c

#endif // __RESISTOR_H_INCLUDED__
