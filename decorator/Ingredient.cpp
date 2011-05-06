#include "StdAfx.h"
#include "Ingredient.h"
#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;


Ingredient::Ingredient(Product* product): Product(0, 0, 0), product(product)
{
	std::cout << "Constructor of Ingredient" << std::endl;
}


Ingredient::Ingredient(Product* product, int calories, int price, int servingTime):
	Product(calories, price, servingTime), product(product) 
{
	std::cout << "Constructor of ingredient" << std::endl;
}

/*
	This method get product attribute of the object.
*/
Product* Ingredient::getProduct()
{
	return this->product;
}


/*
	This method gets decorated object.
	Method return NULL if argument is not a decorator or there are no
	decorated object.
	In every other situation method return pointer of type Product to the
	decorated object.
*/
Product* Ingredient::getProduct(Product* topProduct)
{
	Ingredient* tempIngredient = dynamic_cast<Ingredient*>(topProduct);
	if (NULL != tempIngredient)
	{
		return tempIngredient->product;
	}
	return NULL;
}

/*
	This method gets root product of the product list
*/
Product* Ingredient::getBaseProduct(Product* product)
{
	Ingredient* tempIngredient = dynamic_cast<Ingredient*>(product);
	if (NULL == tempIngredient)
	{
		return product;
	}
	else
	{
		if (NULL == tempIngredient->product)
		{
			return tempIngredient;
		}
		else
		{
			return Ingredient::getBaseProduct(tempIngredient->product);
		}
	}
}

/*
	This method get total sum of calories of all the decorated objects.
	If there are no decorated objects, then amount of calories is only of
	base object.
*/
int Ingredient::getCalories()
{
	if (this->product != NULL)
	{
		return product->getCalories() + Product::getCalories();
	}
	return Product::getCalories();
}

/*
	This method get total price of all the decorated objects.
	If there are no decorated objects, then the price is only of
	base object.
*/
int Ingredient::getPrice()
{
	if (NULL != this->product)
	{
		return product->getPrice() + Product::getPrice();
	}
	return Product::getCalories();
}

/*
	This method get total serving time of all the decorated objects.
	If there are no decorated objects, then the price is only of
	base object.
*/
int Ingredient::getServingTime()
{
	if (NULL != this->product)
	{
		return product->getServingTime() + Product::getServingTime();
	}
	return Product::getServingTime();
}

/*
	Destructor. If there are any decorated objects then destructor for the
	decorated object is being called.
*/
Ingredient::~Ingredient(void)
{
	if (NULL != this->product)
	{
		this->product->~Product();
	}
	cout << "Destructor of ingredient" << endl;
}

/*
	This method sets an objest that should be decorated.
	If there already has been such an object that it will be destroyed
	and new object will be set.
*/
void Ingredient::setProduct(Product* product)
{
	if (NULL != this->product)
	{
		this->product->~Product();
		this->product = product;
	}
	else
	{
		this->product = product;
	}
}

void Ingredient::setProduct(Product* listOfProduct, Product* newProduct)
{
	Ingredient* tempIngredient = dynamic_cast<Ingredient*>(listOfProduct);
	if (NULL != tempIngredient)
	{
		if (NULL != tempIngredient)
		{
			tempIngredient->product->~Product();
		}
		tempIngredient->product = newProduct;
	}
}


/*
	This method prints the class name of the current object and if it contains
	product, then recursively printType method is being executed on product;
*/
void Ingredient::printType()
{
	std::cout << typeid(*this).name() << " ";
	if (this->product != NULL)
	{
		this->product->printType();
	}
}

void Ingredient::showAllProducts()
{
	cout << "List of all the products is: " << endl;
	this->printType();
	cout << endl;
}

Product* Ingredient::getRole(Product* product, char* nameOfProduct)
{
	string className(typeid(*product).name());
	string searchName(nameOfProduct);
	size_t found;
	found = className.find(searchName);
	if (found != string::npos)
	{
		return product;
	}
	else
	{
		Ingredient* temp = dynamic_cast<Ingredient*>(product);
		if (NULL != temp)
		{
			if (NULL != temp->product)
			{
				return Ingredient::getRole(temp->product, nameOfProduct);
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			return NULL;
		}
	}
}

/*
	This method tries to remove ingredient from the ingredient list. If class
	name contains parameter, then method return product of this object.
	Otherwise recursive call is being made for the attribute "product".
	is substring.
	NOTE: client takes a risk if in the decorators chain there is only one
	product, and that product is about to remove. Then method returns NULL.
*/
Product* Ingredient::removeRole(Product* product, char* nameOfProduct)
{
	string className(typeid(*product).name());
	string searchName(nameOfProduct);
	size_t found;
	found = className.find(searchName);
	Ingredient* ingredient = dynamic_cast<Ingredient*>(product);
	if (found != string::npos) // matches
	{
		if (NULL != ingredient) // good casting
		{
			Product* temp = ingredient->getProduct();
			ingredient->product = NULL;
			ingredient->~Ingredient();
			return temp;
		}
		else
		{
			product->~Product();
			return NULL;
		}
		//priskirt temp uznulint sunaikint ir grazint gera
	}
	if (NULL != ingredient) // good casting
	{
		if (NULL != ingredient->product) // contains a product
		{
			ingredient->product = Ingredient::removeRole(ingredient->product, nameOfProduct);
			return ingredient;
		}
		else
		{
			return product;
		}
	}
	return product;
}

char* Ingredient::getClient()
{
	return this->product->getClient();
}

void Ingredient::setClient(char* client)
{
	this->product->setClient(client);
}