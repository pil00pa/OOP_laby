#include "Product.h"

Product::Product() : _name(""), _id(0), _price(0), _discount(0), _сategory(forAll)
{}

Product::Product(string name, int id, float price, float discount, Category category) :
	_name(name), _id(id), _price(price), _discount(discount), _сategory(category)
	{}

Product& Product::setName(string name)
{
	_name = name;
	return *this;
}

string Product::getName() const
{
	return _name;
}

Product& Product::setId(int id)
{
	_id = id;
	return *this;
}

int Product::getId() const
{
	return _id;
}

Product& Product::setCategory(const Category c)
{
	_сategory = c;
	return *this;
}

Category Product::getCategory() const
{
	return _сategory;
}

Product& Product::setPrice(float price)
{
	_price = price;
	return *this;
}

float Product::getFixedPrice() const
{
	return _price;
}

Product& Product::setDiscount(float discount)
{
	_discount = discount;
	return *this;
}

float Product::getDiscount() const
{
	return _discount;
}

bool Product::operator<(const Product& other) const
{
	return (this->_price < other._price);
}

float Product::getRealPrice() const
{
	return _price*(1-_discount);
}