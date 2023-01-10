#include "User.h"
#include "Product.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

User::User() : _name(""), _mobilePhone(0)
{
	//objectCount++;
}

User::User(string name, int mobilePhone) :
	_name(name), _mobilePhone(mobilePhone)
{
}

User::User(string name, int mobilePhone, list<Product> shoppingList) :
	_name(name), _mobilePhone(mobilePhone), _shoppingList(shoppingList)
{
}

User::User(string filepath)
{
	ifstream InputFile;
	InputFile.open(filepath);
	string line = "";

	string buffer = "";
	getline(InputFile, line);
	stringstream inputString(line);
	// initialsing name and phone
	getline(inputString, _name, ',');
	getline(inputString, buffer, ',');
	_mobilePhone = atoi(buffer.c_str());
	getline(inputString, buffer, ',');
	buffer = "";
	inputString.clear();
	// Shopping list
	while (getline(InputFile, line))
	{
		stringstream inputString(line);
		string name;
		int id;
		float price;
		float discount;
		Category category;

		buffer = "";

		// name
		getline(inputString, name, ',');
		// id
		getline(inputString, buffer, ',');
		id = atoi(buffer.c_str());
		buffer = "";
		// price
		getline(inputString, buffer, ',');
		price = atof(buffer.c_str());
		buffer = "";
		// discount
		getline(inputString, buffer, ',');
		discount = atof(buffer.c_str());
		buffer = "";
		// category
		getline(inputString, buffer, ',');
		category = Category(atoi(buffer.c_str()));
		buffer = "";

		Product TempProduct(name, id, price, discount, category);
		_shoppingList.push_back(TempProduct);
		line = "";
	}
	InputFile.close();
	// sort(_shoppingList.begin(), _shoppingList.end());
}


SocialGroup User::getGroup() { return Undefined; }


User& User::setName(string name)
{
	_name = name;
	return *this;
}

string User::getName() const
{
	return _name;
}

User& User::setPhone(int phone)
{
	_mobilePhone = phone;
	return *this;
}

int User::getPhone() const
{
	return _mobilePhone;
}

User& User::addItemToList(Product item)
{
	_shoppingList.push_back(item);
	return *this;
}

list<Product> User::getShoppingList() const
{
	return _shoppingList;
}

int User::getSizeOfShoppingList() const
{
	return _shoppingList.size();
}


void User::print() const
{
	cout << _name << "\n";
	cout << _mobilePhone << "\n";
	for (auto i = _shoppingList.begin(); i != _shoppingList.end(); i++) {
		cout << *i << endl;
	}
}