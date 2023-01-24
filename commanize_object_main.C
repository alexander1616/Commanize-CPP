#include <iostream>
#include <cstdio>
#include <string>
#include "commanize_object.h"

int main(int ac, char* av[]){

	double n;
    int precision = 2;
    printf("input number and precision: \n");
    scanf("%lg%d", &n, &precision);
	alex_utility::Commanize Tiger(n, precision);
    std::cout << "Tiger ["<<Tiger.str()<<"]"<< '\n';

	alex_utility::Commanize Toby;
	std::string tobys = Toby.to_string((int)n);
    std::cout << "Toby ["<<tobys<<"]"<< '\n';

	std::string tigers = Tiger.to_string(n, precision);
    std::cout << "Tiger ["<<tigers<<"]"<< '\n';
// New Code	
	alex_utility::Commanize Godzilla(Tiger);
    std::cout << "Godzilla ["<<Godzilla.str()<<"]"<< '\n';
	Godzilla = Toby;
    std::cout << "Godzilla ["<<Godzilla.str()<<"]"<< '\n';
	if (Godzilla == Toby){
		std::cout << "Godzilla is equal to Toby\n";
	} else {
		std::cout << "Godzilla is not equal to Toby\n";
	};	
	if (Godzilla == Tiger){
		std::cout << "Godzilla is equal to Tiger\n";
	} else {
		std::cout << "Godzilla is not equal to Tiger\n";
	};	
	std::cout << "Godzilla {" << Godzilla <<"}"<<'\n';
	
    return 0;
}


