#include <iostream>
#include <list>

#include <vector>

#include "User.h"
#include "System.h"
#include "Product.h"
#include "Data.cpp"

using namespace std;
int Data::objectCount = 0;

int main()
{
	System s;
	for (int i = 0; i < 100; i++)
	{
		Product p("govno", i + 100, 123, 22, forLower);
		s.addProduct(p);
	}

	cout << s.getPopularProductForMiddle().size();

	
}