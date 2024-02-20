#include <iostream>
#include "mathlib.h"

int main()
{
	std::cout << "Client linked with shared library" << std::endl;
	auto sum = MathLibrary::Arithmetic::Add(3, 7);
	std::cout << "result: " << sum << std::endl;

	return 0;
}
