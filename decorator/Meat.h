#pragma once
#include "ingredient.h"
class Meat :
	public Ingredient
{
private:
	static const int CALORIES_OF_PORTION_OF_MEAT = 250;
	static const int PRICE_OF_PORTION_OF_MEAT = 100;
	static const int TIME_TO_PREPARE_A_PORTION_OF_MEAT = 10;
public:
	Meat(void);
	Meat(Product* product);
	virtual ~Meat(void);
};

