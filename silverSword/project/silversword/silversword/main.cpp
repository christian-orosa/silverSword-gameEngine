#include<iostream>
#include "../../maths/include/vectorSpace.h"

int main()
{



	ss::specialMaths spMath;

	float theValue = 64.1f;
	float logValue = 4;
	float degreesValue = 180;

	spMath.squareRoot(theValue);
	spMath.log(logValue);
	spMath.degreesToRad(degreesValue);

	std::cout << spMath.squareRoot(theValue) << std::endl;
	std::cout << spMath.log(logValue) << std::endl;
	std::cout << spMath.degreesToRad(degreesValue) << std::endl;

	return 22;
}