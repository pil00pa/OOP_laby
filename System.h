#ifndef SYSTEM_H
#define SYSTEM_H

#include "Product.h"
#include "User.h"
#include <list>
class System
{
private:
	vector <Product> Market;
	list <User> UserBase;
public:
	Product& GetProductByName(string name);
	User& GetUserByPhone(int phone);
	System(string MarketPath, vector<string> UserBasePath);
};

#endif