#pragma once
# ifndef __Scalar__H__
# define __Scalar__H__
# include <iostream>
# include <string>
# include <exception>

class Scalar {
    private:
        char*   		_arg;
		double			_n;
		std::string		_str;
		int				_count;

	public:

        class noDisplayable : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class impossible : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		Scalar( char* arg );
		virtual ~Scalar( void );
		Scalar( const Scalar &tocopy );
		Scalar& operator = (const Scalar &tocopy );

        char* getArg() const;
		int getCount() const;

        char toChar();
        int toInt();
        float toFloat();
        double toDouble();
};

#endif