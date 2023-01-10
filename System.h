#ifndef SYSTEM_H
#define SYSTEM_H

#include "Product.h"
#include "User.h"
#include <vector>
#include <unordered_map>


class System
{
private:
	unordered_map<int, Product> _Market;
	unordered_map<int, User*> _UserBase;

	SocialGroup findUserGroup(User u);
	void updateSystem();
public:
	System();
	System(string MarketPath, vector<string> UserBasePath);

	System& addProduct(const Product p);
	Product& getProductById(int id);
	User& getUserByPhone(int phone);
	System& addUser(const User u);

	vector<User> getLowerClass();
	vector<User> getMiddleClass();
	vector<User> getUpperClass();

	vector<pair<int, Product>> getPopularProductForLower();
	vector<pair<int, Product>> getPopularProductForMiddle();
	vector<pair<int, Product>> getPopularProductForUpper();

	void getSocialGroups() const;

	~System();
};

#endif