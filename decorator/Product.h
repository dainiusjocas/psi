#pragma once
class Product
{
private:
	int calories;
	int price;
	int servingTime;
	char* client;

public:
	Product(void);
	Product(int calories, int price, int servingTime);
	virtual int getCalories();
	virtual int getPrice();
	virtual int getServingTime();
	virtual void printType();
	virtual void showInfo();
	virtual ~Product(void);
	virtual char* getClient();
	virtual void setClient(char*);
};

