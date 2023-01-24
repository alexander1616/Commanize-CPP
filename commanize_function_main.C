#include <iostream>
#include <cstdio>
#include <string>
#include "commanize_function.h"

int main(int ac, char* av[]){
    double n;
    int after_d = 4;
    printf("input number and precision: \n");
    scanf("%lg%d", &n, &after_d);
    std::string zzz = alex_utility::commanize(n, after_d);
    std::cout << "["<<zzz<<"]"<< '\n';
    return 0;
}


