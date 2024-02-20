#include <iostream>
#include "mathlib.h"

int main()
{
	std::cout << "Client linked with static library." << std::endl;
	auto product = MathLibrary::Arithmetic::Multiply(3, 7);
    std::cout << "result: " << product << std::endl;

	return 0;
}
