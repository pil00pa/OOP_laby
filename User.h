#ifndef USER_H
#define USER_H

#include "Product.h"
#include <vector>

class User
{
private:
	string Name;
	int MobilePhone;
	vector<Product> ShoppingList;
public:
	User(string filepath);
	void SetName(string name);
	string GetName() const;
	void SetPhone(int phone);
	int GetPhone() const;
	void AddItemToList(Product item);
	void Print();
};

#endif