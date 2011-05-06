#include "StdAfx.h"
#include "Water.h"
#include <iostream>


Water::Water(void): Ingredient(NULL,
	Water::CALORIES_OF_PORTION_OF_WATER,
	Water::PRICE_OF_PORTION_OF_WATER,
	Water::TIME_TO_PREPARE_A_PORTION_OF_WATER)
{
	Water::boiled = false;
	std::cout << "Constructor of water" << std::endl;
}


Water::Water(Product* product): Ingredient(product,
	Water::CALORIES_OF_PORTION_OF_WATER,
	Water::PRICE_OF_PORTION_OF_WATER,
	Water::TIME_TO_PREPARE_A_PORTION_OF_WATER)
{
	Water::boiled = false;
	std::cout << "Constructor of water" << std::endl;
}

void Water::boilWater()
{
	Water::boiled = true;
}


void Water::freezeWater()
{
	Water::boiled = false;
}

Water::~Water(void)
{
	std::cout << "Destructor of water" << std::endl;
}

int Water::getTemperature()
{
	if (this->boiled)
	{
		return 100;
	}
	else
	{
		return 20;
	}
}
