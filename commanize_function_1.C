#include <iostream>
#include <cstdio>
using namespace std;

void commanize(int n){
	int n2;
	if (n < 0){
		printf("-");
		commanize(-n);
		return;
	} else if (n < 1000){
		printf("%d",n);
		return;
	} else {
		n2 = n;
		n /= 1000;
		commanize(n);
		printf(",%03d", n2%1000);
	}
}


int main(int ac, char* av[]){
	
	int n;
	printf("input number: \n");
	scanf("%d", &n);
	commanize(n);
	printf("\n");

	return 0;
}

