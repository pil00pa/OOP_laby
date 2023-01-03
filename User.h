#ifndef USER_H
#define USER_H

#include "Product.h"
#include <list>
using namespace std;

class User
{
private:
	string Name;
	int MobilePhone;
	list<Product> ShoppingList;
public:
	virtual SocialGroup GetCategory() = 0;

	User(string filepath);

	void setName(string name);
	string getName() const;
	void setPhone(int phone);
	int getPhone() const;
	void addItemToList(Product item);
	void print();
};

enum SocialGroup { Lower, Middle, Upper };

class LowerClass : public User
{
	SocialGroup GetCategory() { return Lower; }
};

class MiddleClass : public User
{
	SocialGroup GetCategory() { return Middle; }
};

class UpperClass : public User
{
	SocialGroup GetCategory() { return Upper; }
};

#endif