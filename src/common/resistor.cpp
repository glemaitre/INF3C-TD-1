#include <algorithm>
#include <cmath>
#include "resistor.h"

namespace inf3c {

    // Initialise the static const variables
    const static std::vector< std::string > color_code { "black", "brown", "red", "orange", 
	    "yellow", "green", "blue", "violet", "grey", "white" };

    // Initialize with the smallest resistance possible
    Resistor::Resistor() : 
	resistor_value(10)
    {
	// Nothing to assign
    }

    // Constructor with initialisation -> string
    Resistor::Resistor( std::vector< std::string > val) :
	resistor_value( cvt_color_ohm(val) )
    {
	// Nothing to assign
    }

    // Comstructor with initialisation -> int
    Resistor::Resistor( const int val ) :
	resistor_value( val )
    {
	// Nothing to assign
    }

    // Constructor by recopy
    Resistor::Resistor( const Resistor& val ) :
	resistor_value( val.resistor_value )    
    {
	// Nothing to assign
    }

    Resistor::~Resistor() 
    {
	// Nothing to destroy
    }

    // Show the value of the resistance using string
    void Resistor::show_resistor_string( void ) const 
    {
	// We need to conver the value of the resistance into a vector of string and show it 
	auto val = get_resistor_string();
	// Show each value of the vector
	for (auto it = val.begin() ; it != val.end() ; ++it)
	    std::cout << ' ' << *it;
	std::cout << std::endl;
    }

    std::vector< std::string > cvt_ohm_color( int val )
    {
	std::vector< std::string > output_string;
    
	// Convert the input into a vector of digit
	std::vector< int > digits;
	while(val)
	{
	    digits.push_back( val % 10 );
	    val /= 10;
	}
    
	// Make the same operation for the two last integers
	for (int i = 0 ; i < 2 ; ++i)
	{
	    // Get the first color
	    output_string.push_back( color_code[digits.back()] );
	    // Remove the value from the digits vector since that we already read it
	    digits.pop_back();
	}

	// Get the number of zero
	output_string.push_back( color_code[digits.size()] );
    
	return output_string;
    }

    int cvt_color_ohm( std::vector< std::string > val )
    {
	// We will save the ouput first into a string and then convert it to integer
	std::string num = "";

	// Reverse the order of the vector to be in the same configuration as before
	std::reverse(val.begin(), val.end());

        // Make the same operation for the two last color code
	for (int i = 0 ; i < 2 ; ++i) 
	{
	    // Search for the string and find the corresponding index
	    auto it_color = std::find( color_code.begin(), color_code.end(), val.back() );
	    if ( it_color != std::end(color_code) ){
		// Compute the index corresponding the iterator found
		auto idx = std::distance(color_code.begin(), it_color);
		num += std::to_string( idx );
		val.pop_back();
	    }	    
	    else
		std::cout << "Error: the color specified is unknown!!!" << std::endl;
	}

	// Check the last color and multiply with the previous string
	int output_int = std::stoi(num);
	// Search for the string and find the corresponding index
	auto it_color = std::find( color_code.begin(), color_code.end(), val.back() );
	if ( it_color != std::end(color_code) ){
	    // Compute the index corresponding the iterator found
	    auto idx = std::distance(color_code.begin(), it_color);
	    output_int *= (int) std::pow(1., idx);
	}	    
	else
	    std::cout << "Error: the color specified is unknown!!!" << std::endl;

	return output_int;
    }

}
    
