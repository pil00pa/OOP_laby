#ifndef USER_H
#define USER_H

#include "Product.h"
#include <list>
using namespace std;

enum SocialGroup { Lower = 0, Middle = 1, Upper = 2, Undefined = 3 };

class User
{
protected:
	string _name;
	int _mobilePhone;
	list<Product> _shoppingList;
public:
	User();
	User(string name, int mobilePhone);
	User(string name, int mobilePhone, list<Product> shoppingList);
	User(string filepath);

	virtual SocialGroup getGroup();
	User& setName(string name);
	string getName() const;
	User& setPhone(int phone);
	int getPhone() const;
	User& addItemToList(Product item);
	list<Product> getShoppingList() const;
	void print() const;
};

class LowerClass : public User
{
public:
	LowerClass(const User& u)
	{
		_name = u.getName();
		_mobilePhone = u.getPhone();
		_shoppingList = u.getShoppingList();
	}
	SocialGroup getGroup() { return Lower; }
};

class MiddleClass : public User
{
public:
	MiddleClass(const User& u)
	{
		_name = u.getName();
		_mobilePhone = u.getPhone();
		_shoppingList = u.getShoppingList();
	}
	SocialGroup getGroup() { return Middle; }
};

class UpperClass : public User
{
public:
	UpperClass(const User& u)
	{
		_name = u.getName();
		_mobilePhone = u.getPhone();
		_shoppingList = u.getShoppingList();
	}
	SocialGroup getGroup() { return Upper; }
};

#endif