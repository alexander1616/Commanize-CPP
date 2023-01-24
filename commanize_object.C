#include <iostream>
#include <cstdio>
#include <string>
#include <math.h>
using namespace std;
#include "commanize_object.h"

namespace alex_utility{
// constructor
Commanize::Commanize(){
	precision = 0;
};

Commanize::Commanize(int value){
	precision = 0;
	convertInt(value);
};

Commanize::Commanize(double value, int d){
	precision = d;
	convertDouble(value);
};
// destructor
Commanize::~Commanize(){
	;
};

#if 0 //inline copySource and copy constructor on h file
void Commanize::_copySource(const Commanize& source){
	precision = source.precision;
	s = source.s;
};

// copy constructor
Commanize::Commanize(const Commanize& source){
	_copySource(source);
};

#endif
// copy assignment operator
Commanize& Commanize::operator=(const Commanize& source){
	_copySource(source);
	return *this;	
};

// equal operator
int Commanize::operator==(const Commanize& source){
	if ((precision == source.precision)&&(s == source.s)){
		return 1;
	} else {
		return 0;
	};
};

// member functions
void Commanize::commanize_helper(int n){
    if (n < 1000){
        s.append(std::to_string(n));
    } else {
        commanize_helper(n/1000);
        char buf[100];
        sprintf(buf, ",%03d", n%1000);
        s.append(buf);
    }
}

std::string Commanize::to_string(int g){
	convertInt(g);
	return s;
};

std::string Commanize::to_string(double g, int d){
	precision = d;
	convertDouble(g);
	return s;
};

void Commanize::convertInt(int n){
	s.clear();
    if (n < 0){
        s.append("-");
        n = -n;
    }
    commanize_helper(n);
}

void Commanize::convertDouble(double n){
	s.clear();
	if (n < 0){
        s.append("-");
        n = -n;
    }
    int o = n;
    commanize_helper(o);
    if (precision > 0){
    	s.append(".");
    	double p = n - o;
    	double q = p * pow(10, precision);
		int r = q;
    	char buf[100];
    	sprintf(buf, "%.*d", precision, r);
    	s.append(buf);
    };
}

std::ostream& operator<<(std::ostream& os
						, const Commanize& source){
	os<<source.s;
	return os;	
};

}
