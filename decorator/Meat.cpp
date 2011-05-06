#include "StdAfx.h"
#include "Meat.h"
#include <iostream>


Meat::Meat(void): Ingredient(NULL,
	Meat::CALORIES_OF_PORTION_OF_MEAT,
	Meat::PRICE_OF_PORTION_OF_MEAT,
	Meat::TIME_TO_PREPARE_A_PORTION_OF_MEAT)
{
	std::cout << "Constructor of meat" << std::endl;
}


Meat::Meat(Product* product): Ingredient(product,
	Meat::CALORIES_OF_PORTION_OF_MEAT,
	Meat::PRICE_OF_PORTION_OF_MEAT,
	Meat::TIME_TO_PREPARE_A_PORTION_OF_MEAT)
{
	std::cout << "Constructor of meat" << std::endl;
}


Meat::~Meat(void)
{
	std::cout << "Destructor of meat" << std::endl;
}
