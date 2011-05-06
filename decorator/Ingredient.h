#pragma once
#include "product.h"

class Ingredient :
	public Product
{
private:
	Product* product;
public:
	Ingredient(Product* product);
	Ingredient(Product* product, int calories, int price, int servingTime);
	static Product* getBaseProduct(Product* product);
	static Product* getRole(Product* product, char* nameOfProduct);
	static Product* removeRole(Product* product, char* nameOfProduct);
	static Product* getProduct(Product* topProduct);
	virtual Product* getProduct();
	static void setProduct(Product* listOfProduct, Product* newProduct);
	virtual void setProduct(Product* product);
	virtual int getCalories();
	virtual int getPrice();
	virtual int getServingTime();
	virtual void showAllProducts();
	virtual void printType();
	virtual ~Ingredient(void);
	virtual char* getClient();
	virtual void setClient(char* client);
};

