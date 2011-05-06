#pragma once
#include "ingredient.h"
class Sugar :
	public Ingredient
{
private:
	static const int CALORIES_OF_PORTION_OF_SUGAR = 100;
	static const int PRICE_OF_PORTION_OF_SUGAR = 10;
	static const int TIME_TO_PREPARE_A_PORTION_OF_SUGAR = 1;
public:
	Sugar(void);
	Sugar(Product* product);
	virtual ~Sugar(void);
};

