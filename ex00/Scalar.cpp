#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

#include "Scalar.hpp"

Scalar::~Scalar( void ) {}

Scalar::Scalar( char* arg ) : _arg(arg), _str(arg), _count(0) {
	if (_str.length() == 3 && _arg[0] == 39 && _arg[2] == 39) {
		this->_n = static_cast<double>(_arg[1]);
		return ;
	}
	else {
		int len = _str.length();
		int i = 0;
		while ( i < len && _arg[i] == '0' ){ 
			i++; 
		}
		while ( i < len && isdigit(_arg[i])){
			i++; 
			_count++;
		}
	}
	this->_n = std::atof(arg);
}

Scalar::Scalar( const Scalar &tocopy )  : _arg(tocopy.getArg())  {}

Scalar& Scalar::operator = (const Scalar & tocopy ) {
	return (*this);
}

char* Scalar::getArg() const {
    return (this->_arg);
}

int Scalar::getCount() const {
    return (this->_count);
}

const char* Scalar::noDisplayable::what() const throw()
{
	return ("Non displayable");
}

const char* Scalar::impossible::what() const throw()
{
	return ("impossible");
}

char Scalar::toChar() {
	if (_str.length() == 3 && _arg[0] == 39 && _arg[2] == 39) {
		this->_n = static_cast<double>(_arg[1]);}
	if (_n >= 0 && _n <= 255){
		if (_n >= 32 && _n <= 126){
			char c = static_cast<char>(_n);
    		return (c);
		}
		throw Scalar::noDisplayable();
	}
	throw Scalar::impossible();
}

int Scalar::toInt(){
	if (_str.length() == 3 && _arg[0] == 39 && _arg[2] == 39) {
		this->_n = static_cast<double>(_arg[1]);
		return (static_cast<int>(_n));
	}
	if (_str.compare(0, _str.length(), "nan") == 0 || \
	_str.compare(0, _str.length(), "inf") == 0 || \
	_str.compare(0, _str.length(), "+inf") == 0 || \
	_str.compare(0, _str.length(), "-inf") == 0 || \
	_str.compare(0, _str.length(), "nanf") == 0 || \
	_str.compare(0, _str.length(), "inff") == 0 || \
	_str.compare(0, _str.length(), "+inff") == 0 || \
	_str.compare(0, _str.length(), "-inff") == 0 ||
	_n < INT_MIN || _n > INT_MAX )
		throw Scalar::impossible();
	// for (int len = _str.length() - 2; len >= 1; --len ){
	// 	if (!isdigit(_arg[len]))
	// 		throw Scalar::impossible();
	// }
	// if (!isdigit(_arg[_str.length() - 1]) && _arg[_str.length() - 1] != 'f')
	// 	throw Scalar::impossible();
	// if (!isdigit(_arg[0]) && _arg[0] != '-')
	// 	throw Scalar::impossible();
    return (static_cast<int>(_n));
}

float Scalar::toFloat(){
	if (_str.length() == 3 && _arg[0] == 39 && _arg[2] == 39) {
		this->_n = static_cast<double>(_arg[1]);
		return (static_cast<float>(_n));
	}
	if (_str.compare(0, _str.length(), "nan") == 0 || \
	_str.compare(0, _str.length(), "inf") == 0 || \
	_str.compare(0, _str.length(), "+inf") == 0 || \
	_str.compare(0, _str.length(), "-inf") == 0 || \
	_str.compare(0, _str.length(), "nanf") == 0 || \
	_str.compare(0, _str.length(), "inff") == 0 || \
	_str.compare(0, _str.length(), "+inff") == 0 || \
	_str.compare(0, _str.length(), "-inff") == 0 ) {
		this->_n = std::atof(_arg);
		return (static_cast<float>(_n));
	}
	// for (int len = _str.length() - 2; len >= 1; --len ){
	// 	if (!isdigit(_arg[len]))
	// 		throw Scalar::impossible();
	// }
	// if (!isdigit(_arg[_str.length() - 1]) && _arg[_str.length() - 1] != 'f')
	// 	throw Scalar::impossible();
	// if (!isdigit(_arg[0]) && _arg[0] != '-')
	// 	throw Scalar::impossible();
    return (static_cast<float>(_n));
}
        
double Scalar::toDouble(){
	if (_str.length() == 3 && _arg[0] == 39 && _arg[2] == 39) {
		this->_n = static_cast<double>(_arg[1]);
		return (this->_n);
	}
	if (_str.compare(0, _str.length(), "nan") == 0 || \
	_str.compare(0, _str.length(), "inf") == 0 || \
	_str.compare(0, _str.length(), "+inf") == 0 || \
	_str.compare(0, _str.length(), "-inf") == 0 || \
	_str.compare(0, _str.length(), "nanf") == 0 || \
	_str.compare(0, _str.length(), "inff") == 0 || \
	_str.compare(0, _str.length(), "+inff") == 0 || \
	_str.compare(0, _str.length(), "-inff") == 0 ) {
		this->_n = std::atof(_arg);
		return (this->_n);
	}
	// for (int len = _str.length() - 2; len >= 1; --len ){
	// 	if (!isdigit(_arg[len]) )
	// 		throw Scalar::impossible();
	// }
	// if (!isdigit(_arg[_str.length() - 1]) && _arg[_str.length() - 1] != 'f')
	// 	throw Scalar::impossible();
	// if (!isdigit(_arg[0]) && _arg[0] != '-')
	// 	throw Scalar::impossible();
    return (this->_n);
}
