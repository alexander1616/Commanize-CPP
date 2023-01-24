#ifndef commanize_object_h
#define commanize_object_h
#include <iostream>
#include <string>

namespace alex_utility{
	class Commanize {
	public:
		// constructor
		Commanize();
		Commanize(int);
		Commanize(double, int d = 2);
		// destructor
		~Commanize();
	private:
		// helper for copying source
		inline void _copySource(const Commanize& source){
			precision = source.precision;
			s = source.s;
		};
	public:
		// copy constructor
		Commanize(const Commanize& source){
			_copySource(source);
		};
		// copy assignment operator
		Commanize& operator=(const Commanize&);
		// equal operator
		int operator==(const Commanize&);
		// member function
		std::string str(){return s;};
		std::string to_string(int);
		std::string to_string(double, int d=2);
	private:
		// member data
		int precision;
		std::string s;
		// member function
		void commanize_helper(int);
		void convertInt(int);
		void convertDouble(double);
		// << operator
		friend std::ostream& operator<<(std::ostream&, const Commanize&);
	};
}

#endif
