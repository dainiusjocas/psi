#include "StdAfx.h"
#include "Sugar.h"
#include <iostream>


Sugar::Sugar(void): Ingredient(NULL, 
	Sugar::CALORIES_OF_PORTION_OF_SUGAR,
	Sugar::PRICE_OF_PORTION_OF_SUGAR,
	Sugar::TIME_TO_PREPARE_A_PORTION_OF_SUGAR)
{
	std::cout << "Constructor of sugar" << std::endl;
}


Sugar::Sugar(Product* product): Ingredient(product, 
	Sugar::CALORIES_OF_PORTION_OF_SUGAR,
	Sugar::PRICE_OF_PORTION_OF_SUGAR,
	Sugar::TIME_TO_PREPARE_A_PORTION_OF_SUGAR)
{
	std::cout << "Constructor of sugar" << std::endl;
}


Sugar::~Sugar(void)
{
	std::cout << "destructor of sugar" << std::endl;
}
