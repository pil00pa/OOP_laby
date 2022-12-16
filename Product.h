#pragma once
#include <string>
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

};

