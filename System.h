#pragma once
#include "Proposal.h"
class System
{
private:
	vector <Product> Market;
	vector <User> UserBase;
public:
	Product& GetProductByName(string name);
	User& GetUserByPhone(int phone);
	System(string MarketPath, vector<string> UserBasePath);
};

