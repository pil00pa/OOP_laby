#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <fstream>
using namespace std;

class Product
{
private:
	string Name;
	float Price, Discount;
public:
	Product(string name, float price, float discount);
	bool IsOnDiscount();
	void SetName(string name);
	string GetName() const;
	void SetPrice(float price);
	float GetFixedPrice() const;
	void SetDiscount(float discount);
	float GetDiscount() const;
	float GetRealPrice() const;
	friend std::ostream& operator << (std::ostream& os, const Product& cur) {
		float RealPrice = cur.Price * (1 - cur.Discount);
		os << cur.Name.c_str() << " Price " << cur.Price << " Discount " << cur.Discount <<" Price with discount " << RealPrice << "\n";
		return os;
	}
	bool operator < (const Product& other) {
		return (this->Price < other.Price);
	}
};

#endif