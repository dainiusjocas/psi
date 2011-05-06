// decorator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Product.h"
#include "Beverage.h"
#include "SandwichPad.h"
#include "Ingredient.h"
#include "Sugar.h"
#include "Butter.h"
#include "Meat.h"
#include "Water.h"
#include <typeinfo>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Product* sandwich = new Meat(new Butter(new SandwichPad()));
	cout << endl;
	sandwich->printType();
	sandwich->showInfo();
	cout << endl;

	Product* tempProduct = Ingredient::getRole(sandwich, "Butter");
	if (NULL != tempProduct)
	{
		cout << "Specific functionality: " << endl;
		Butter* butterFromSandwich = dynamic_cast<Butter*>(tempProduct);
		cout << "Butter condition before using: " << butterFromSandwich->getCondition() << endl;
		butterFromSandwich->setCondition();
		cout << "Butter condition after using: " << butterFromSandwich->getCondition() << endl;
	}
	else
	{
		cout << "There is no object of such type" << endl;
	}

	tempProduct = Ingredient::getRole(sandwich, "SandwichPad");
	if (NULL != tempProduct)
	{
		cout << endl << "Specific functionality: " << endl;
		SandwichPad* temp = dynamic_cast<SandwichPad*>(tempProduct);
		cout << temp->toast() << endl;
	}
	else
	{
		cout << "There is no object of such type" << endl;
	}
	std::cout << std::endl;
	if (NULL != sandwich)
	{
		sandwich->~Product();
	}
	return 0;
}

