#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <fstream>
#include <sstream>
using namespace std;

enum Category { forLower, forMiddle, forUpper, forAll };

class Product
{
private:
	string _name;
	int _id;
	float _price, _discount;
	Category _сategory;
public:
	Product();
	Product(string name, int id, float price, float discount, Category category);
	Product& setName(string name);
	string getName() const;

	Product& setId(int id);
	int getId() const;

	Product& setCategory(const Category c);
	Category getCategory() const;

	Product& setPrice(float price);
	float getFixedPrice() const;
	float getRealPrice() const;

	Product& setDiscount(float discount);
	float getDiscount() const;

	friend std::ostream& operator << (std::ostream& os, const Product& cur) {
		float RealPrice = cur._price * (1 - cur._discount);
		os << cur._name.c_str() << " _price " << cur._price << " _discount " << cur._discount <<" _price with discount " << RealPrice << "\n";
		return os;
	}

	bool operator < (const Product& other) const;
};

#endif