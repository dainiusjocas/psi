#pragma once
#include "product.h"
class SandwichPad :
	public Product
{
private:
	bool toasted;
public:
	SandwichPad(void);
	virtual char* toast();
	virtual ~SandwichPad(void);
};

