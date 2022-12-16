#include "Product.h"

Product::Product(string name, float price, float discount)
{
	Name = name;
	Price = price;
	Discount = discount;
}

bool Product::IsOnDiscount()
{
	return (Discount>0);
}

void Product::SetName(string name)
{
	Name = name;
}

string Product::GetName()
{
	return Name;
}

void Product::SetPrice(float price)
{
	Price = price;
}

float Product::GetFixedPrice()
{
	return Price;
}

void Product::SetDiscount(float discount)
{
	Discount = discount;
}

float Product::GetDiscount()
{
	return Discount;
}

float Product::GetRealPrice()
{
	return Price*(1-Discount);
}
