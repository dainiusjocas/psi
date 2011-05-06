#include "StdAfx.h"
#include "SandwichPad.h"
#include <iostream>


SandwichPad::SandwichPad(void): Product(100, 50, 5)
{
	toasted = false;
	std::cout << "Constructor of SandwichPad" << std::endl;
}

char* SandwichPad::toast()
{
	toasted = true;
	return "Sandwich pad now is toasted";
}

SandwichPad::~SandwichPad(void)
{
	std::cout << "Destructor of SandwichPad" << std::endl;
}
