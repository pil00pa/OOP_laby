#ifndef SYSTEM_H
#define SYSTEM_H

#include "Product.h"
#include "User.h"
#include <list>
#include <vector>
class System
{
private:
	vector <Product> Market;
	list <User> UserBase;
public:
	Product& getProductByName(string name);
	User& getUserByPhone(int phone);
	System(string MarketPath, vector<string> UserBasePath);
};

#endif