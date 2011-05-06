#include "StdAfx.h"
#include "Butter.h"
#include "SandwichPad.h"
#include <typeinfo>
#include <string>
#include <iostream>


Butter::Butter(void): Ingredient(NULL,
	Butter::CALORIES_OF_PORTION_OF_BUTTER,
	Butter::PRICE_OF_PORTION_OF_BUTTER,
	Butter::TIME_TO_PREPARE_A_PORTION_OF_BUTTER)
{
	this->condition = 0;
	std::cout << "Constructor of butter" << std::endl;
}


Butter::Butter(Product* product): Ingredient(product,
	Butter::CALORIES_OF_PORTION_OF_BUTTER,
	Butter::PRICE_OF_PORTION_OF_BUTTER,
	Butter::TIME_TO_PREPARE_A_PORTION_OF_BUTTER)
{
	this->condition = 0;
	std::cout << "Constructor of butter" << std::endl;
}

/*
	This method sets the parameter which describes in which condition butter
	should be. It should be spreaded if the root product is sandwich pad.
	Otherwise it should be melted.
*/
void Butter::setCondition()
{
	Product* mainProduct = Ingredient::getBaseProduct(this);
	SandwichPad* rootProduct = dynamic_cast<SandwichPad*>(mainProduct);
	if (NULL != rootProduct)
	{
		this->condition = 1;
	}
	else
	{
		this->condition = 2;
	}
}

char* Butter::getCondition()
{
	if (1 == this->condition)
	{ 
		return "spreaded";
	}
	else if (2 == this->condition)
	{
		return "melted";
	}
	return "Undefined condition";
}

Butter::~Butter(void)
{
	std::cout << "Destructor of butter" << std::endl;
}
