#pragma once
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
	string GetName();
	void SetPrice(float price);
	float GetFixedPrice();
	void SetDiscount(float discount);
	float GetDiscount();
	float GetRealPrice();
	friend std::ostream& operator << (std::ostream& os, const Product& cur) {
		float RealPrice = cur.Price * (1 - cur.Discount);
		os << cur.Name.c_str() << " Price " << cur.Price << " Discount " << cur.Discount <<" Price with discount " << RealPrice << "\n";
		return os;
	}
};

