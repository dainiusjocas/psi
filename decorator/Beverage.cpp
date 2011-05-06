#include "StdAfx.h"
#include "Beverage.h"
#include <iostream>

/*
	Constructor
*/
Beverage::Beverage(void)
{
	std::cout << "Constructor of beverage" << std::endl;
}

/*
	Destructor
*/	
Beverage::~Beverage(void)
{
	std::cout << "Destructor of beverage" << std::endl;
}
