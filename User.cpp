#include "User.h"
#include "Product.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

User::User(string filepath)
{
	ifstream InputFile;
	InputFile.open(filepath);
	string line = "";
	
	string buffer = "";
	getline(InputFile, line);
	stringstream inputString(line);
	// initialsing mane and phone
	getline(inputString, Name, ',');
	getline(inputString, buffer, ',');
	MobilePhone = atoi(buffer.c_str());
	getline(inputString, buffer, ',');
	buffer = "";
	inputString.clear();
	// Shopping list
	while (getline(InputFile,line))
	{
		stringstream inputString(line);
		string name;
		float price;
		float discount;
		buffer = "";

		getline(inputString, name, ',');

		getline(inputString, buffer, ',');
		price = atof(buffer.c_str());
		buffer = "";

		getline(inputString, buffer, ',');
		discount = atof(buffer.c_str());
		buffer = "";

		Product TempProduct(name, price, discount);
		ShoppingList.push_back(TempProduct);
		line = "";
	}
	InputFile.close();
	sort(ShoppingList.begin(), ShoppingList.end());
}

void User::setName(string name)
{
	Name = name;
}

string User::getName() const
{
	return Name;
}

void User::setPhone(int phone)
{
	MobilePhone = phone;
}

int User::getPhone() const
{
	return MobilePhone;
}

void User::addItemToList(Product item)
{
	ShoppingList.push_back(item);
}

void User::print()
{
	cout << Name<<"\n";
	cout << MobilePhone << "\n";
	for (auto i =ShoppingList.begin(); i != ShoppingList.end(); i++) {
		cout << *i;
	}
}