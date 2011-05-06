#include "StdAfx.h"
#include "Product.h"
#include <iostream>
#include <string>

using namespace std;


Product::Product(void): calories(0), price(0), servingTime(0)
{
	this->client = "Client";
	std::cout << "Constructor of product" << std::endl;
}


Product::Product(int calories, int price, int servingTime):
	calories(calories), price(price), servingTime(servingTime)
{
	this->client = "Destytojas";
	std::cout << "Constructor of product" << std::endl;
}


Product::~Product(void)
{
	std::cout << "destructor of product" << std::endl;
}


int Product::getCalories()
{
	return Product::calories;
}


int Product::getPrice()
{
	return Product::price;
}


int Product::getServingTime()
{
	return Product::servingTime;
}


void Product::printType()
{
	std::cout << " " << typeid(*this).name();
}


void Product::showInfo()
{
	cout << endl << "Information about the dish: " << endl
		<< "  Calories: " << this->getCalories() << endl
		<< "  Price: " << this->getPrice() << endl
		<< "  Time to serve: " << this->getServingTime() << endl << endl;
}

// returns client
char* Product::getClient()
{
	return this->client;
}


void Product::setClient(char* client)
{
	this->client = client;
}