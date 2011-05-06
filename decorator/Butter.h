#pragma once
#include "ingredient.h"
class Butter :
	public Ingredient
{
private:
	static const int CALORIES_OF_PORTION_OF_BUTTER = 150;
	static const int PRICE_OF_PORTION_OF_BUTTER = 30;
	static const int TIME_TO_PREPARE_A_PORTION_OF_BUTTER = 5;
	int condition;
public:
	Butter(void);
	Butter(Product* product);
	virtual void setCondition();
	virtual char* getCondition();
	virtual ~Butter(void);
};

