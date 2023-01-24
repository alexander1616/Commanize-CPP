#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <math.h>
using namespace std;

namespace alex_utility{
static void commanize_helper(int n, string& s){
    if (n < 1000){
        s.append(std::to_string(n));
    } else {
        commanize_helper(n/1000, s);
        char buf[100];
        sprintf(buf, ",%03d", n%1000);
        s.append(buf);
    }
}

string commanize(int n){
    string zzz;
    if (n < 0){
        zzz.append("-");
        n = -n;
    }
    commanize_helper(n, zzz);
    return zzz;
}

string commanize(double n, int after_d = 4){
    string zzz;
    if (n < 0){
        zzz.append("-");
        n = -n;
    }
    int o = n;
    commanize_helper(o, zzz);
    if (after_d > 0){
    zzz.append(".");
    double p = n - o;
    double q = p * pow(10, after_d);
	int r = q;
    char buf[100];
    //char fmt[100];
    //sprintf(fmt, "%%0%dd", after_d);
    //sprintf(buf, fmt, r);
    sprintf(buf, "%.*d", after_d, r);
    zzz.append(buf);
    };

    return zzz;
}
}
