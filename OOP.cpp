#include <iostream>
#include <list>
#include "User.h"
#include "System.h"
#include "Product.h"
#include "Data.cpp"

using namespace std;
int Data::objectCount = 0;

int main()
{
	Product p("Coca Cola light", 144, 15.55, 0.5, forLower);
	list<Product> pro; pro.push_back(p);
	
	User u("Mishania", 332, pro);
	User u2("Data.csv");
	cout << u[0];
	System s;

	
	s.addUser(u);


	for (int i = 0; i < 100; i++)
	{
		s.addUser(User("penis", i, pro));
	}

	
	cout <<(s._UserBase.find(55))->second->getPhone();
	cout << s.getUserByPhone(33).getPhone();

	cout << "\nData demo\n";
	Data data;
	cout << data;
	Data data2(28, 2, 2004);
	cout << data2;
	++data2;
	cout << data2;
	cout << "Static member demo\n";
	cout << data.objectCount << "\n";
	cout << data.objectCount << "\n";
}