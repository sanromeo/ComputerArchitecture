#include "calculator.h"
#include "iostream"

int main()
{
	double a = 69;
	double b = 17;
	
	int resultAdd, resultSub;
	
	resultAdd = Add(a, b);
	resultSub = Sub(a, b);
	
	std::cout << resultAdd << std::endl;
	std::cout << resultSub << std::endl;
	
	return 0;
}
