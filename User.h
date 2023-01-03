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

	void SetName(string name);
	string GetName() const;
	void SetPhone(int phone);
	int GetPhone() const;
	void AddItemToList(Product item);
	void Print();
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