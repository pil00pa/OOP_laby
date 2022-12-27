#pragma once
#include "Product.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class User
{
private:
	string Name;
	int MobilePhone;
	vector <Product> ShoppingList;
public:
	User(string filepath);
	void SetName(string name);
	string GetName();
	void SetPhone(int phone);
	int GetPhone();
	void AddItemToList(Product item);
	void Print();
	
};

