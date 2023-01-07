#ifndef SYSTEM_H
#define SYSTEM_H

#include "Product.h"
#include "User.h"
#include <vector>
#include <unordered_map>


class System
{
public:
	unordered_map<int, Product> _Market;
	unordered_map<int, User*> _UserBase;

	SocialGroup findUserGroup(User u);
public:
	System();
	System(string MarketPath, vector<string> UserBasePath);

	System& addProduct(const Product p);

	Product& getProductById(int id);
	User& getUserByPhone(int phone);
	System& addUser(const User u);

	vector<User> getLowerClass() const;
	vector<User> getMiddleClass() const;
	vector<User> getUpperClass() const;

	vector<Product> getPopularProductForLower() const;
	vector<Product> getPopularProductForMiddle() const;
	vector<Product> getPopularProductForUpper() const;


	vector<Product> getProductsByPopularity() const;
	void getSocialGroups() const;

	~System();
};

#endif