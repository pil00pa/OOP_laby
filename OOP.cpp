#include <iostream>
#include <list>
#include "User.h"
#include "System.h"
#include "Product.h"

using namespace std;

int main()
{
	Product p("govno", 144, 15.55, 0.5, forLower);
	list<Product> pro; pro.push_back(p);
	
	User u("xyi", 332, pro);

	System s;

	
	s.addUser(u);


	for (int i = 0; i < 100; i++)
	{
		s.addUser(User("penis", i, pro));
	}

	
	cout <<(s._UserBase.find(55))->second->getPhone();
	cout << s.getUserByPhone(33).getPhone();
}