#include "Product.h"

Product::Product(string name, float price, float discount)
{
	Name = name;
	Price = price;
	Discount = discount;
}

bool Product::isOnDiscount()
{
	return (Discount>0);
}

void Product::setName(string name)
{
	Name = name;
}

string Product::getName() const
{
	return Name;
}

void Product::setPrice(float price)
{
	Price = price;
}

float Product::getFixedPrice() const
{
	return Price;
}

void Product::setDiscount(float discount)
{
	Discount = discount;
}

float Product::getDiscount() const
{
	return Discount;
}

float Product::getRealPrice() const
{
	return Price*(1-Discount);
}
