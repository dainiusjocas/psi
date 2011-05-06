#pragma once
#include "ingredient.h"
class Water :
	public Ingredient
{
private:
	static const int CALORIES_OF_PORTION_OF_WATER = 0;
	static const int PRICE_OF_PORTION_OF_WATER = 1;
	static const int TIME_TO_PREPARE_A_PORTION_OF_WATER = 1;
	bool boiled;
public:
	Water(void);
	Water(Product* product);
	virtual void boilWater();
	virtual void freezeWater();
	virtual int getTemperature();
	virtual ~Water(void);
};

